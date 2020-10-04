---
layout: post
title: "Complexity"
permalink: /theory/complexity
index: true
---
{% include start-row.html %}

**Notation**:
- Consider an algorithm $$A(x)$$.
- Let $$c(x)$$ be the cost (in number of operations) of the studied algorithm for input $$x$$.
- Let $$f(n_x)$$ be a cost expression over $$n_x$$ ($$x$$ input characteristics such as dimensionality).

## Time

#### Big O, $$O$$:
Upper bound of the algorithm cost.

\begin{equation}
A \space \textrm{is} \space O(f(n)) \iff \exists M \in \mathbb{R}_{>0} \mid c(x) < M \cdot f(n_x) \space \forall x
\end{equation}

#### Big Omega, $$\Omega$$:
Lower bound of the algorithm cost.

\begin{equation}
A \space \textrm{is} \space \Omega(f(n)) \iff \exists M \in \mathbb{R}_{>0} \mid M \cdot f(n_x) < c(x) \space \forall x
\end{equation}

#### Big theta, $$\Theta$$:
{% include end-row.html %}
{% include start-row.html %}

Tight bound. If the algorithm is both $$O(f(n))$$ and $$\Omega(f(n))$$

{% include annotation.html %}

Giving upper or lower bounds is not very helpful unless they are tight to real performance.
E.g. saying that an $$O(n)$$ algorithm is a O(n!) is not very informative.

{% include end-row.html %}
{% include start-row.html %}

In practice people refer to $$O(\cdot)$$ as the tightest upper bound.

#### Best/Worst/Expected Cases
{% include end-row.html %}
{% include start-row.html %}

Best/Worst/Expected case provides information on the cost of the algorithm for **particular inputs**.
They are expressed in terms of $$O(\cdot)$$ or $$\Theta (\cdot)$$.

{% include annotation.html %}
The best case is usually omitted (any algorithm can get lucky and perform something fast).

{% include end-row.html %}
{% include start-row.html %}

There is **no relationship** between O/Omega/Theta and Best/Worst/Expected.
The first describe bounds for the runtime, the second, time for particular inputs or scenarios.

{% include end-row.html %}
{% include start-row.html %}

- When you say **best case** runs in $$O(n log(n))$$ you mean that:
for some input, the run time upper bound will be $$n log(n)$$ i.e. it will run faster than $$n log(n)$$.

- When you say **worst case** runs in $$O(n^2)$$, you mean that the input conditions which make the algorithm slower will make the algorithm upper bound to be $$n^2$$.

## Space
Same as time.

**Remember**: Stack calls also take space.
A recursive function which calls itself once per call will take O(n) time and O(n) space.

## Amortized time

When dynamically-sized arrays (e.g. ```std::vector```) run out of space, usually allocate $$2\cdot n$$ positions their current size and copy the previous $$n$$ entries to the new memory block.
This method takes $$n$$ operations, but in average can be considered an $$O(1)$$ operation:

Image you start with an empty container and try to allocate $$M$$ values (assume $$M = 2^m$$ for simplicity).
The number of copies you'll need to do to have a container of $$M = 2^m$$ elements is:

\begin{equation}
1 + 2 + ... + 2^m = \frac{2^{m+1} - 1}{2 - 1} = 2 \cdot 2^m -1 = O(M)
\end{equation}

Where I used the geometric sum formula.
This principle is known as **amortized time**.

{% include end-row.html %}
