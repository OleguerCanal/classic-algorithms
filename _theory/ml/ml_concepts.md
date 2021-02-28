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

## Evaluation Methods

Loss functions

Corss-validation

Precision/Recall
Error Types
ROC

## Ensemble Methods

{% include end-row.html %}
