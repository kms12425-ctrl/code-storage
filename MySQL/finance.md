# finance1 数据库表结构说明

## 表1 client（客户表）

| 字段名 | 数据类型 | 约束 | 说明 |
| :--- | :--- | :--- | :--- |
| c_id | INTEGER | PRIMARY KEY | 客户编号 |
| c_name | VARCHAR(100) | NOT NULL | 客户名称 |
| c_mail | CHAR(30) | UNIQUE | 客户邮箱 |
| c_id_card | CHAR(20) | UNIQUE NOT NULL | 客户身份证 |
| c_phone | CHAR(20) | UNIQUE NOT NULL | 客户手机号 |
| c_password | CHAR(20) | NOT NULL | 客户登录密码 |

参数说明：
- `c_id`：客户主键编号，唯一标识一个客户。
- `c_name`：客户姓名。
- `c_mail`：客户邮箱地址，设置唯一约束，不能与其他客户重复。
- `c_id_card`：客户身份证号，唯一且不能为空。
- `c_phone`：客户手机号，唯一且不能为空。
- `c_password`：客户登录密码，不能为空。

## 表2 bank_card（银行卡表）

| 字段名 | 数据类型 | 是否为空 | 键 |
| :--- | :--- | :--- | :--- |
| b_number | CHAR(30) | NO | PRI |
| b_type | CHAR(20) | YES | |
| b_c_id | INT | NO | MUL |
| b_balance | DECIMAL(10,2) | YES | |

参数说明：
- `b_number`：银行卡号，主键。
- `b_type`：银行卡类型，例如储蓄卡、信用卡。
- `b_c_id`：持卡客户编号，通常关联 `client.c_id`。
- `b_balance`：银行卡余额，保留两位小数。

说明：`b_c_id` 通常用于关联客户表主键 `c_id`。

## 表3 finances_product（理财产品表）

| 字段名 | 数据类型 | 是否为空 | 键 |
| :--- | :--- | :--- | :--- |
| p_name | VARCHAR(100) | NO | |
| p_id | INT | NO | PRI |
| p_description | VARCHAR(4000) | YES | |
| p_amount | INT | YES | |
| p_year | INT | YES | |

参数说明：
- `p_id`：理财产品编号，主键。
- `p_name`：理财产品名称。
- `p_description`：理财产品描述信息（介绍、规则等）。
- `p_amount`：理财产品金额或起购金额。
- `p_year`：理财期限（年）。

## 表4 insurance（保险表）

| 字段名 | 数据类型 | 是否为空 | 键 |
| :--- | :--- | :--- | :--- |
| i_name | VARCHAR(100) | NO | |
| i_id | INT | NO | PRI |
| i_amount | INT | YES | |
| i_person | CHAR(20) | YES | |
| i_year | INT | YES | |
| i_project | VARCHAR(200) | YES | |

参数说明：
- `i_id`：保险产品编号，主键。
- `i_name`：保险名称。
- `i_amount`：保险金额（保额或产品金额信息）。
- `i_person`：被保险人群体说明（如成人、少儿等）。
- `i_year`：保险年限。
- `i_project`：保障项目（如重疾、医疗、意外等）。

## 表5 fund（基金表）

| 字段名 | 数据类型 | 是否为空 | 键 |
| :--- | :--- | :--- | :--- |
| f_name | VARCHAR(100) | NO | UNI |
| f_id | INT | NO | PRI |
| f_type | CHAR(20) | YES | |
| f_amount | INT | YES | |
| risk_level | CHAR(20) | NO | |
| f_manager | INT | NO | |

参数说明：
- `f_id`：基金编号，主键。
- `f_name`：基金名称，唯一。
- `f_type`：基金类型（如货币型、债券型、混合型等）。
- `f_amount`：基金金额（可按课程定义理解为单价或规模字段）。
- `risk_level`：风险等级。
- `f_manager`：基金经理编号。

## 表6 property（资产持有表）

| 字段名 | 数据类型 | 是否为空 | 键 |
| :--- | :--- | :--- | :--- |
| pro_id | INT | NO | PRI |
| pro_c_id | INT | NO | MUL |
| pro_pif_id | INT | NO | |
| pro_type | INT | NO | |
| pro_status | CHAR(20) | NO | |
| pro_quantity | INT | YES | |
| pro_income | INT | YES | |
| pro_purchase_time | DATE | YES | |

参数说明：
- `pro_id`：资产记录编号，主键。
- `pro_c_id`：客户编号，关联客户表主键 `client.c_id`。
- `pro_pif_id`：产品编号，关联具体产品主键（理财/保险/基金之一）。
- `pro_type`：资产类型标记，常见约定 `1=理财，2=保险，3=基金`。
- `pro_status`：资产状态（如持有中、已赎回、已到期等）。
- `pro_quantity`：持有数量。
- `pro_income`：该笔资产收益。
- `pro_purchase_time`：购买日期。

