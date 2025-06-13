from scipy.signal import savgol_filter
from scipy.stats import linregress
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import PchipInterpolator

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

# # === 原始数据 ===
# frequencies = np.array(
#     [100, 200, 500, 1000, 2000, 4000, 6000, 8000, 10000, 12000])
# levels = np.array([17,   8.5,  6.0,    0,   -8.5,  -
#                   10,  -25.5,  -7.5,    3,     6.5])
# log_freq = np.log10(frequencies)

# # === PCHIP 插值，消除不必要的峰值 ===
# pchip = PchipInterpolator(log_freq, levels)
# x_smooth = np.linspace(log_freq.min(), log_freq.max(), 300)
# y_smooth = pchip(x_smooth)

# # === 绘图 ===
# fig, ax = plt.subplots(figsize=(7, 4))
# ax.plot(x_smooth, y_smooth, linewidth=2, label='曲线')
# ax.scatter(log_freq, levels, color='black', zorder=5, label='数据点')

# # 标注原始频率
# for x, y, f in zip(log_freq, levels, frequencies):
#     ax.annotate(f"{f:.0f} Hz",
#                 xy=(x, y), xytext=(0, 6),
#                 textcoords="offset points",
#                 ha='center', fontsize=9)

# # 坐标与标题
# ax.set_xticks(log_freq)
# ax.set_xticklabels([f"{v:.2f}" for v in log_freq], rotation=45, ha='right')
# ax.set_xlabel("频率的常用对数", fontsize=12)
# ax.set_ylabel("L测/dB", fontsize=12)
# ax.set_title("不同条件下人耳的听觉阈值", fontsize=14)

# # x 轴移至 y=0，隐藏多余脊梁
# ax.spines['bottom'].set_position(('data', 0))
# ax.spines['top'].set_visible(False)
# ax.spines['right'].set_visible(False)

# # x-label 下移
# ax.xaxis.set_label_coords(0.5, -0.12)

# # 网格 & 图例
# ax.grid(True, linestyle='--', alpha=0.5)
# ax.legend(loc='upper right')

# plt.tight_layout()
# plt.show()


# # === 1. 准备数据（已为 mV，无需再转换） ===
# P = np.array([2.67, 5.33, 8, 10.67, 13.33, 16,
#               18.67, 21.33, 24, 26.66])         # 压强 (kPa)
# U = np.array([7.2, 13, 19.2, 23.8, 29.4, 35.4,
#               40.8, 46.2, 51.9, 57.1])           # 电压 (mV)

# # === 2. 线性拟合 ===
# slope, intercept, r_value, p_value, std_err = linregress(P, U)
# r_squared = r_value**2

# print(f"灵敏度 S = {slope:.4f} mV/kPa")
# print(f"截距 U₀  = {intercept:.4f} mV")
# print(f"相关系数 r = {r_value:.4f}")
# print(f"决定系数 R² = {r_squared:.4f}")

# # === 3. 绘图 ===
# fig, ax = plt.subplots(figsize=(6, 4))

# # 实验数据散点
# ax.scatter(P, U, color='blue', label='实验数据')

# # 拟合直线（实线）
# P_fit = np.linspace(0, P.max() * 1.05, 100)
# U_fit = slope * P_fit + intercept
# ax.plot(P_fit, U_fit, 'r-', linewidth=2,
#         label=f'U = {slope:.4f}·P + {intercept:.4f} (mV)')

# # 坐标轴从 0 开始
# ax.set_xlim(0, P.max() * 1.05)
# ax.set_ylim(0, U.max() * 1.05)

# # 坐标与美化
# ax.set_xlabel("压强 P (kPa)", fontsize=12)
# ax.set_ylabel("电压 U (mV)", fontsize=12)
# ax.set_title("不同压强下气体传感器输出电压", fontsize=14)
# ax.grid(True, linestyle='--', alpha=0.5)

# # 把注释（R²）放在左上角
# ax.text(0.02, 0.98,
#         f'$R^2$ = {r_squared:.4f}',
#         transform=ax.transAxes,
#         fontsize=12,
#         va='top',
#         bbox=dict(boxstyle='round,pad=0.3', facecolor='white', alpha=0.7))

# ax.legend(loc='lower right')

# plt.tight_layout()
# plt.show()


# === 原始数据 ===
Z = np.array([28424, 21042, 14669, 9218, 4534,
              2502, 1420, 658, 437, 363, 364, 442])
lgf = np.array([1.301, 1.699, 2, 2.301, 2.699,
                3, 3.301, 3.699, 4, 4.301, 4.699, 5])

# === 按 lgf 升序排序（便于平滑绘图）===
sort_idx = np.argsort(lgf)
lgf_sorted = lgf[sort_idx]
Z_sorted = Z[sort_idx]

# === Savitzky-Golay 平滑 ===
window_length = 5
polyorder = 2
wl = min(window_length, len(Z_sorted) if len(Z_sorted) %
         2 == 1 else len(Z_sorted) - 1)
wl = max(wl, polyorder + 2)
if wl % 2 == 0:
    wl += 1
Z_smooth = savgol_filter(Z_sorted, window_length=wl, polyorder=polyorder)

# === 绘图 ===
plt.figure(figsize=(8, 4))
plt.plot(lgf_sorted, Z_smooth, color='blue', linewidth=2, label='曲线')
plt.scatter(lgf, Z, color='red', label='数据点', zorder=5)

# 轴标签与标题
plt.xlabel("lg(f)", fontsize=12)
plt.ylabel("电阻 Z (Ω)", fontsize=12)
plt.title("Z-lgf曲线", fontsize=14)

# 网格与图例
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.show()
