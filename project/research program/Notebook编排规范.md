# Jupyter Notebook 编排与生成规范

本文档规定了将课程材料（如 HTML/PDF/Word 内容）转换为带有答题模板的 Jupyter Notebook (`.ipynb`) 文件的统一排版标准。在后续生成任何章节的 Notebook 时，请**严格按照以下要求**进行处理。

## 一、 总体原则

1. **单元格分离（极其重要）**：**绝不要把所有的内容塞进一个单独的单元格里！** 必须根据文稿的逻辑结构（如章节、理论讲解、代码练习）将内容合理拆分为多个 Markdown 单元格和 Code 单元格。
2. **逻辑清晰**：理论部分、作业要求部分使用 Markdown 单元格；需要跑代码验证、实验和编程作业的部分使用 Code（代码）单元格。
3. **保持原始层次**：忠实保留原始文档中的标题层级、粗体强调、列表（包括有序和无序列表）等格式。

---

## 二、 Markdown 单元格排版要求

### 1. 标题与结构
* **章节主标题**：单独占用一个 Markdown 单元格，使用一级标题，如 `# Chapter X: <章节名称>`。如果有 `**Objective:**`（学习目标），紧跟在主标题下方。
* **小节标题**：每个独立的小节使用二级标题，如 `## 1. <小节名称>`。

### 2. 任务与问题格式
遇到 "Tasks:" 或 "Questions to Explore:" 时，需使用粗体包裹，并配合合理的列表缩进：
```markdown
**Tasks:**
1. 第一个任务...
2. 第二个任务...

**Questions to Explore:**
* 问题一...
* 问题二...
```

### 3. 预留答题区（Answer Template）
凡是出现了问题、需要总结或需要思考的地方，**必须**在问题后方的 Markdown 单元格中预留出答题区块。答题区块统一使用引用（Blockquote）格式：
```markdown
> **Answer:**
> [在此填写你的答案]
```

---

## 三、 Code 单元格排版要求

### 1. 独立的代码块
当文档中出现 `Programming Exercise`、`Tasks` 中的代码要求，或明确要求编写代码时，必须**紧接着 Markdown 单元格之后**插入一个空白的 Python 代码单元格 (`code cell`)。

### 2. 占位注释与提示
新插入的代码单元格应该包含清晰的注释，指出这个单元格是用来做什么的，例如：
```python
# Task: [简要描述任务内容，例如：Display 10 random images in a grid]
# [在此编写代码]
```

### 3. 骨架代码（Skeleton Code）
如果原始材料中提供了“骨架代码”、“示例代码”或要求修改某段代码，**不要**把这些代码写在 Markdown 里，而是应该：
1. 直接放入一个 `Code Cell` 中。
2. 保持原有的代码缩进和结构。
3. 导入语句（`import`）放在代码区域顶部。

---

## 四、 模板示例 (Example Layout)

**【Markdown 单元格】**
```markdown
## 3. Visualizing Images

Visualization helps you understand the dataset better.

**Tasks:**
1. Display a few random images from the training dataset.
2. CIFAR-10 has 10 classes. Try to match the numeric labels to the class names.

> **Answer:**
> 1. [针对任务2的文字回答写在这里]
```

**【Code 单元格】**
```python
# Task: Display a few random images from the training dataset
import matplotlib.pyplot as plt

# [在此编写具体代码]
```
