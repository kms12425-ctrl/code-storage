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
- **Training accuracy trend**: In most experiments, training accuracy kept going up steadily.
- **Validation accuracy trend**: Validation accuracy usually improved early, then became stable.
- **General pattern**: When training kept rising but validation stopped improving, that suggested overfitting.

"So from these curves, I can see that the models were learning, but not every setting generalized equally well.
Some configurations learned useful patterns and stabilized at a good validation level, while others kept fitting the training set without improving test performance."

### Why Some Runs Underperformed
- **Very large batch sizes** hurt optimization and gave weak results.
- **The bigger and wide models** performed especially poorly, with test accuracy staying very low.
- **Model setting matters**: depth and augmentation helped more than simply making the model wider.

"This means performance was not determined by model size alone.
Good results came from a better balance between architecture, learning rate, regularization, and data diversity."

---

## Part 2: Test Evaluation and FCNN Comparison
"I evaluated each trained model on the test set to obtain an unbiased performance estimate."

### Experimental Groups and Their Main Differences
- **baseline_noaug**: the standard reference model with two convolution blocks, learning rate 1e-3, batch size 512, dropout 0.5, and no data augmentation.
- **baseline_aug**: the same baseline model, but trained with RandomFlip, RandomRotation, and RandomZoom. This shows the direct effect of augmentation on the standard setup.
- **bigger_noaug**: a larger-capacity model with more filters, more dense units, and a very large batch size of 2048, without augmentation. This tested whether simply scaling the model up would help.
- **bigger_aug**: the same larger model, but with augmentation. This tested whether augmentation could rescue a poorly optimized large-batch setting.
- **low_lr_aug_noaug**: a model using a smaller learning rate of 5e-4, without augmentation. Its main feature was slower and more conservative optimization.
- **low_lr_aug_aug**: the same 5e-4 learning-rate setting, but with augmentation. This tested the interaction between slower learning and stronger data diversity.
- **deep_small_filters_noaug**: a deeper model with three convolution stages and gradually increasing filters, without augmentation. Its main idea was to improve feature extraction through depth.
- **deep_small_filters_aug**: the same deeper architecture with augmentation. This combined stronger feature extraction and better data diversity, and it gave the best result.
- **wide_noaug**: a wider model with 128 and 128 filters and a larger dense layer, without augmentation. This focused on width rather than depth.
- **wide_aug**: the same wide model, but with augmentation. This tested whether data augmentation could improve a width-focused design.
- **low_dropout_noaug**: the baseline-style model with dropout reduced from 0.5 to 0.2, without augmentation. Its main feature was weaker regularization.
- **low_dropout_aug**: the low-dropout version with augmentation. This tested whether lighter dropout and more diverse data could work well together.
- **high_dropout_noaug**: the baseline-style model with dropout increased to 0.6, without augmentation. Its main feature was stronger regularization.
- **high_dropout_aug**: the high-dropout version with augmentation. This tested whether strong regularization plus augmentation would improve generalization or become too restrictive.
- **low_lr_noaug**: a model with learning rate reduced further to 1e-4 and batch size 256, without augmentation. This emphasized very slow, stable optimization.
- **low_lr_aug**: the same 1e-4 learning-rate setting with augmentation. This tested whether a very small learning rate and augmentation could still converge well.

"So the experiment names are quite literal: the first part describes the architecture or training change, and the suffix tells us whether augmentation was used.
This makes it easier to compare not only which model performed best, but also why it performed that way."

### Key Test Results (Approx.)
- **Best CNN (deep_small_filters_aug)**: about **0.78**
- **Baseline + augmentation**: about **0.67**
- **Baseline (no augmentation)**: about **0.70**
- **Poorly tuned larger/wider settings**: about **0.13-0.19**

"The strongest result came from the deeper small-filter model with augmentation.
This suggests that adding depth in a controlled way was more effective than simply increasing width or batch size."

### CNN vs FCNN
"Compared with the FCNN from Chapter 3, CNN performs better overall.
Depending on the FCNN baseline, the best CNN is typically around **5-20 percentage points** higher."

"Even the more ordinary CNN settings were competitive, while the best CNN clearly showed the advantage of convolution-based feature extraction on image data."

### Why CNN Wins
- **CNNs keep spatial information**, while FCNNs flatten the image too early.
- **Convolution layers learn useful local patterns** like edges, textures, and shapes.
- **This makes CNNs more efficient and more suitable for image classification.**

"In other words, CNNs are designed for images, so they can learn structure that FCNNs usually miss or represent less efficiently."

---

## Part 3: Feature Map Interpretation
"To understand what the network learns internally, I extracted intermediate convolution outputs and visualized feature maps for a test image."

### Layer-wise Interpretation
- **Early layers**: detect low-level cues such as edges, color blobs, and simple textures.
- **Middle layers**: combine primitives into richer textures and local motifs.
- **Deep layers**: respond to larger receptive fields and object-part patterns with sparser activations.

"In short, the representation evolves from local visual primitives to class-relevant semantic structure."

"This is important because it shows that the CNN is not memorizing raw pixels.
Instead, it is transforming the input step by step into more meaningful internal representations."

### Why This Helps Classification
- The model can separate classes using progressively more abstract and discriminative features.
- It becomes less sensitive to small local noise and more sensitive to meaningful object structure.

"That is why feature map visualization is useful: it gives an interpretable view of how the model builds its decision process."

---

## Part 4: Impact of Data Augmentation
"I applied online augmentation using RandomFlip, RandomRotation, and RandomZoom during training."

### Practical Impact
- In the best setting, augmentation helped the model reach about **0.78**.
- But augmentation did **not** improve every configuration.
- This means augmentation is useful, but it still depends on the model design and hyperparameters.

"So augmentation should be understood as a helpful training strategy, not as a guaranteed improvement in every experiment."

### Interpretation
- Augmentation increases sample diversity without collecting new data.
- It reduces overfitting by exposing the model to transformed views.
- It improves invariance to orientation/position/scale changes.

"So my conclusion is that augmentation is helpful, but it works best when the model structure is already reasonable."

"In this chapter, the best overall result came from combining a stronger architecture with augmentation, rather than relying on augmentation alone."

---

## Reflection and Next Steps
"To summarize Chapter 6:
1) CNN clearly outperformed FCNN on image classification.
2) Training curves showed clear differences between good and poor hyperparameter settings.
3) Feature maps validated the hierarchical learning hypothesis.
4) Data augmentation helped the best model most clearly, but not every run improved."

"For future improvement, I plan to:
- add stronger regularization tuning (dropout + weight decay),
- use more efficient architectures with global average pooling,
- and perform more systematic hyperparameter search with smaller, better-chosen batch sizes."

"Thank you, Professor. This concludes my Chapter 6 presentation."