说明：
- `pro_c_id` 通常关联客户编号（`client.c_id`）。
- `pro_pif_id` 一般用于关联具体产品编号（可能指向理财、保险或基金）。
- `pro_type` 可用于区分产品类别，例如：1=理财，2=保险，3=基金（具体以你的课程要求为准）。

## 你截图里提到的一处语法点

在 MySQL 中：
- `SHOW` 后面通常是 `DATABASES / TABLES / COLUMNS / CREATE TABLE ...` 等关键字。
- 查看某张表结构应使用：

```sql
DESC insurance;
-- 或
DESCRIBE insurance;
```

`SHOW insurance;` 会报 1064 语法错误，这个现象和你截图一致。

## 可选：对应建表 SQL（简化版）

```sql
CREATE TABLE client (
  c_id INT PRIMARY KEY,
  c_name VARCHAR(100) NOT NULL,
  c_mail CHAR(30) UNIQUE,
  c_id_card CHAR(20) UNIQUE NOT NULL,
  c_phone CHAR(20) UNIQUE NOT NULL,
  c_password CHAR(20) NOT NULL
);

CREATE TABLE bank_card (
  b_number CHAR(30) PRIMARY KEY,
  b_type CHAR(20),
  b_c_id INT NOT NULL,
  b_balance DECIMAL(10,2),
  CONSTRAINT FK_bank_card_client FOREIGN KEY (b_c_id) REFERENCES client(c_id)
);

CREATE TABLE finances_product (
  p_id INT PRIMARY KEY,
  p_name VARCHAR(100) NOT NULL,
  p_description VARCHAR(4000),
  p_amount INT,
  p_year INT
);

CREATE TABLE insurance (
  i_id INT PRIMARY KEY,
  i_name VARCHAR(100) NOT NULL,
  i_amount INT,
  i_person CHAR(20),
  i_year INT,
  i_project VARCHAR(200)
);

CREATE TABLE fund (
  f_id INT PRIMARY KEY,
  f_name VARCHAR(100) NOT NULL UNIQUE,
  f_type CHAR(20),
  f_amount INT,
  risk_level CHAR(20) NOT NULL,
  f_manager INT NOT NULL
);

CREATE TABLE property (
  pro_id INT PRIMARY KEY,
  pro_c_id INT NOT NULL,
  pro_pif_id INT NOT NULL,
  pro_type INT NOT NULL,
  pro_status CHAR(20) NOT NULL,
  pro_quantity INT,
  pro_income INT,
  pro_purchase_time DATE,
  CONSTRAINT FK_property_client FOREIGN KEY (pro_c_id) REFERENCES client(c_id)
);
```

## 创建视图语句参数解释（保险资产明细）

推荐使用的语句：

```sql
CREATE OR REPLACE VIEW v_insurance_detail AS
SELECT
  c.c_name,
  c.c_id_card,
  i.i_name,
  i.i_project,
  p.pro_status,
  p.pro_quantity,
  i.i_amount,
  i.i_year,
  p.pro_income,
  p.pro_purchase_time
FROM client c
JOIN property p ON p.pro_c_id = c.c_id
JOIN insurance i ON p.pro_pif_id = i.i_id
WHERE p.pro_type = 2;
```

### 1）视图和关键字

- `CREATE VIEW`：创建视图。
- `OR REPLACE`：如果视图已存在则覆盖（避免重复创建报错）。
- `v_insurance_detail`：视图名，表示“保险资产明细”。

### 2）表别名

- `client c`：`c` 代表客户表。
- `property p`：`p` 代表资产持有表。
- `insurance i`：`i` 代表保险产品表。

作用：写成 `c.c_name` 这种形式更清晰，也避免同名字段冲突。

### 3）SELECT 中每个字段含义

- `c.c_name`：购买客户姓名。
- `c.c_id_card`：客户身份证号。
- `i.i_name`：保险名称。
- `i.i_project`：保障项目。
- `p.pro_status`：该资产当前状态（例如持有中、已到期等）。
- `p.pro_quantity`：购买数量。
- `i.i_amount`：保险金额（产品金额信息）。
- `i.i_year`：保险年限。
- `p.pro_income`：该笔资产收益。
- `p.pro_purchase_time`：购买时间。

### 4）JOIN 关联条件含义

- `p.pro_c_id = c.c_id`：把“资产记录”关联到“对应客户”。
- `p.pro_pif_id = i.i_id`：把“资产记录”关联到“对应保险产品”。

注意：`property` 表里没有 `i_id` 字段，所以不能写 `p.i_id = i.i_id`。

### 5）WHERE 条件含义

- `p.pro_type = 2`：只筛选保险类资产。

根据本文件约定：`pro_type` 通常 `1=理财，2=保险，3=基金`。

