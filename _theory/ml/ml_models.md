---
layout: post
title: "Machine Learning Models"
permalink: /theory/ml_models
index: true
---
{% include start-row.html %}

## Basic concepts

- [Discriminative vs Generative](https://campusai.github.io/ml/generative_models): Discriminative models learn to map inputs and labels while generative models learn the underlying distribution of the data. This allows us to perform density estimation, sampling, infer latent vars...

{% include end-row.html %}
{% include start-row.html %}

- **Bias-variance tradeoff**:
  - **Bias** is introduced by our choices on the model's functional form. Wrong (or too-simple) assumptions often lead to under-fitting.
  - **Variance** error is the opposite
  - An example of high-variance low-bias models are **decision trees**: They don't do any assumption on the data structure. Usually its high variance is reduced through variance-reduction ensemble methods such as **Bagging** (further improved by **Random Forests**, where not only subsets of data are used but also subsets of features).

{% include annotation.html %}
**Bias error example**: If you choose a linear model to capture non-linear relations, doesnt matter how much data you use to train, it will never work well.

{% include end-row.html %}
{% include start-row.html %}


## Ensemble Methods

{% include end-row.html %}
