import math


def compute_q(U, t_e, t_g, d, rho, g, eta, l, b, p):
    """
    计算动态法测量中的 a, K, q

    参数：
    U   : 电压或其他实验常数
    t_e : 上升（或下降）时间 te
    t_g : 平衡速度测量时间 tg
    d   : 滴管（或液滴）直径
    rho : 液体密度 ρ
    g   : 重力加速度 g
    eta : 液体粘度 η
    l   : 滴落距离 l
    b   : 透气孔常数 b
    p   : 空气密度 p

    返回值：
    a   : 下落加速度
    K   : 公式 K 的值
    q   : 计算得到的电荷量或其他量
    """

    # 1. 先计算 v_g = l / t_g
    v_g = l / t_g

    # 2. 计算 a = sqrt(9 η v_g / (2 ρ g))
    a = math.sqrt(9 * eta * v_g / (2 * rho * g))

    term1 = 18 * math.pi * d / math.sqrt(2 * rho * g)
    term2 = (eta * l / (1 + b / (p * a))) ** 1.5  # 只让分式取 3/2 次方
    K = term1 * term2

    # 4. 计算 q = (K / U) * (1/t_e + 1/t_g) * (1/t_g)^(1/2)
    q = (K / U) * (1.0/t_e + 1.0/t_g) * (1.0/t_g) ** 0.5

    return a, K, q


if __name__ == "__main__":
    # 示例参数（请替换为你的实验数据）
    U = 262     # 电压 (V)
    t_e = 24.2       # 上升时间 te (s)
    t_g = 27.6        # 平衡时间 tg (s)
    d = 0.005    # 滴管直径 d (m)
    rho = 981       # 空气密度 ρ (kg/m³)
    g = 9.795       # 重力加速度 g (m/s²)
    eta = 1.83e-5    # 空气粘度 η (Pa·s)
    l = 0.002     # 滴落距离 l (m)
    b = 6.17e-6     # 常数 b (Pa·s)
    p = 76     # 大气压强 p (Pa)

    a, K, q = compute_q(U, t_e, t_g, d, rho, g, eta, l, b, p)
    # print(f"a = {a:.5e} m/s²")
    # print(f"K = {K:.5e}")
    print(f"q = {q:.5e} (单位视具体实验而定)")
