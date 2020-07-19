# Algorithmics
Data structures and common algorithms playground. As well as some theory notes.
Only dependencies are STD library and MPI for parallel implementations.
As always more an exercise for me to think their implementation rather than anything useful.

**NOTE**: Some theoretical content and ideas are from [The Cherno](https://www.youtube.com/channel/UCQ-W1KE9EYfdxhL6S4twUNw) YouTube channel.
Likewise, other ideas are from this [book](https://www.amazon.com/Cracking-Coding-Interview-Programming-Questions/dp/0984782850).

More algorithm implementations on my [LeetCode](https://leetcode.com/oleguercanal/)

## Theory

- [Complexity](theory/complexity.md)
- Bit manipulation
- [Pointers](theory/pointers.md)
- [Passing args to functions](theory/func_args.md)
- [Memory Management](theory/memory_management.md)
- Recursion
- Dynamic programming
- [Competitive programming problems approach guide](theory/comp_progr_guide.md)

## Lists

- [Reverse](lists/reverse.cpp)

## Arrays

- [Binary search](search/bin_search.cpp) (& variants)
- [Bubble Sort](sorting/bubble_sort.cpp) (Serial)
- [Heap Sort](sorting/heap_sort.cpp) (Serial)
- Quick Sort (Serial)
- [Merge Sort](sorting/merge_sort_parallel.cpp) (**Parallel**)


## Tree Traversal

### Recursive
- [Pre-order DFS](tree_traversal/recursive_tree_traversal.cpp)
- [In-order DFS](tree_traversal/recursive_tree_traversal.cpp)
- [Post-order DFS](tree_traversal/recursive_tree_traversal.cpp)

### Iterative
- [Pre-order DFS](tree_traversal/iterative_tree_traversal.cpp)
- [In-order DFS](tree_traversal/iterative_tree_traversal.cpp)
- Post-order DFS
- [BFS](tree_traversal/iterative_tree_traversal.cpp)

## Graph Search

### Uninformed:

- BFS (Breath First Search)
- DFS (Depth First Search)

### Informed:

#### Without heuristic:
- Dijkstra (Expand lowest acquisition_cost node)

#### Heuristic available:

- Greedy (Expand lowest heuristic node)
- A* (Expand lowest heuristic + acquisition_cost node)

## Metaheuristics

- Genetic algorithm
- Simulated Annealing
- Ant Colony
- Tabu Search

## Data Structures

- Stack allocated [Array](include/array.hpp). Usage [example](ds_tests/array_test.cpp). STD implementation [here](https://en.cppreference.com/w/cpp/container/array).
- Vector
- [Singly Linked List](include/single_link_list.hpp)
- Double Linked List
- Stack
- Queue
- [BT](include/binnary_tree.hpp) (Binnary Tree)
- BST (Binnary Search Tree)
- Heap
- Trie
- [Graph](include/graph.hpp)
- Hash table



# To test an algorithm

If serial algorithm: 
`./run_serial.sh <path_to_cpp_file>`

If parallel algorithm:
`./run_parallel.sh <path_to_cpp_file> <processors_to_use>`
