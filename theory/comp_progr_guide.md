# Competitive programming guide
This is just a list of random thoughts I have while approaching competitive programming problems.

## Problem walkthrough

1. Think of harder examples than the ones presented! Usually they hide the tricky stuff!
2. Think of the most obvious (inefficient) way to solve the problem. Think its complexity. This is just to make sure you understand the problem.
3. Think of optimizations. What is the **best data structure**? Think time/space tradeoffs.
4. Implement it. As modular as possible!
5. Take care of special cases. Empty vector/ small numbers and stuff like that.,

## Common tricks

### The right data structure is key!
- **Hash tables** ftw.

### Indexes problems:
- Can it be done with a **single index**?
    - Single path storing key info (e.g. stock problem)
    - Single path modifying array (e.g calculating accumulated differences)
    - Dynamic programming: Traverse backwards storing key information. (e.g. number of jumps problem)

- Can it be done with **multiple indexes**?
    - Begin/End indexes
    - Indexes traversing at different speeds