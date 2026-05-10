import os
import sys
import numpy as np

from adaboost import AdaBoost
from data_utils import load_csv_data, k_fold_indices, resolve_output_dir, resolve_target_path, standardize_train_test
from learners import DecisionStump, LogisticRegression


def get_base_config(base_learner_id):
    if base_learner_id == 0:
        return DecisionStump, {}
    return LogisticRegression, {
        "lr": 0.1,
        "n_iter": 200,
        "reg_lambda": 1e-4,
        "tol": 1e-6,
        "lr_decay": 0.02,
        "patience": 10,
    }


def run_cross_validation(x, y, decode_map, base_learner_id, output_dir):
    t_list = [1, 5, 10, 100]
    folds = k_fold_indices(y, k=10, seed=42, shuffle=True)
    acc_map = {t: [] for t in t_list}

    all_indices = np.arange(len(y))
    base_cls, base_kwargs = get_base_config(base_learner_id)

    for fold_id, test_idx in enumerate(folds, start=1):
        train_mask = np.ones(len(y), dtype=bool)
        train_mask[test_idx] = False
        train_idx = all_indices[train_mask]

        x_train = x[train_idx]
        y_train = y[train_idx]
        x_test = x[test_idx]
        y_test = y[test_idx]

        if base_learner_id == 1:
            x_train, x_test = standardize_train_test(x_train, x_test)

        model = AdaBoost(base_cls, n_estimators=max(
            t_list), base_kwargs=base_kwargs)
        model.fit(x_train, y_train)

        for t in t_list:
            pred = model.predict(x_test, num_estimators=t)
            out_labels = np.where(
                pred == 1, decode_map[1], decode_map[-1]).astype(int)
            output = np.column_stack((test_idx + 1, out_labels))
            out_path = os.path.join(
                output_dir, "base%d_fold%d.csv" % (t, fold_id))
            np.savetxt(out_path, output, fmt="%d,%d")
            acc_map[t].append(float(np.mean(pred == y_test)))

    return acc_map


def main(argv):
    if len(argv) < 4:
        print("Usage: python main.py data.csv target.csv 0")
        return 1

    data_path = argv[1]
    target_path = resolve_target_path(argv[2])

    if not os.path.exists(data_path):
        raise FileNotFoundError("Data file not found: %s" % data_path)

    try:
        base_learner_id = int(argv[3])
    except ValueError as exc:
        raise ValueError("Base learner id must be 0 or 1") from exc

    if base_learner_id not in (0, 1):
        raise ValueError("Base learner id must be 0 (stump) or 1 (logistic)")

    output_dir = resolve_output_dir(data_path)
    x, y, decode_map = load_csv_data(data_path, target_path)
    acc_map = run_cross_validation(
        x, y, decode_map, base_learner_id, output_dir)

    print("Done. Saved predictions to %s" % output_dir)
    for t in [1, 5, 10, 100]:
        print("Accuracy T=%d: %.6f" % (t, float(np.mean(acc_map[t]))))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
