def calculate_impedance(U_Z, U_R0, R0):
    """
    计算阻抗 Z

    参数:
    U_Z   -- 待测电压 U_Z（单位 V）
    U_R0  -- 基准电压 U_R0（单位 V）
    R0    -- 基准电阻 R0（单位 Ω）

    返回:
    Z     -- 计算得到的阻抗值（单位 Ω）
    """
    if U_R0 == 0:
        raise ValueError("U_R0 不能为零")
    Z = (U_Z / U_R0) * R0
    return Z


if __name__ == "__main__":
    # 示例：你可以在这里替换为实际测量值
    U_Z_value = 0.06
    U_R0_value = 1.356
    R0_value = 10000

    try:
        Z_value = calculate_impedance(U_Z_value, U_R0_value, R0_value)
        print(f"计算得到的阻抗 Z = {Z_value:.4f} Ω")
    except ValueError as e:
        print("计算出错：", e)
