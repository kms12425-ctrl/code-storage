import numpy as np


class DecisionStump:
    def __init__(self):
        self.feature_index = None
        self.threshold = None
        self.polarity = 1

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

            change_idx = np.where(sorted_x[1:] != sorted_x[:-1])[0]
            candidate_idx = np.concatenate([change_idx, [n_samples - 1]])
            thresholds = sorted_x[candidate_idx]

            error_pos = cum_neg[candidate_idx] + \
                (total_pos - cum_pos[candidate_idx])
            error_neg = cum_pos[candidate_idx] + \
                (total_neg - cum_neg[candidate_idx])

            min_pos_idx = int(np.argmin(error_pos))
            min_neg_idx = int(np.argmin(error_neg))

            if error_pos[min_pos_idx] < error_neg[min_neg_idx]:
                error = error_pos[min_pos_idx]
                threshold = thresholds[min_pos_idx]
                polarity = 1
            else:
                error = error_neg[min_neg_idx]
                threshold = thresholds[min_neg_idx]
                polarity = -1

            if error < best_error:
                best_error = error
                best_feature = feature_idx
                best_threshold = threshold
                best_polarity = polarity

        self.feature_index = best_feature
        self.threshold = float(best_threshold)
        self.polarity = int(best_polarity)
        return self

    def predict(self, x):
        feature_values = x[:, self.feature_index]
        preds = np.ones(x.shape[0], dtype=int)
        if self.polarity == 1:
            preds[feature_values > self.threshold] = -1
        else:
            preds[feature_values <= self.threshold] = -1
        return preds


class LogisticRegression:
    def __init__(self, lr=0.1, n_iter=50, reg_lambda=1e-4, tol=1e-6):
        self.lr = lr
        self.n_iter = n_iter
        self.reg_lambda = reg_lambda
        self.tol = tol
        self.coef_ = None
        self.bias_ = 0.0

    def fit(self, x, y, sample_weight=None):
        n_samples, n_features = x.shape
        if sample_weight is None:
            sample_weight = np.ones(n_samples) / n_samples
        else:
            sample_weight = sample_weight / np.sum(sample_weight)

        x_ext = np.hstack([x, np.ones((n_samples, 1))])
        weights = np.zeros(n_features + 1)
        prev_loss = None

        for _ in range(self.n_iter):
            scores = x_ext @ weights
            yz = y * scores
            yz_clip = np.clip(yz, -50, 50)
            sigmoid = 1.0 / (1.0 + np.exp(yz_clip))

            grad = -(x_ext.T @ (sample_weight * y * sigmoid))
            grad[:-1] += self.reg_lambda * weights[:-1]

            weights -= self.lr * grad

            if self.tol is not None:
                loss = np.sum(sample_weight * np.log1p(np.exp(-yz_clip)))
                loss += 0.5 * self.reg_lambda * np.sum(weights[:-1] ** 2)
                if prev_loss is not None and (prev_loss - loss) < self.tol:
                    break
                prev_loss = loss

        self.coef_ = weights[:-1]
        self.bias_ = weights[-1]
        return self

    def predict(self, x):
        scores = x @ self.coef_ + self.bias_
        preds = np.sign(scores)
        preds[preds == 0] = 1
        return preds.astype(int)
