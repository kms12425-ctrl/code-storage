# Presentation Script: Chapter 6 - Training, Evaluating, and Interpreting a CNN

## Introduction
"Good afternoon, Professor.
In Chapter 6, I moved from CNN theory to a full experimental pipeline on CIFAR-10.
Today I will present four parts: training behavior, evaluation against FCNN, feature-map interpretation, and the effect of data augmentation."

---

## Part 1: Training Dynamics and Generalization
"I trained multiple CNN configurations with different learning rates, batch sizes, model widths/depths, and dropout settings.
To improve stability and convergence, I used two key callbacks: ReduceLROnPlateau and EarlyStopping."

### What I Observed in the Curves
- **Training accuracy trend**: In most runs, training accuracy increased steadily over epochs.
- **Validation accuracy trend**: Validation accuracy improved quickly at first, then plateaued in many settings.
- **Overfitting pattern**: In several runs, training accuracy kept rising while validation stopped improving or slightly dropped.

"This train-val gap is a standard sign of overfitting: the model keeps fitting training details but does not gain additional generalization."

### Why Some Runs Underperformed
- **Too large batch sizes** reduced useful gradient noise and hurt generalization.
- **Poorly tuned capacity** (too wide or misconfigured) produced very low test accuracy in some experiments.
- **Insufficient regularization/data diversity** made overfitting appear earlier.

---

## Part 2: Test Evaluation and FCNN Comparison
"I evaluated each trained model on the test set to obtain an unbiased performance estimate."

### Key Test Results (Approx.)
- **Best CNN (deep_small_filters_aug)**: about **0.78**
- **Baseline + augmentation**: about **0.67**
- **Baseline (no augmentation)**: about **0.60**
- **Poorly tuned larger/wider settings**: about **0.16-0.19**

### CNN vs FCNN
"Compared with the FCNN from Chapter 3, CNN performs better overall.
Depending on the FCNN baseline, the best CNN is typically around **5-20 percentage points** higher."

### Why CNN Wins
- **Local receptive fields** capture nearby pixel structure.
- **Weight sharing** reduces parameters and improves data efficiency.
- **Hierarchical feature learning** builds from edges to semantic parts.
- **Better synergy with augmentation** leads to stronger robustness.

---

## Part 3: Feature Map Interpretation
"To understand what the network learns internally, I extracted intermediate convolution outputs and visualized feature maps for a test image."

### Layer-wise Interpretation
- **Early layers**: detect low-level cues such as edges, color blobs, and simple textures.
- **Middle layers**: combine primitives into richer textures and local motifs.
- **Deep layers**: respond to larger receptive fields and object-part patterns with sparser activations.

"In short, the representation evolves from local visual primitives to class-relevant semantic structure."

### Why This Helps Classification
- The model can separate classes using progressively more abstract and discriminative features.
- It becomes less sensitive to small local noise and more sensitive to meaningful object structure.

---

## Part 4: Impact of Data Augmentation
"I applied online augmentation using RandomFlip, RandomRotation, and RandomZoom during training."

### Practical Impact
- Baseline improved from about **0.60** to about **0.67** with augmentation.
- Top-performing runs benefited even more and reached around **0.78**.

### Interpretation
- Augmentation increases sample diversity without collecting new data.
- It reduces overfitting by exposing the model to transformed views.
- It improves invariance to orientation/position/scale changes.

"So augmentation is not just a minor trick; in this chapter it was a major contributor to generalization gains."

---

## Reflection and Next Steps
"To summarize Chapter 6:
1) CNN clearly outperformed FCNN on image classification.
2) Training curves showed the expected trade-off between fitting and generalization.
3) Feature maps validated the hierarchical learning hypothesis.
4) Data augmentation consistently improved robustness and test accuracy."

"For future improvement, I plan to:
- add stronger regularization tuning (dropout + weight decay),
- use more efficient architectures with global average pooling,
- and perform more systematic hyperparameter search with smaller, better-chosen batch sizes."

"Thank you, Professor. This concludes my Chapter 6 presentation."