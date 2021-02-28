---
layout: post
title: "Basic Machine Learning Models"
permalink: /theory/ml_models
index: true
---
{% include start-row.html %}

## Supervised Learning

### k-Nearest Neighbor (kNN)

**Solves**: Classification, Regression

{% include end-row.html %}
{% include start-row.html %}

**Method**: kNN estimates new point labels by aggregating the labels of the $$k$$-closest points in the dataset.

{% include annotation.html %}
It is a good idea to choose a $$k$$ different than the number of classes to avoid draws.
{% include end-row.html %}
{% include start-row.html %}

**Pos/Cons:**
- <span style="color:green">Simplicity.</span>
- <span style="color:red">If the dataset is very big, it can be slow to find closest point.</span>

**Characteristics:** `discriminative`, `non-parametric`

### Decision Trees

**Solves**: Classification, Regression

**Method**: Learn decision rules based on the data features.
These decisions are encoded by a tree where each node represents condition and its branches the possible outcomes.
The conditions are chosen iteratively granting a **higher information gain** (the split of data which results in the **lowest possible entropy entropy** state).

{% include end-row.html %}
{% include start-row.html %}

**Pos/Cons:**
- <span style="color:green">Intuitive and interpretable.</span>
- <span style="color:green">No need to pre-process the data.</span>
- <span style="color:green">No bias (no previous assumptions on the model are made)</span>
- <span style="color:green">Very effective, often used in winning solution in [Kaggle](https://www.kaggle.com/)</span>
- <span style="color:red">High variance (results entirely depend on training data).</span>

{% include annotation.html %}
This high-variance issue is often addressed with variance-reduction ensemble methods.
As a matter of fact, there is a technique specially tailored to them called **random forest**:
A set of different trees are trained with different subsets of **data** (similar idea to **bagging**), and also different subsets of **features**.
{% include end-row.html %}
{% include start-row.html %}

**Characteristics:** `discriminative`

### Naive Bayes

**Solves**: Classification

{% include end-row.html %}
{% include start-row.html %}

**Method**: Given a dataset of labelled points in a $$d$$-dim space a naive Bayes classifier approximates the probability of each class of a new point $$\vec{x} = (x^1, ..., x^d)$$ assuming independence on its features:

{% include annotation.html %}
**Naive** because it assumes independence between features.
{% include end-row.html %}
{% include start-row.html %}

\begin{equation}
p(\vec{x}) = p(x^1, ..., x^d) \simeq p(x^1) ... p(x^d)
\end{equation}

{% include end-row.html %}
{% include start-row.html %}

By applying the Bayes theorem:

\begin{equation}
p(c_i \mid \vec{x}) = \frac{p(\vec{x} \mid c_i) p(c_i)}{p(\vec{x})} \simeq \frac{p(x^1 \mid c_i) ... p(x^d \mid c_i) p(c_i)}{p(x^1)...p(x^d)}
\end{equation}

We can then estimate:
-  $$p(x^j \mid c_i)$$ as the ratio of times $$x^j$$ appears with and without $$c_i$$ in the dataset.
-  $$p(c_i)$$ as the ratio of points classified as $$c^i$$ in the dataset.

{% include annotation.html %}
Notice that we don't actually need to compute the **evidence** (denominator) as it only acts as a normalization factor of the probabilities.
It is constant throughout all classes.
{% include end-row.html %}
{% include start-row.html %}

**Pos/Cons:**
- <span style="color:green">Simplicity, easy implementation, speed...</span>
- <span style="color:green">Works well in high dimensions.</span>
- <span style="color:red">Features in real world are not independent.</span>

**Characteristics:** `generative`, `non-parametric`

### Support Vector Machines (SVMs)

**Solves**: Binary classification

**Method**: Learn the hyperplane parameters which "better" split the data.
It frames it as a **convex** optimization problem with the objective of finding the largest margin within the two classes of points.
A set of points is chosen from each group to optimize the hyperplane position, these points are known as **support vectors**.

- **Maximum Margin Classifier** attempts to find a "hard" boundary between the two data groups. It is however very susceptible to training outliers (high-variance problem).

- **Soft Margin** approach allows for the miss-classification of points, it is more biased but better performing.
Often cross-validation is used to select the support vectors which yield better results.

Schematically, SVM has this form:

\begin{equation}
\vec{x} \rightarrow  \text{Linear function} < \vec{x}, \vec{w} > \rightarrow
\begin{cases}
if \geq 1 \rightarrow \text{class 1} \newline
if \leq -1 \rightarrow  \text{class -1}
\end{cases}
\end{equation}

##### Kernel
{% include end-row.html %}
{% include start-row.html %}
Often, the data is not linearly-separable.
We can apply a non-linear transformation into a (possibly higher-dimensional) space and perform the linear separation there.
We call this non-linear transformation **kernel**.

**Pos/Cons:**
- <span style="color:green">Works well on high-dim spaces.</span>
- <span style="color:green">Works well with small datasets.</span>
- <span style="color:red">Need to choose a kernel.</span>

{% include annotation.html %}
**Kernel trick**: One can frame the problem in such a way that the only information needed is the dot product between points.
For some kernels we can calculate the dot product of the transformation of two points without actually needing to transform them, which makes the overall computation much more efficient.
We already saw this idea in [dimensionality reduction algorithms](https://campusai.github.io/ds/dim_reduction_algos).
{% include end-row.html %}
{% include start-row.html %}

**Characteristics:** `discriminative`

### Logistic Regression

**Solves**: Binary classification

**Method**: The model has two steps:
1. Apply a linear function to the input $$\vec{x}$$ (parametrized as $$\vec{w}$$).
2. Apply a sigmoid function to this output: $$f(x) = \frac{e^x}{e^x + 1}$$.

In summary, logistic regression assumes the following functional form:

\begin{equation}
\hat p (\vec{x}) = \frac{e^{< \vec{w}, \vec{x} >}}{e^{< \vec{w}, \vec{x} >} + 1}
\end{equation}

And uses **maximum likelihood estimation (MLE)** to learn the parameters $$\vec{w}$$. Notice its similarity with **SVMs**:

{% include end-row.html %}
{% include start-row.html %}

\begin{equation}
\vec{x} \rightarrow  \text{Linear function} < \vec{x}, \vec{w} > \rightarrow \text{SIGMOID} \rightarrow 
\begin{cases}
if \geq 0.5 \rightarrow \text{class 1} \newline
if \leq 0.5 \rightarrow  \text{class 0}
\end{cases}
\end{equation}

{% include annotation.html %}
We can also think of this as a single-neuron ANN with a SIGMOID activation function.
{% include end-row.html %}
{% include start-row.html %}

We therefore find the parameters $$w$$ through MLE.

**Pos/Cons:**
- <span style="color:green">Simplicity.</span>
- <span style="color:red">Susceptible to outliers.</span>
- <span style="color:red">Negatively affected by high correlations in predictors.</span>
- <span style="color:red">Limited to linear boundaries.</span>
- <span style="color:red">Generalized and easily outperformed by ANNs.</span>

**Characteristics:** `discriminative`

### Linear Regression

**Solves**: Regression

**Method**: Learn parameters of a linear transformation using **least squares**

Ridge regression

Lasso regression

**Pos/Cons:**
- <span style="color:green">Works well with small datasets.</span>
- <span style="color:red">Susceptible to outliers, high correlations in predictors.</span>

**Characteristics:** `discriminative`


## Unsupervised Learning


### Clustering

### k-means

**Method**: Randomly place $$k$$ centroids and iteratively move them so they 

**Pos/Cons:**
- <span style="color:green"></span>
- <span style="color:red">Number of clusters need to be pre-set</span>
- <span style="color:red">Isotropic clusters</span>


### Expectation Maximization



{% include end-row.html %}
