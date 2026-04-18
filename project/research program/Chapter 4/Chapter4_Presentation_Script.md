# Presentation Script: Chapter 4 - Optimization & Theory

## Introduction
"Good afternoon, Professor. 
Starting from where we left off, I have focused on **optimizing the model** by adjusting hyperparameters and addressing overfitting. I have also prepared the theoretical answers regarding loss functions and training dynamics."

---

## Part 1: Hyperparameter Experiments & Reflection
"First, I conducted experiments to find the best configuration by focusing on key **Hyperparameters**. To formally define them:
- **Hyperparameter**: High-level structural settings essentially acting as the "control knobs" of the model (e.g., learning rate, network depth, batch size). These are configured *manually before training begins* and govern how the model learns, rather than being learned from the data itself.
- **Parameter**: Internal variables the model learns and updates *automatically* during training (e.g., neuron weights and biases).

**Reflections on Training Dynamics & Tuning:**
During the experiments, I made several key observations regarding how the model learns:
<!-- 1. **Impact of Optimization Step Size**: The learning rate essentially dictates our path to the solution. Pushing it aggressively high (0.1) caused the model to erraticly overshoot the minimum (divergence). Conversely, an excessively tiny rate (0.00001) dragged the progression to a crawl. Discovering that sweet spot (0.001) was crucial for a prompt, stable descent.
2. **Identifying the Memorization Trap**: Tracking the batch sizes and epochs, I noticed training scores climbing endlessly while validation performance hit a brick wall. This widening gap was the textbook definition of **overfitting**—the network was treating random dataset noise as undeniable facts.
3. **Structured Parameter Selection**: I realized that dialing in these settings shouldn't be based on trial-and-error. The proper methodology involves deploying systematic sweeps—like a targeted Grid Search or wide Random Search—and strictly evaluating the resulting validation metrics to isolate the best configuration." -->

Learning Rate — Controls how big each update step is during training. Too high and the model overshoots the optimal solution; too low and it learns painfully slowly.
Batch Size — How many training samples the model sees before updating its weights. Larger batches = smoother but slower updates; smaller batches = noisier but more frequent updates.
Epoch — One complete pass through the entire training dataset. More epochs give the model more chances to learn, but too many can lead to overfitting.

Think of it like studying: learning rate is how much you absorb per session, batch size is how many pages you read before pausing to reflect, and epochs is how many times you re-read the whole book.


Learning Rate is the dominant factor:

LR=0.1 completely fails (~10% accuracy), the learning rate is too large to converge
LR=0.001 performs best (~47% accuracy) with stable, fast convergence
LR=0.00001 learns too slowly and hasn't fully converged by epoch 14

Batch size has minimal impact when LR=0.001 — all three batch sizes (32/64/256) reach similar final accuracy (~46-47%), though smaller batches show more noisy curves.
Best config: LR=0.001, Batch=64 — best balance of speed, stability, and performance. Further gains likely require architectural improvements rather than hyperparameter tuning.

---

## Part 2: Regularization (Curbing Overfitting)
"To bridge that performance gap and stop the network from memorizing, I introduced two distinct constraints. Here is my reflection on why they worked:"

### 1. Structural Disruption (Dropout Layer)
- **Definition**: A regularization technique where randomly selected neurons are temporarily deactivated (ignored or "dropped out") during each step of the training process. 
- **The Approach**: We intentionally 'blindfold' a random portion (e.g., 50%) of the network's nodes during every single update.
- **The Outcome**: Because the model can never guarantee which specific neurons will be available, it prevents individual pathways from dominating or becoming overly dependent on one another. The network learns to distribute its knowledge robustly, allowing it to adapt much better to entirely unseen data.

### 2. Mathematical Penalty (L2 Weight Decay)
- **Definition**: A regularization method that adds a penalty term to the loss function, which is directly proportional to the squared magnitude of the network's weights.
- **The Approach**: This technique fundamentally alters our objective by directly injecting the magnitude of the model's weights into the loss penalty.
- **The Outcome**: It imposes a strict 'complexity budget'. By squashing the weights toward zero, the network's decision boundaries become much smoother. A simpler internal representation inherently stops the model from overreacting to minor outliers in our samples.

**Core Distinction**: Ultimately, Dropout battles overfitting by temporarily and dynamically altering the network's architecture (structure), whereas L2 tackles the issue from a purely mathematical angle by restricted the sheer size of the learned equations (loss function).

---

## Part 3: Theoretical Tasks (Math & Course Explanations)
"Finally, here are the detailed explanations for the specific assigned tasks for today's session:"

### 1. Loss Functions Formulas
- **Mean Squared Error (MSE)**: 
  - $MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$
  - *Explanation*: Measures average squared difference. It's best suited for continuous regression tasks as it penalizes large errors.
- **Cross-Entropy Loss**: 
  - $CE = - \sum_{i=1}^{C} y_i \log(\hat{y}_i)$
  - *Explanation*: Measures differences between probability distributions. The $-\log$ function heavily penalizes models that are "confidently wrong" (predicting near 0% probability for the true class sends the penalty to infinity). Best for classification.

### 2. Optimization Concepts (Andrew Ng Slides)
*[Insert specific course screenshots for Gradient Descent, Binary Cross-Entropy, and Backpropagation]*

- **Gradient Descent**: An optimization algorithm that calculates the gradient (slope) of the loss and takes small steps in the opposite direction to find the lowest possible error.
- **Binary Cross-Entropy Loss**: 
  - Formula: $L = - [ y \cdot \log(\hat{y}) + (1 - y) \cdot \log(1 - \hat{y}) ]$
  - *Intuitive Breakdown*: This formula functions like a switch. When the true label $y=1$, only the first term $-\log(\hat{y})$ is active; when $y=0$, only the second term $-\log(1-\hat{y})$ is active. This mechanism imposes a heavy mathematical penalty when the model is "confidently wrong" (e.g., predicting a near-zero probability for a true event), pushing the model towards correct and confident predictions.
- **Backpropagation**: Calculates the gradient of the loss function. It uses the "chain rule" from calculus to pass error information *backwards* from the output layer to the input layer, telling the model how to adjust its weights.

---

## Conclusion
"By systematically testing hyperparameters and applying structural and mathematical regularizations, I achieved a stable model. I've also detailed the mathematical foundations mapping directly to the specialization course. Thank you."
