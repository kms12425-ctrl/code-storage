import numpy as np


class AdaBoost:
    def __init__(self, base_learner_cls, n_estimators=100, base_kwargs=None, eps=1e-10):
        self.base_learner_cls = base_learner_cls
        self.n_estimators = n_estimators
        self.base_kwargs = base_kwargs or {}
        self.eps = eps
        self.learners_ = []
        self.alphas_ = []

    def fit(self, x, y):
        n_samples = x.shape[0]
        weights = np.ones(n_samples) / n_samples

        self.learners_ = []
        self.alphas_ = []

        for _ in range(self.n_estimators):
            learner = self.base_learner_cls(**self.base_kwargs)
            learner.fit(x, y, weights)
            pred = learner.predict(x)

            miss = pred != y
            error = float(np.sum(weights[miss]))

            if error > 0.5:
                learner.invert()
                pred = -pred
                error = 1.0 - error

            if error >= 0.5 - self.eps:
                break

            error = np.clip(error, self.eps, 1.0 - self.eps)
            alpha = 0.5 * np.log((1.0 - error) / error)

            weights *= np.exp(-alpha * y * pred)
            weights_sum = np.sum(weights)
            if weights_sum <= 0:
                break
            weights /= weights_sum

            self.learners_.append(learner)
            self.alphas_.append(alpha)

            if error <= self.eps:
                break

        return self

    def predict(self, x, num_estimators=None):
        if not self.learners_:
            return np.ones(x.shape[0], dtype=int)

        if num_estimators is None:
            num_estimators = len(self.learners_)
        num_estimators = min(num_estimators, len(self.learners_))

        scores = np.zeros(x.shape[0])
        for alpha, learner in zip(self.alphas_[:num_estimators], self.learners_[:num_estimators]):
            scores += alpha * learner.predict(x)

        preds = np.sign(scores)
        preds[preds == 0] = 1
        return preds.astype(int)
