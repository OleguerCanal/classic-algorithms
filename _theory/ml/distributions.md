---
layout: post
title: "Probability distributions"
permalink: /theory/distributions
index: true
---
{% include start-row.html %}

- **Random variable**: Mapping between outcomes and real values that ease the probability calculus.
  
- **Independence**: The occurrence of an outcome $$A_1$$ variable doesnt affect the other $$A_2$$: $$p(A_1 \cap A_2) = p(A_1) p(A_2)$$

- **Probability distro**: Function that provides occurrence probability of possible outcomes. Can be Discrete/Continuous.
    - **PMF** (Probability Mass Function): Probability of each point in a discrete R.V.
    - **PDF** (Probability Density Function): Likelihood of each point in a continuous R.V. Or probability spread over area.

- **Expectation**:
  - In discrete r.v.: $$E [X] = \sum p(x) x$$ 
  - In continuous r.v.: $$E [X] = \int p(x) x $$ 

- **Variance**: Expectation of the squared deviation of a r.v.

## Maximum likelihood estimation

{% include end-row.html %}
{% include start-row.html %}

MLE finds the parameters which better explain the data.
I.e. which achieve a higher likelihood on the distribution assumed (through expert knowledge or distribution tests):

\begin{equation}
\theta^\star = \arg \max_\theta (\mathcal{L} (\mathcal{D}, \theta))
\end{equation}

{% include annotation.html %}
In some cases (see [Deep Generative Models](https://campusai.github.io/ml/generative_models)) the assumed functional form of the likelihood is so complex that this optimization cannot be done analytically.
We then use other optimization techniques (s.a. stochastic gradient ascent to optimize the likelihood).
{% include end-row.html %}
{% include start-row.html %}


## Famous distributions

### Discrete

#### Bernoulli

Toss of a coin with probability of head of $$\lambda \in [0, 1]$$.

\begin{equation}
X \in \{0, 1\}
\end{equation}


\begin{equation}
p(X = x) =
\begin{cases}
\lambda & \textrm{if} x = 1 \newline
1-\lambda & \textrm{if} x = 0
\end{cases}
\end{equation}

$$E [X] = \lambda \cdot 1 + (1 - \lambda) \cdot 0 = \lambda$$

$$V [X] = E [(X - E (X))^2]$$ = 

#### Categorical

Toss of a dice with $$k$$ faces and probabilities $$\lambda_1, ..., \lambda_k$$.
Where $$\sum_i \lambda_i = 1$$, and $$\lambda_i \in [0, 1] \forall i$$.

\begin{equation}
X \in \{1:k\}
\end{equation}


\begin{equation}
p(X=x) =
\begin{cases}
\lambda_1 & \textrm{if} x = 1 \newline
\lambda_2 & \textrm{if} x = 2 \newline
...
\end{cases}
\end{equation}

**Categorical Cross-Entropy** is often used as a Loss function for ML models.
Remember that the cross-entropy between the data distribution and the approximate one is:

$$\mathcal{H} (P, Q) = E_P [I_Q] = - \sum p(P=p_i) \log (Q = p_i) = - \sum \lambda_i \log (\hat \lambda_i)$$

Usually for classification tasks $$\lambda_i$$ is a hard label, so the loss associated with a datapoint becomes $$- \log (\hat \lambda_i)$$ (negative log of the guessed prob).
Remember that the cross-entropy is usually used when the data information is fixed, thus KL divergence $$D_{KL} (P \Vert Q) = E_P [I_Q - I_P]$$ is a simple translation of $$\mathcal{H} (P, Q)$$.

#### Binomial

{% include end-row.html %}
{% include start-row.html %}

Number of successes in $$n$$ Bernoullies (with mean $$\lambda \in [0, 1]$$).

\begin{equation}
X \in \{1:n\}
\end{equation}


\begin{equation}
p(X=x) = {N \choose x} \lambda^x (1 - \lambda)^{n - x}
\end{equation}

{% include annotation.html %}
For large $$n$$ and $$\lambda \simeq \frac{1}{2}$$ it behaves as a *discretization* of the normal distribution.
{% include end-row.html %}
{% include start-row.html %}

#### Multinomial

{% include end-row.html %}
{% include start-row.html %}

It models the number of counts of a k-sided die rolled n times.
I.e. $$x_i$$ counts the number of times side $$i$$ appeared when rolling the dice $$n$$ times, thus:

\begin{equation}
x_{i \in 1:k} \in \{0:n\}
\end{equation}

Where: $$\sum_{i=1}^k x_i = n$$

\begin{equation}
p(X=\{x_1, ..., x_k\}) = {N \choose {x_1, ..., x_k}} \lambda_1^{x_1} ... \lambda_k^{x_k}
\end{equation}

Notice this is a generalization of binomial distribution for categorical variables.

{% include annotation.html %}
For large $$n$$ and $$\lambda \simeq \frac{1}{2}$$ it behaves as a *discretization* of the normal distribution.
{% include end-row.html %}
{% include start-row.html %}

#### Geometric

Counts the number of failures before the first success in a Bernoulli r.v.

\begin{equation}
x \in \mathbb{N}
\end{equation}

\begin{equation}
p(X = x) = (1 - \lambda)^{x-1} \lambda
\end{equation}

#### Poison

Counts the number of random independent events happening in a fixed period of time (or space).
Imagine that on average $$\lambda \in \mathbb{R}_{[0, 1]}$$ events happen within a time period, then we can get the probability of $$x$$ events happening by evaluating the Poisson distribution.

\begin{equation}
x \in \mathbb{N}
\end{equation}

\begin{equation}
p(X = x) = \frac{\lambda^x e^{- \lambda}}{x!}
\end{equation}

### Continuous

#### Uniform

Assigns same likelihood to all values between a range.

\begin{equation}
x \in [a, b]
\end{equation}

\begin{equation}
PDF(x) = \frac{1}{b-a}
\end{equation}

- Is the distribution which gives the **highest entropy** for $$x \in [a, b]$$ 


**MLE**: Given a dataset $$\mathcal{D} = \{ x_i \}_{i=1:n}$$ the MLE estimation of its parameters: $$a, b$$ is: $$a = \min_i {x_i}, b = \max_i {x_i}$$. We can easily see it be expressing the likelihood of the dataset:

\begin{equation}
\mathcal{L (\mathcal{D}, a, b)} = \frac{1}{b - a}^n
\end{equation}

If we want to maximize the likelihood we need to minimize $$b - a$$ but $$x_i \in [a, b] \forall i$$.
Thus, the minimum is achieved when we take b as the maximum and a as the minimum.

#### Gaussian/Normal

\begin{equation}
x \in \mathbb{R}
\end{equation}

\begin{equation}
PDF(x) = \frac{1}{\sqrt{2 \pi \sigma^2}} e^{- \frac{1}{2} \frac{(x - \mu)^2}{\sigma^2}}
\end{equation}

- Is the distribution which gives the **highest entropy** for a fixed variance $$\sigma^2$$ for $$x \in \mathbb{R}$$.
- A lot of events in nature seem to follow a normal distribution.
- The sum of normal r.v.'s is normal

**Central limit theorem**: The sum of independent samples from any distribution tends to follow a normal distribution (as the number of samples grows).

#### Log-Normal

$$X$$ follows a log-normal distribution if $$\log (X)$$ follows a normal distribution.

{% include end-row.html %}
