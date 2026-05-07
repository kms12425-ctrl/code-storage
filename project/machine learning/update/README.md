# update 目录说明

本目录存放在不修改原始实现前提下的改进版 AdaBoost 代码，主要改进点如下：

1. `data_utils.py`：将普通随机 10 折改为分层 10 折，并增强输出目录解析能力。
2. `learners.py`：决策树桩使用相邻不同取值的中点作为阈值；逻辑回归加入学习率衰减和更稳健的提前停止。
3. `adaboost.py`：增加弱学习器误差大于 `0.5` 时的翻转处理，以及无效弱学习器的提前终止逻辑。
4. `main.py`：保持与原始版本相同的命令行接口，可直接独立运行。

建议在 `update` 目录中运行：

```bash
python main.py ../data_and_samples/data.csv ../data_and_samples/target.csv 0
python main.py ../data_and_samples/data.csv ../data_and_samples/target.csv 1
```