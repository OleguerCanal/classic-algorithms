# STD Data Structures

**TODO:** vector, list, unordered_map, map, multimap, multiset...

## unordered_set:
**OBSs**: Traverse with an iterator

**Implementation:**
- Hash table

**Average Costs:**
- Insertion: O(1)
- Search: O(1)
- Remove: O(1)

## set:
**OBSs**: Traverse with an iterator

**Implementation:**
- Binnary search tree

**Average Costs:**
- Insertion: O(log n)
- Search: O(log n)
- Remove: O(log n)


## queue:
**OBSs**: Not a container, but container adaptor (takes container and builds different interface)

**Implementation:**
- Container (default: std::deque)

**Average Costs:**
- push: O(1) (except when reloacation happens O(n))
- front: O(1)
- pop: O(1)
- empty: O(1)
- size: O(1)