# STD Data Structures

**TODO:** vector, list, unordered_map, map, multimap, multiset...

## queue:
**Implementation:**
- Container (default: std::deque)

**Average Costs:**
- push: O(1) (except when reloacation happens O(n))
- front: O(1)
- pop: O(1)
- empty: O(1)
- size: O(1)

**OBSs**:
- Not a container, but container adaptor (takes container and builds different interface)
- Used in BFS implementation

## stack:
**Implementation:**
- Container (default: std::deque)

**Average Costs:**
- push: O(1) (except when reloacation happens O(n))
- front: O(1)
- pop: O(1)
- empty: O(1)
- size: O(1)

**OBSs**:
- Not a container, but container adaptor (takes container and builds different interface)
- Used in DFS implementation

## unordered_set:
**Implementation:**
- Hash table

**Average Costs:**
- Insertion: O(1)
- Search: O(1)
- Remove: O(1)
**OBSs**: Traverse with an iterator

## set:
**Implementation:**
- Binnary search tree

**Average Costs:**
- Insertion: O(log n)
- Search: O(log n)
- Remove: O(log n)

**OBSs**: Traverse with an iterator