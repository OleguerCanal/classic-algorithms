---
layout: post
title: "Basic Machine Learning Concepts"
permalink: /theory/ml_concepts
index: true
---
{% include start-row.html %}

**Machine Learning** studies algorithms which improve their performance through data: The more data they process, the better they will perform.

## Basics

{% include end-row.html %}
{% include start-row.html %}
- **Paradigms of Machine Leaning**:
  - **Supervised**: Provided inputs and expected outputs it learns a mapping between them. Used for regression and classification.
  - **Unsupervised**: Learns patters in unstructured data: clustering, dim-reduction, learn distributions...
  <!-- - **Semi-supervised**: Only a subset of the data is labelled. How can we leverage this situation? -->
  - **Reinforcement**: Deals with decision-making problems.

{% include annotation.html %}
- Supervised learning is **predictive**
- Unsupervised learning is **descriptive**
{% include end-row.html %}
{% include start-row.html %}


- [Discriminative vs Generative](https://campusai.github.io/ml/generative_models):
  - **Discriminative models** learn to map inputs and labels.
  - **Generative models** learn the underlying distribution of the data. This allows us to perform density estimation, sampling, infer latent vars... Often used in **unsupervised learning** applications.

{% include end-row.html %}
{% include start-row.html %}

- **Bias-variance tradeoff**:
  - **Bias** is introduced by our choices on the model's functional form. Wrong (or too-simple) assumptions often lead to under-fitting.
  - **Variance** error is the opposite: it appears when the model is too susceptible to the data. For instance, over-parametrized models tend to over-fit to the training data and perform poorly on test data.
  

{% include annotation.html %}
- **Bias error example**: If you choose a linear model to capture non-linear relations, doesnt matter how much data you use to train, it will never fit it well.

- **Variance error example**: Decision trees are high-variance low-bias models, as they don't do any assumption on the data structure. Usually its high variance is reduced through variance-reduction ensemble methods such as **Bagging** (further improved by **Random Forests**, where not only subsets of data are used but also subsets of features).
{% include end-row.html %}
{% include start-row.html %}

## Error Measures

Loss functions

Corss-validation

### Binary Confusion Matrix

- **Type I Error**: False Positive (Model guessed + but was -).
- **Type II Error**: False Negative (Model guessed - but was +).
- **Accuracy**:  $$\frac{\text{TP} + \text{TN}}{\text{TOTAL}}$$. Overall, what proportion did the model correctly guess.
- **Precision**: $$\frac{\text{TP}}{\text{TP} + \text{I}}$$. From the ones, you said were +, what proportion did you correctly guess.
- **Recall** $$\frac{\text{TP}}{\text{TP} + \text{II}}$$. From the ones that were +, how many did you correctly guess. (aka *true positive rate (TPR)*)
- **Specificity** $$\frac{\text{TN}}{\text{TN} + \text{I}}$$. From the ones that were -, how many did you correctly guess.

**Receiving Operating Characteristic ROC**

Compares model **Recall** vs **FPR** (1 - Specificity) obtained with the studied model when varying a parameter.

- **AUC** Measures how good is the model at distinguishing the classes. Higher AUG means higher **RECALL** and higher **SPECIFICITY**: Which means it is better at predicting positives as positives and negatives as negatives.

## Ensemble Methods

**IDEA**: Combine multiple weak learners to improve results.

Techniques:

- **Mode**: Simple voting mechanism. Take what the majority of learners say

- **Average** / **Weighted Average**: Assign a weight to each learner and compute the mean prediction.

- **BAGGING (Bootstrap AGGregatING)** : Multiple models of the same type are trained with a random subset of the data sampled with replacement (**bootstrapping**). This technique is specially effective to **reduce variance**.

- **BOOSTING**: Each datapoint is given an "*importance weight*" which is adjusted during the **sequential** training of multiple models. In addition, a "*reliability weight*" is assigned to each model and weighted average is used for the final guess. Although it also lowers the variance, it is mainly used to **lower the bias** of the models.
  - **ADABOOST**: After model $$i$$ is trained, the weights associated with each datapoint are adjusted giving more importance to the ones that presented a worse performance.
  - **Gradient Boosting**: Instead of changing the weight of each misclassification, fits 

{% include end-row.html %}
