import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

# 实验数据
m_x = np.array([0, 10, 20, 30, 40, 50])  # 横坐标：所加质量 m_x (单位：g)
inv_f_squared = np.array([14.692, 19.788, 24.544, 30.874,
                         36.467, 41.638])  # 纵坐标：1/f² × 10^{-6} (单位：1/Hz²)

# 执行最小二乘法线性回归
slope, intercept, r_value, p_value, std_err = stats.linregress(
    m_x, inv_f_squared)

# 计算拟合值
fit_line = slope * m_x + intercept

# 计算决定系数 R²
r_squared = r_value**2

# 准备拟合方程文本
# 使用实际数值代替科学计数法表示
equation = f"y = {slope:.4f}x + {intercept:.4f}"
r2_text = f"$R^2$ = {r_squared:.6f}"

# 绘制数据点和拟合直线
plt.figure(figsize=(10, 6))

# 绘制原始数据点
plt.scatter(m_x, inv_f_squared, color='blue', s=80, label='实验数据点', zorder=5)

# 绘制拟合直线
plt.plot(m_x, fit_line, 'r-', linewidth=2, label='线性拟合曲线')

# 添加拟合方程和R²值文本
# 放在图的左上角
plt.text(0.05, 0.95, equation,
         transform=plt.gca().transAxes, fontsize=12,
         verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

plt.text(0.05, 0.87, r2_text,
         transform=plt.gca().transAxes, fontsize=12,
         verticalalignment='top', bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

# 设置图表标题和坐标轴标签
plt.title('音叉 1/f² 与所加质量 $m_x$ 的关系', fontsize=16)
plt.xlabel('所加质量 $m_x$ (g)', fontsize=14)

# 根据数据调整纵坐标标签
plt.ylabel(r'$\frac{1}{f^2} \times 10^{-6}\,(\text{Hz}^{-2})$', fontsize=14)

# 添加网格
plt.grid(True, linestyle='--', alpha=0.6)

# 设置x轴范围从0开始，留出一些空间
plt.xlim(-2, 52)

# 添加图例
plt.legend(loc='lower right', fontsize=12)

# 调整布局并显示
plt.tight_layout()
plt.show()

# 打印拟合结果和分析
print("="*50)
print(f"线性拟合方程: {equation}")
print(f"斜率 (k) = {slope:.6f} (10^{-6}/g)")
print(f"截距 (b) = {intercept:.6f} (10^{-6})")
print(f"决定系数 R² = {r_squared:.6f}")
print("="*50)

# 分析线性关系和物理意义
print("\n结果分析：")
print(f"1. 决定系数 R² = {r_squared:.6f} > 0.99，表明1/f²与m_x之间呈现强线性关系")
print(f"2. 斜率 k = {slope:.6f} × 10^{-6}/g，反映了频率对质量变化的敏感度")
print(f"3. 截距 b = {intercept:.6f} × 10^{-6}，对应音叉自身质量引起的1/f²值")
print(f"4. 根据物理公式 1/f² = (4π²m₀/k) + (4π²/k)m_x，其中：")
print(f"   - k 为弹性系数，可以从斜率计算")
print(f"   - m₀ 为音叉固有质量，可以从截距计算")

# 计算物理参数（假设值，需要根据实际公式调整）
k = 4 * np.pi**2 / slope  # 估算的弹性系数
m0 = intercept / (slope / k)  # 估算的固有质量

print("\n估算的物理参数：")
print(f"弹性系数 k ≈ {k:.4e} N/m")
print(f"固有质量 m₀ ≈ {m0:.6f} g")
