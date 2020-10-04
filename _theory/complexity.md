---
layout: page
title: "Complexity"
permalink: /theory/complexity
index: true
---

## Time

- **O**: (big O) Upper bound. The algorithms runs under O(.)
- **\Omega**: (big omega) Lower bound. The algorithm runs faster than O(.)
- **\Theta**: (big theta) Tight bound. If the algorithm is both O(.) and \Omega(.)

Giving upper or lower bounds is not very helpful unless they are tight to real performance.
E.g. saying that an algorithm which runs in linear has a O(n!) is not very informative.

That is why we split performance into **best**, **worst** and **expected** cases.
In this case, the best case is usually omitted (any algorithm can get lucky and perform something fast), the important metrics are the worst and expected cases.

**OBS**:
There is no relationship between O/Omega/Theta and Best/Worst/Expected.
The first describe bounds for the runtime, the second, time for particular inputs or scenarios.

- When you say **best case** it runs in O(n log(n)) you mean that:
for some input, the run time upper bound will be n log(n) i.e. it will run faster than n log(n).

- When you say **worst case** it runs in O(n^2), you mean that the input conditions which makes it slower will make the algorithm upper bound to be n^2.

## Space

Same as time.

**OBS**: Stack calls also take space. A recursive function which calls itself once per call will take O(n) time and O(n) space.