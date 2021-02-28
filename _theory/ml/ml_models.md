---
layout: post
title: "Basic Machine Learning Models"
permalink: /theory/ml_models
index: true
---
{% include start-row.html %}

## Supervised Learning

#### k-Nearest Neighbor (kNN)

{% include end-row.html %}
{% include start-row.html %}

Given a labelled dataset, each time we want to estimate the label of a new point, we get the label from the $$k$$-closest points in the dataset and guess its label based on that information.

{% include annotation.html %}
It is a good idea to choose a $$k$$ different than the number of classes to avoid draws.
{% include end-row.html %}
{% include start-row.html %}

**Pos/Cons:**
- <span style="color:green">Simplicity.</span>
- <span style="color:red">If the dataset is very big, it can be slow to find closest point.</span>

**Characteristics:** `discriminative`, `non-parametric`

#### Decision Trees

The idea is to build a tree where each node is a condition and its branches the possible outcomes.
These conditions are chosen iteratively granting a **higher information gain**, or, equivalently, the split of data which results in the **lowest possible entropy entropy** state.

**Pos/Cons:**
- <span style="color:green">Intuitive and interpretable.</span>
- <span style="color:green">No need to pre-process the data.</span>
- <span style="color:green">No bias (no previous assumptions on the model are made)</span>
- <span style="color:red">High variance (results entirely depend on training data).</span>

This high-variance issue is often addressed with variance-reduction ensemble methods.
As a matter of fact, there is a technique specially tailored to them called **random forest**:
A set of different trees are trained with different subsets of **data** (similar idea to **bagging**), and also different subsets of **features**.

Despite their simplicity, they are very effective models.
They often win [Kaggle](https://www.kaggle.com/) contests.

**Characteristics:** `discriminative`

#### Naive Bayes

{% include end-row.html %}
{% include start-row.html %}

Given a dataset of $$n$$ labelled points in a $$d$$-dim space: $$\mathcal{D} = {(\vec{x_1}, c_1), ..., (\vec{x_n}, c_n)}$$.
A naive Bayes classifier approximates the probability of each class of a new point $$\vec{x} = (x^1, ..., x^d)$$ assuming independence on its features:

\begin{equation}
p(\vec{x}) = p(x^1, ..., x^d) \simeq p(x^1) ... p(x^d)
\end{equation}

By applying the Bayes theorem:

\begin{equation}
p(c_i \mid \vec{x}) = \frac{p(\vec{x} \mid c_i) p(c_i)}{p(\vec{x})} \simeq \frac{p(x^1 \mid c_i) ... p(x^d \mid c_i) p(c_i)}{p(x^1)...p(x^d)}
\end{equation}

We can then estimate:
-  $$p(x^j \mid c_i)$$ as the ratio of times $$x^j$$ appears with and without $$c_i$$ in the dataset.
-  $$p(c_i)$$ as the ratio of points classified as $$c^i$$ in the dataset.


Notice that we don't actually need to compute the **evidence** (denominator) as it only acts as a normalization factor of the probabilities.
It is constant throughout all classes.

**Pos/Cons:**
- <span style="color:green">Simplicity, easy implementation, speed...</span>
- <span style="color:green">Works well in high dimensions.</span>
- <span style="color:red">Features in real world are not independent.</span>

**Characteristics:** `generative`, `non-parametric`

{% include annotation.html %}
**Naive** because it assumes independence between features.
{% include end-row.html %}
{% include start-row.html %}

#### Support Vector Machines (SVMs)

SVM solves a (n-dimensional) linear **binary classification** problem by finding the hyperplane which "better" splits the data.
It frames it as a **convex** optimization problem with the objective of finding the largest margin within the two sets of points.
A set of points is chosen from each group to optimize the hyperplane position, these points are known as **support vectors**.

- **Maximum Margin Classifier** attempts to find a "hard" boundary between the two data groups. It is however very susceptible to training outliers (high-variance problem).

- **Soft Margin** approach allows for the miss-classification of points, it is more biased but better performing.
Often cross-validation is used to select the support vectors which yield better results.

##### Kernel and kernel trick
Oftentimes, the data is not linearly-separable.
We can apply a non-linear transformation into a (possibly higher-dimensional) space and perform the linear separation there.
We call this non-linear transformation **kernel**.

**Kernel trick**: One can frame the problem in such a way that the only information needed is the dot product between points.
For some kernels we can calculate the dot product of the transformation of two points without actually needing to transform them, which makes the overall computation much more efficient.
We already saw this idea in [dimensionality reduction algorithms](https://campusai.github.io/ds/dim_reduction_algos).

**Pos/Cons:**
- <span style="color:green">Works well on high-dim spaces.</span>
- <span style="color:green">Works well with small datasets.</span>
- <span style="color:red">Need to choose a kernel.</span>

#### Linear Regression

We use **least squares** to learn the subspace which better fits the data

Ridge regression

Lasso regression

#### Logistic Regression

In a binary classification problem, logistic regression learns the probability of both class based on their features.
It does so by assuming (a usually simple) functional form and fit its parameters through **maximum likelihood**.



## Unsupervised Learning


### Clustering

#### k-means

#### Expectation Maximization



{% include end-row.html %}
