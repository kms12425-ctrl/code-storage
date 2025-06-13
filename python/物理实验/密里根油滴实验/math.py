# import math

# # 输入参数 (根据实际值修改以下参数)
# eta = 0.0000183   # 流体粘度 [Pa·s]
# l = 0.002         # 特征长度 [m]
# t_g = 14.6       # 时间 [s]
# b = 0.00000617        # 修正系数 [无量纲]
# p = 76      # 压力 [Pa]
# d = 0.005       # 直径 [m]
# U = 150         # 电压 [V]
# rho = 981     # 流体密度 [kg/m³]
# g = 9.795        # 重力加速度 [m/s²]

# ---------------------- 计算过程 ----------------------
# 1. 计算气体速度 v_g = l / t_g
# v_g = (l / t_g)

# 2. 计算特征长度 a = sqrt(9*eta*v_g / (2*rho*g))
# a = (math.sqrt(9 * eta * (l / t_g) / (2 * rho * g)))

# 3. 计算流量 q = (18π / sqrt(2ρg)) * [ηl/(t_g*(1 + b/(p*a)))]^(3/2) * (d/U)
# 分步计算分母和指数项
# denominator = (t_g * (1 + b / (p * a)))  # 分母项 t_g*(1 + b/(p*a))
# term = ((eta * l) / (t_g * (1 + b / (p * a))))          # 方括号内的项
# q = (18 * math.pi / math.sqrt(2 * rho * g)) * (((eta * l) / (t_g * (1 + b / (p * (math.sqrt(9 * eta * (l / t_g) / (2 * rho * g)))))))   ** 1.5) * (d / U)

# ---------------------- 结果输出 ----------------------
# print(f"计算参数:")
# print(f"v_g = {v_g:.4f} m/s")
# print(f"a = {a:.4f} m")
# print(f"q = {q:.4e} m³/s")  # 科学计数法显示小数值
# 输出公式验证
# print("\n公式验证:")
# print(f"v_g = l / t_g = {l} / {t_g} = {v_g:.4f}")
# print(f"a = sqrt(9*η*v_g/(2ρg)) = sqrt(9*{eta}*{v_g:.4f}/(2*{rho}*{g})) = {a:.4f}")
# print(f"q = (18π/sqrt(2ρg)) * [ηl/(t_g(1 + b/(pa)))]^1.5 * (d/U)\n"
#       f"  = (18π/{math.sqrt(2*rho*g):.4f}) * [{eta*lenominator:.4e}]^1.5 * {d/U:.4f}\n"
#       f"  = {q:.4e}")
# -*- coding: utf-8 -*-
# import numpy as np
# import matplotlib.pyplot as plt

# # 设置中文字体（根据操作系统选择）
# plt.rcParams['font.sans-serif'] = [
#     'Microsoft YaHei'  # Windows首选
# ]
# plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示异常
# # 步骤1: 准备数据
# # =============================== ↓ 在这里插入你的数据 ↓ ===============================
# n = [11.96, 6.12, 5.15, 7.41, 12.05, 11.44, 14.40, 4.56, 11.03, 12.40, 4.39]   # 替换为你的q值列表（横坐标）
# q = [7.47, 3.82, 3.22, 4.63, 7.53, 7.15, 9.00, 2.85, 6.89, 7.75, 2.74]   # 替换为你的n值列表（纵坐标）
# # =============================== ↑ 在这里插入你的数据 ↑ ===============================

# # 步骤2: 最小二乘法拟合（线性，不会过度拟合）
# slope, intercept = np.polyfit(q, n, 1)
# print(f"最小二乘法直线斜率: 1.6939, 截距: {intercept:.4f}")

# # 只用两个端点来绘制这条直线
# q_fit = np.array([0, max(q)])  # 仅两点：q_min, q_max
# n_fit = slope * q_fit + intercept

# # 步骤3: 绘制图形
# plt.figure(figsize=(8, 6))

# # 绘制原始数据点
# plt.scatter(q, n, color='blue', label='数据点')

# # 绘制拟合直线
# plt.plot(q_fit, n_fit, color='red', label=f'拟合直线: n = 1.6939q + {intercept:.4f}')
# plt.xlim(0, max(q) * 1.05)
# plt.ylim(0, max(n_fit) * 1.05)
# # 图表修饰
# plt.title('q–n 曲线', fontsize=14, fontweight='bold')
# plt.ylabel('q(x10^-18C)', fontsize=12)
# plt.xlabel('n(个)', fontsize=12)
# plt.grid(True, linestyle='--', alpha=0.7)
# plt.legend()
# plt.tight_layout()

# # 显示图形
# plt.show()
from sklearn.metrics import r2_score  # 用 sklearn 来算 R^2，更方便
import numpy as np
import matplotlib.pyplot as plt
# 设置中文字体（根据操作系统选择）
plt.rcParams['font.sans-serif'] = [
    'Microsoft YaHei'  # Windows首选
]
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示异常


# 数据
n = np.array([10.0392, 7.3144, 4.35215, 4.341275])
q = np.array([16.0627, 11.7031, 6.96344, 6.94604])

# 最小二乘法拟合: q = k * n + b
coeffs = np.polyfit(n, q, 1)
k, b = coeffs

# 计算拟合值
q_pred = k * n + b

# 计算 R^2
r2 = r2_score(q, q_pred)

print(f"拟合直线: q = {k:.4f} * n + {b:.4f}")
print(f"R^2 = {r2:.4f}")

# 生成拟合直线的点，x 从 0 开始，延长到比 max(n) 稍大一些
n_fit = np.linspace(0, max(n) * 1.1, 200)
q_fit = k * n_fit + b

# 绘图
plt.figure(figsize=(6, 4))
plt.scatter(n, q, color='blue', label='数据点')
plt.plot(n_fit, q_fit, color='red',
         label=f'拟合直线: q = {k:.4f} n + {b:.4f}\n$R^2$ = {r2:.4f}')
plt.xlabel('n')
plt.ylabel('q')
plt.title('q-n关系')
plt.legend()
plt.grid(True)
plt.xlim(0)  # X 轴从 0 开始
plt.ylim(0)  # Y 轴从 0 开始
plt.show()
