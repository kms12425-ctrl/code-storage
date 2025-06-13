import numpy as np
import matplotlib.pyplot as plt
# 设置中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False


def find_half_power_points(f, U):
    """找到半功率点对应的频率f1和f2"""
    # 找到最大电压值及其索引
    Umax = np.max(U)
    Umax_idx = np.argmax(U)
    f0 = f[Umax_idx]  # 谐振频率

    # 计算半功率点电压值 (Umax/√2 ≈ 0.707 * Umax)
    U_half = Umax / np.sqrt(2)

    # 寻找左侧半功率点f1（小于f0的频率区域）
    left_f = f[:Umax_idx]
    left_U = U[:Umax_idx]
    f1_idx = np.argmin(np.abs(left_U - U_half))
    f1 = left_f[f1_idx]

    # 寻找右侧半功率点f2（大于f0的频率区域）
    right_f = f[Umax_idx:]
    right_U = U[Umax_idx:]
    f2_idx = np.argmin(np.abs(right_U - U_half))
    f2 = right_f[f2_idx]

    return f0, f1, f2, U_half


# 使用您提供的实验数据
f = np.array([260.369, 260.389, 260.409, 260.429, 260.439, 260.459, 260.549, 260.590,
              260.610, 260.650, 260.670, 260.700, 260.760, 260.790, 260.8, 260.82,
              260.83, 260.84, 260.85, 260.88, 260.881, 260.883, 260.884, 260.885,
              260.887, 260.888, 260.89, 260.891, 260.892, 260.894, 260.896, 260.898,
              261.168, 261.068, 260.906, 260.909, 260.938, 260.958, 260.978, 261.268,
              261.128, 261.188, 261.023, 260.993])

U = np.array([0.17, 0.177, 0.185, 0.193, 0.197, 0.206, 0.261, 0.294, 0.313, 0.367,
              0.395, 0.454, 0.627, 0.772, 0.843, 0.992, 1.066, 1.169, 1.253, 1.476,
              1.487, 1.488, 1.494, 1.496, 1.498, 1.496, 1.492, 1.491, 1.486, 1.484,
              1.477, 1.464, 0.366, 0.541, 1.419, 1.4, 1.19, 1.042, 0.921, 0.275,
              0.419, 0.341, 0.67, 0.81])

# 计算谐振点和半功率点
f0, f1, f2, U_half = find_half_power_points(f, U)

# 创建更简洁的图表 - 只标出关键点
plt.figure(figsize=(10, 7))
plt.plot(f, U, 'bo', markersize=5, label='数据点')  # 数据点

# 标出谐振频率点和半功率点
plt.scatter(f0, np.max(U), color='black', zorder=5, alpha=0.9)  # 谐振点
plt.scatter(f1, U_half, color='black', s=100, zorder=5, alpha=0.9)  # 半功率点1
plt.scatter(f2, U_half, color='black', s=100, zorder=5, alpha=0.9)  # 半功率点2

# 添加关键点坐标标注 - 均在点的外侧
# 谐振点标注在右上侧
plt.text(f0 + 0.01, np.max(U),
         f'U_max:({f0:.3f}, {np.max(U):.3f})',
         ha='left', va='center', fontsize=10)

# 半功率点1（较小的f）标注在正左侧
plt.text(f1 - 0.01, U_half, f'f_1:({f1:.3f}, 1.066)',
         ha='right', va='center', fontsize=10)

# 半功率点2（较大的f）标注在正右侧
plt.text(f2 + 0.01, U_half, f'f_2:({f2:.3f}, 1.042)',
         ha='left', va='center', fontsize=10)

# 设置图表和标签
plt.xlabel('频率 (Hz)', fontsize=14)
plt.ylabel('电压 (V)', fontsize=14)
plt.title('音叉的幅频特性曲线', fontsize=16)
plt.grid(True, linestyle='--', alpha=0.5)
plt.tight_layout()
plt.xlim(right=261.407)  # 设置x轴范围

# 添加图例
plt.legend(loc='best', fontsize=10)

plt.show()
