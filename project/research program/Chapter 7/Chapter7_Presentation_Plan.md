# Presentation Plan: Going Deeper with Convolutions


## Presentation Goal

This presentation is designed for a **7-10 minute academic report** in English.

It answers three core questions:
1. What problem does the paper solve?
2. How does the paper solve it?
3. What are the limitations of the paper?

Recommended slide count: **7 slides**

---

## Suggested Timing

| Slide | Topic | Suggested Time |
|---|---|---:|
| 1 | Title and roadmap | 0:30-0:45 |
| 2 | Problem and motivation | 1:00 |
| 3 | Inception module | 1:15-1:30 |
| 4 | Efficiency trick | 1:00-1:15 |
| 5 | GoogLeNet architecture | 1:00-1:15 |
| 6 | Results and impact | 1:00-1:15 |
| 7 | Limitations and takeaway | 1:00-1:15 |

Total: about **7 to 9 minutes**

---

## Slide 1. Title and Roadmap

**Title:** Going Deeper with Convolutions

**Main message:**
This is a landmark CNN paper that introduced the Inception architecture and changed how researchers think about efficient deep networks.

**What to say:**
- Introduce the paper title, authors, and year.
- State why the paper matters: it won ILSVRC 2014 and introduced GoogLeNet.
- Preview the structure of the talk: problem, method, results, and limitations.

## Suggested speaking line:
"Today I will present the paper *Going Deeper with Convolutions*. This paper introduced the Inception architecture, also known through GoogLeNet, and became a major milestone in CNN design. In this presentation, I will explain the problem the paper addresses, the key idea behind the solution, the main experimental results, and the limitations of the work."

**Recommended visual:**
- Paper title and one subtitle line: *Inception architecture under a fixed computational budget*

---

## Slide 2. Problem and Motivation

**Title:** What Problem Does the Paper Solve?

**Main message:**
The paper tries to improve image classification accuracy without simply making the network much more expensive.

**What to say:**
- Earlier CNN progress often came from making models deeper and wider.
- That approach increases parameter count, overfitting risk, memory usage, and computation.
- The paper asks a more practical question: how can we improve accuracy while keeping the computational budget under control?

## Suggested speaking line:
"The main problem is that bigger CNNs are usually more accurate, but they are also more expensive. If we only increase depth and width, we quickly get too many parameters and too much computation. So the real question is how to build a stronger model without letting the cost grow out of control."

**Recommended visual:**
- A simple contrast: *Bigger model -> better accuracy but higher cost*

---

## Slide 3. Core Idea: The Inception Module

**Title:** The Core Idea: Multi-Scale Processing

**Main message:**
The Inception module processes the same input with multiple filter sizes in parallel.

**What to say:**
- The module has parallel branches: 1x1 convolution, 3x3 convolution, 5x5 convolution, and pooling.
- Different branches capture different spatial patterns and receptive field sizes.
- Their outputs are concatenated, so the next layer sees multi-scale information at the same time.

## Suggested speaking line:
"Instead of choosing only one filter size, the Inception module runs several operations in parallel. Small filters capture local details, larger filters capture broader patterns, and pooling adds another type of robust feature extraction. Then all branch outputs are concatenated together."


---

## Slide 4. Why Is It Efficient?

**Title:** Efficiency Through 1x1 Convolutions

**Main message:**
The key engineering trick is using 1x1 convolutions to reduce channel dimensions before expensive operations.

**What to say:**
- A naive multi-branch design would be too computationally expensive.
- The paper uses 1x1 convolutions before 3x3 and 5x5 convolutions.
- These 1x1 layers reduce the number of channels, so later convolutions become much cheaper.
- This makes it possible to increase both depth and width without exploding the cost.

## Suggested speaking line:
"The paper does not just add more branches. It also controls the cost very carefully. Before applying expensive 3x3 and 5x5 filters, it first uses 1x1 convolutions to reduce the channel dimension. This is the main reason the model stays efficient."

---

## Slide 5. GoogLeNet as the Full Network

**Title:** GoogLeNet: A Deep Inception Network

**Main message:**
GoogLeNet is the concrete realization of the Inception idea.

**What to say:**
- GoogLeNet stacks many Inception modules into a 22-layer network.
- It uses auxiliary classifiers to help gradient flow during training.
- It replaces large fully connected layers with global average pooling.
- This reduces parameters while keeping strong predictive performance.

## Suggested speaking line:
"The full network used in the competition is called GoogLeNet. It is 22 layers deep, built by stacking Inception modules. The authors also add auxiliary classifiers during training and use global average pooling near the end, which helps reduce parameter count."

---

## Slide 6. Results and Impact

**Title:** Results: Strong Accuracy with Lower Parameter Cost

**Main message:**
The paper shows that better architecture design can outperform brute-force scaling.

**What to say:**
- GoogLeNet achieved first place in ILSVRC 2014 classification and detection.
- It achieved a top-5 classification error of **6.67%**.
- The model used far fewer parameters than earlier large CNNs such as AlexNet-style systems.
- The paper influenced later CNN design by showing that efficient architecture matters.

## Suggested speaking line:
"The main result is that GoogLeNet achieved state-of-the-art performance on ImageNet while using a more efficient architecture. This showed that a carefully designed network can beat larger, more brute-force models."

**Optional note for speaking:**
- You can mention that the best reported number depends on ensemble prediction and aggressive cropping at test time.

---

## Slide 7. Limitations and Final Evaluation

**Title:** Limitations and Final Takeaway

**Main message:**
The paper is highly influential, but its strongest results rely on several practical choices beyond the core architecture.

**What to say:**
- The architecture design is largely hand-crafted rather than automatically discovered.
- The best performance depends on ensemble models and heavy test-time cropping.
- The training procedure is not described in a perfectly reproducible way.
- The paper is motivated by sparse computation ideas, but the implementation still relies on dense operations.

## Suggested speaking line:
"Although the paper is very successful, it also has limitations. The architecture is manually designed, the best benchmark numbers depend on additional test-time tricks, and the training process is not fully simple to reproduce. So the contribution is very important, but it is not a complete or final solution to efficient deep learning."

**Closing sentence:**
"In summary, this paper solved the problem of improving CNN performance under computational constraints, introduced the Inception module as an efficient multi-scale solution, and became one of the most important papers in the history of convolutional networks."

---

## Most Important Visual Assets

If the final HTML slide deck should stay simple, the **three most valuable content blocks** are:

1. **One Inception module diagram**
2. **One GoogLeNet benchmark table**
3. **One limitations summary page**

That is enough for a clean and persuasive 7-10 minute presentation.

---

## Minimal Slide Design Advice

- Keep each slide to **one main message**.
- Avoid long paragraphs on the slide itself.
- Use short bullets and speak the fuller explanation orally.
- Keep the benchmark and limitations slides visually clean.
- If you build the deck in HTML, the Mermaid diagram can be rendered directly in many slide frameworks.

---

## Optional Short Opening and Ending

**Opening:**
"Good afternoon, Professor. Today I will present the paper *Going Deeper with Convolutions*, which introduced the Inception architecture and helped define a new direction for CNN design."

**Ending:**
"Thank you, Professor. This paper is still worth studying because it shows that careful architecture design can improve both efficiency and accuracy at the same time."