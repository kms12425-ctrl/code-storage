import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

# 实验数据
n = np.array([1, 2, 3])  # 波腹数（个）
frequency = np.array([118.312, 239.413, 355.000])  # 频率（Hz）
wavelength = np.array([60, 30, 20])  # 波长（cm）

# 执行最小二乘法线性回归：频率 vs 波腹数
slope, intercept, r_value, p_value, std_err = stats.linregress(n, frequency)

# 计算拟合值
fit_line = slope * n + intercept

# 计算决定系数 R²
r_squared = r_value**2

# 准备拟合方程文本
equation = f"f = {slope:.4f}n + {intercept:.4f}"

# 绘制关系图
plt.figure(figsize=(10, 6))

# 绘制原始数据点
plt.scatter(n, frequency, color='blue', s=80, label='实验数据点', zorder=5)

# 绘制拟合直线（延长到坐标轴边界）
x_fit = np.array([0.5, 3.5])
y_fit = slope * x_fit + intercept
plt.plot(x_fit, y_fit, 'r-', linewidth=2, label='线性拟合曲线')

# 添加拟合方程和R²值文本
plt.text(0.05, 0.95, equation,
         transform=plt.gca().transAxes, fontsize=12,
         verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

plt.text(0.05, 0.88, f"$R^2$ = {r_squared:.6f}",
         transform=plt.gca().transAxes, fontsize=12,
         verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

# 设置图表标题和坐标轴标签
plt.title('波腹数与驻波频率的线性关系', fontsize=16)
plt.xlabel('波腹数 n (个)', fontsize=14)
plt.ylabel('频率 f (Hz)', fontsize=14)

# 添加网格
plt.grid(True, linestyle='--', alpha=0.6)

# 设置坐标轴范围
plt.xlim(0.5, 3.5)
plt.ylim(0, 400)

# 添加图例
plt.legend(loc='lower right', fontsize=12)

# 调整布局并显示
plt.tight_layout()
plt.show()

# 打印R²计算过程
print("="*80)
print("R²计算详细过程：")
print("1. 计算波腹数n和频率f的平均值：")
n_mean = np.mean(n)
f_mean = np.mean(frequency)
print(f"   n̄ = {n_mean:.3f}, f̄ = {f_mean:.3f} Hz")

print("\n2. 计算总平方和(SST)、回归平方和(SSR)和残差平方和(SSE)：")

# 计算SST（总平方和）
SST = np.sum((frequency - f_mean)**2)
print(f"   SST = Σ(fᵢ - f̄)² = {SST:.6f}")

# 计算预测值
predicted_f = slope * n + intercept

# 计算SSR（回归平方和）
SSR = np.sum((predicted_f - f_mean)**2)
print(f"   SSR = Σ(ŷᵢ - f̄)² = {SSR:.6f}")

# 计算SSE（残差平方和）
SSE = np.sum((frequency - predicted_f)**2)
print(f"   SSE = Σ(fᵢ - ŷᵢ)² = {SSE:.6f}")

print("\n3. 计算决定系数R²：")
r_squared_calculated = 1 - (SSE/SST)
print(
    f"   R² = 1 - (SSE/SST) = 1 - ({SSE:.6f}/{SST:.6f}) = {r_squared_calculated:.6f}")

# 验证公式二
r_squared_formula2 = SSR / SST
print(f"   或者：R² = SSR/SST = ({SSR:.6f}/{SST:.6f}) = {r_squared_formula2:.6f}")

print("="*80)
print("\n最终结果：")
print(f"线性拟合方程: {equation}")
print(f"决定系数 R² = {r_squared:.6f}")

print("\n理论分析：")
print("根据驻波理论，频率f与波腹数n的关系应为：f = (n / (2L)) × √(T/μ)")
print("其中：")
print("L - 弦线长度（cm）")
print("T - 弦线张力（N）")
print("μ - 线密度（g/m）")
print("")
print("这表明频率f与波腹数n应成线性关系：f ∝ n")
print(f"实验结果中的拟合方程 f = {slope:.4f}n + {intercept:.4f} 验证了这一理论关系")
print(f"极高的R²值（>{r_squared:.6f}）表明线性模型对数据的拟合度非常好")
