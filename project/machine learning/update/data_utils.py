import os
import numpy as np


def resolve_target_path(target_path):
    if os.path.exists(target_path):
        return target_path

    parent_dir = os.path.dirname(target_path)
    base_name = os.path.basename(target_path)
    candidates = []
    if base_name == "target.csv":
        candidates.append(os.path.join(parent_dir, "targets.csv"))
    elif base_name == "targets.csv":
        candidates.append(os.path.join(parent_dir, "target.csv"))

    for candidate in candidates:
        if os.path.exists(candidate):
            return candidate

    raise FileNotFoundError("Target file not found: %s" % target_path)


def encode_labels(y_raw):
    y_flat = np.asarray(y_raw).reshape(-1)
    unique = np.unique(y_flat)
    if unique.size != 2:
        raise ValueError(
            "Expected binary labels, got %d classes" % unique.size)

    unique_sorted = np.sort(unique)
    if set(unique.tolist()) == {-1, 1}:
        y_encoded = y_flat.astype(int)
        decode_map = {-1: -1, 1: 1}
        return y_encoded, decode_map

    if set(unique.tolist()) == {0, 1}:
        y_encoded = np.where(y_flat == 1, 1, -1)
        decode_map = {-1: 0, 1: 1}
        return y_encoded, decode_map

    low, high = unique_sorted[0], unique_sorted[1]
    y_encoded = np.where(y_flat == high, 1, -1)
    decode_map = {-1: int(low), 1: int(high)}
    return y_encoded, decode_map


def load_csv_data(data_path, target_path):
    x = np.genfromtxt(data_path, delimiter=",")
    y_raw = np.genfromtxt(target_path, delimiter=",")
    if y_raw.ndim > 1:
        y_raw = y_raw.squeeze()
    y, decode_map = encode_labels(y_raw)
    return x, y, decode_map


def k_fold_indices(y, k=10, seed=42, shuffle=True):
    y = np.asarray(y).reshape(-1)
    n_samples = y.shape[0]
    if k <= 1 or k > n_samples:
        raise ValueError("k must be in [2, n_samples]")

    rng = np.random.default_rng(seed)
    indices = np.arange(n_samples)
    folds = [[] for _ in range(k)]

    for label in np.unique(y):
        label_indices = indices[y == label].copy()
        if shuffle:
            rng.shuffle(label_indices)

        label_parts = np.array_split(label_indices, k)
        for fold_id, part in enumerate(label_parts):
            folds[fold_id].extend(part.tolist())

    finalized_folds = []
    for fold in folds:
        fold_array = np.array(fold, dtype=int)
        if shuffle:
            rng.shuffle(fold_array)
        finalized_folds.append(fold_array)
    return finalized_folds


def standardize_train_test(x_train, x_test):
    mean = x_train.mean(axis=0)
    std = x_train.std(axis=0)
    std[std == 0] = 1.0
    x_train_scaled = (x_train - mean) / std
    x_test_scaled = (x_test - mean) / std
    return x_train_scaled, x_test_scaled


def resolve_output_dir(data_path):
    data_dir = os.path.dirname(os.path.abspath(data_path))
    preferred_dir = os.path.join(data_dir, "experiments")
    cwd_dir = os.path.join(os.getcwd(), "experiments")

    if os.path.isdir(preferred_dir):
        return preferred_dir
    if os.path.isdir(cwd_dir):
        return cwd_dir

    raise FileNotFoundError(
        "Missing experiments directory. Tried: %s and %s" % (
            preferred_dir, cwd_dir)
    )
