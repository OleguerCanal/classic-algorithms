# Competitive programming guide
This is just a list of random thoughts I have while approaching competitive programming problems.

## Problem walkthrough

1. Think of harder examples than the ones presented! Usually they hide the tricky stuff!
2. Think of the most obvious (inefficient) way to solve the problem. Think its complexity. This is just to make sure you understand the problem.
3. Think of optimizations. What is the **best data structure**? Think time/space tradeoffs.
4. Implement it. As modular as possible!
5. Take care of special cases. Empty vector/ small numbers and stuff like that.

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
    - Indexes traversing at different speeds (e.g split linked list into 2 halves, one index at speed 1, the other at speed 2)
    - Indexes traversing with a certain offset (e.g. linked list remove n from end with a single pass, you run 2 indices with n of difference)

## List tricks

- **Dummy head**: Sometimes when deleting a node you have to delete the first node of the list. In this case it helps to add a **dummy** node s.t. dummy->next = head, do all operations using his dummy as a new head and then return dummy->next;
