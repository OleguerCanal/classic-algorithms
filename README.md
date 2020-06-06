# Classic Algorithms
Data structures and common algorithms playground. As well as some theory notes.
As always more an exercice for me to think their implementation rather than anything useful.

## Theory

- [Memory Management in C++](theory/memory_management.md)
- LeetCode-like problems approach guide

## Array Sorting:

- [Bubble Sort](sorting/bubble_sort.cpp) (Serial)
- Odd-Even Sort (Parallel)
- Merge Sort (Parallel)
- Heap Sort (Serial)
- Quick Sort (Serial)

## Tree Traversal:

### Recursive
- [Pre-order DFS](tree_traversal/recursive_tree_traversal.cpp)
- [In-order DFS](tree_traversal/recursive_tree_traversal.cpp)
- [Post-order DFS](tree_traversal/recursive_tree_traversal.cpp)

### Iterative
- [Pre-order DFS](tree_traversal/iterative_tree_traversal.cpp)
- [In-order DFS](tree_traversal/iterative_tree_traversal.cpp)
- Post-order DFS
- [BFS](tree_traversal/iterative_tree_traversal.cpp)

## Graph Search:

### Uninformed:

- BFS (Breath First Search)
- DFS (Depth First Search)

### Informed:

- Greedy (Expand lowest heuristic node)
- Dijkstra (Expand lowest acquisition_cost node)
- A* (Expand lowest heuristic + acquisition_cost node)

## Metaheuristics:

- Genetic algorithm
- Simulated Annealing
- Ant Colony
- Tabu Search

## Data Structures

- [BT](include/binnary_tree.hpp) (Binnary Tree)
- BST (Binnary Search Tree)
- [Graph](include/graph.hpp)


# To run an algorithm:

`./run.sh path_to_cpp_file`