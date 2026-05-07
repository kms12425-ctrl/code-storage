import numpy as np


class DecisionStump:
    def __init__(self):
        self.feature_index = None
        self.threshold = None
        self.polarity = 1
        self.output_scale = 1

    def fit(self, x, y, sample_weight=None):
        n_samples, n_features = x.shape
        if sample_weight is None:
            sample_weight = np.ones(n_samples) / n_samples
        else:
            sample_weight = sample_weight / np.sum(sample_weight)

        best_error = np.inf
        best_feature = 0
        best_threshold = 0.0
        best_polarity = 1

        for feature_idx in range(n_features):
            feature_values = x[:, feature_idx]
            order = np.argsort(feature_values)
            sorted_x = feature_values[order]
            sorted_y = y[order]
            sorted_w = sample_weight[order]

            pos_mask = sorted_y == 1
            neg_mask = ~pos_mask

            cum_pos = np.cumsum(sorted_w * pos_mask)
            cum_neg = np.cumsum(sorted_w * neg_mask)
            total_pos = cum_pos[-1]
            total_neg = cum_neg[-1]

            unique_values = np.unique(sorted_x)
            if unique_values.size == 1:
                thresholds = np.array(
                    [np.nextafter(unique_values[0], -np.inf), np.nextafter(unique_values[0], np.inf)])
                error_pos = np.array([total_pos, total_neg])
                error_neg = np.array([total_neg, total_pos])
            else:
                change_idx = np.where(sorted_x[1:] != sorted_x[:-1])[0]
                midpoints = 0.5 * \
                    (sorted_x[change_idx] + sorted_x[change_idx + 1])
                left_edge = np.nextafter(sorted_x[0], -np.inf)
                right_edge = np.nextafter(sorted_x[-1], np.inf)

                thresholds = np.concatenate(
                    ([left_edge], midpoints, [right_edge]))
                error_pos = np.concatenate((
                    [total_pos],
                    cum_neg[change_idx] + (total_pos - cum_pos[change_idx]),
                    [total_neg],
                ))
                error_neg = np.concatenate((
                    [total_neg],
                    cum_pos[change_idx] + (total_neg - cum_neg[change_idx]),
                    [total_pos],
                ))

            min_pos_idx = int(np.argmin(error_pos))
            min_neg_idx = int(np.argmin(error_neg))

            if error_pos[min_pos_idx] <= error_neg[min_neg_idx]:
                error = float(error_pos[min_pos_idx])
                threshold = float(thresholds[min_pos_idx])
                polarity = 1
            else:
                error = float(error_neg[min_neg_idx])
                threshold = float(thresholds[min_neg_idx])
                polarity = -1

            if error < best_error:
                best_error = error
                best_feature = feature_idx
                best_threshold = threshold
                best_polarity = polarity

        self.feature_index = best_feature
        self.threshold = best_threshold
        self.polarity = best_polarity
        self.output_scale = 1
        return self

    def invert(self):
        self.output_scale *= -1

    def predict(self, x):
        feature_values = x[:, self.feature_index]
        preds = np.ones(x.shape[0], dtype=int)
        if self.polarity == 1:
            preds[feature_values > self.threshold] = -1
        else:
            preds[feature_values <= self.threshold] = -1
        return self.output_scale * preds


class LogisticRegression:
    def __init__(self, lr=0.1, n_iter=80, reg_lambda=5e-4, tol=1e-6, lr_decay=0.02, patience=5):
        self.lr = lr
        self.n_iter = n_iter
        self.reg_lambda = reg_lambda
        self.tol = tol
        self.lr_decay = lr_decay
        self.patience = patience
        self.coef_ = None
        self.bias_ = 0.0
        self.output_scale = 1

    def fit(self, x, y, sample_weight=None):
        n_samples, n_features = x.shape
        if sample_weight is None:
            sample_weight = np.ones(n_samples) / n_samples
        else:
            sample_weight = sample_weight / np.sum(sample_weight)

        x_ext = np.hstack([x, np.ones((n_samples, 1))])
        weights = np.zeros(n_features + 1)
        best_weights = weights.copy()
        best_loss = np.inf
        no_improve_rounds = 0

        for iteration in range(self.n_iter):
            scores = x_ext @ weights
            yz = y * scores
            yz_clip = np.clip(yz, -50, 50)
            inv_margin = 1.0 / (1.0 + np.exp(yz_clip))

            grad = -(x_ext.T @ (sample_weight * y * inv_margin))
            grad[:-1] += self.reg_lambda * weights[:-1]

            step_size = self.lr / (1.0 + self.lr_decay * iteration)
            weights -= step_size * grad

            stable_yz = np.clip(y * (x_ext @ weights), -50, 50)
            loss = np.sum(sample_weight * np.log1p(np.exp(-stable_yz)))
            loss += 0.5 * self.reg_lambda * np.sum(weights[:-1] ** 2)

            if loss + self.tol < best_loss:
                best_loss = loss
                best_weights = weights.copy()
                no_improve_rounds = 0
            else:
                no_improve_rounds += 1
                if no_improve_rounds >= self.patience:
                    break

        self.coef_ = best_weights[:-1]
        self.bias_ = best_weights[-1]
        self.output_scale = 1
        return self

    def invert(self):
        self.output_scale *= -1

    def predict(self, x):
        scores = x @ self.coef_ + self.bias_
        preds = np.sign(scores)
        preds[preds == 0] = 1
        return (self.output_scale * preds).astype(int)
