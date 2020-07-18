# Memory management notes

## Stack allocation:
Stores temporary variables created by each function with a LIFO data structure managed by CPU.

Example:
```cpp
  Entity entity("oleguer");  // Value based: Local to this function stack frame
  std::cout << entity.GetName() << std::endl;
```

Example:
```cpp
  bool* visited = (bool*) alloca(sizeof(bool)*n); // alloca reserves in stack memory. WARNING! Not recomended, If causes stack overflow, program behavior is undefined
  memset(visited, false, n);
```

**Pros:**
- Faster allocation
- Automatically "destroyed" when scope is finished

**Cons:**
- Can only be used in this scope (between these brackets)
- Objects can't be very very big (STACK memory is fixed to ~2MB ~= 1000x500 32bit numbers)


## Heap allocation:
Example of dynamically allocated memory:
```cpp
  Entity *entity = new Entity("oleguer");  // Created in heap
  std::cout << (*entity).GetName() << std::endl;  // Access pointer value
  std::cout << entity->GetName() << std::endl;  // Arrow automatically does this for us

  // As it is a pointer created in heap,
  // here we could save the pointer and use it in another scope
  some_entity_pointer = entity;
  // This is not copying values, just setting another pointer

  // When we are done with this variable,
  // we have to free the memory allocated
  delete entity;
  // OBS: if we had assigned it to another pointer,
  // we could have done:  delete some_entity_pointer
  // And would have deleted the same object
  // (we can do this outside this scope)
```

Example:
```cpp
  bool* visited = (bool*) malloc(sizeof(bool)*n); // malloc reserves in heap memory. WARNING! Not recomended, If causes stack overflow, program behavior is undefined
  memset(visited, false, n);
```

**Pros:**
- Control over life-span of the object
- Can hold bigger variables (HEAP memory is expandable)

**Cons:**
- Slower
- Can lead into memory leaks

### The "NEW" KeyWord:
- Finds the necessary memory for the specified data type in the HEAP memory.
- Returns a pointer to the found address
- It also calls the constructor of the object

**OBS:** The memory allocating part of **new**, is equivalent to **malloc**:
```cpp
  // Allocate memory and call constructor:
  Entity* entity = new Entity();

  // Allocate memory but don't call constructor
  Entity* entity = (Entity*)malloc(sizeof(Entity));  
```

### The "DELETE" KeyWord:
- Calls c function: **free()**, which frees the malloc block memory
- Calls destructor of the object

**OBS:** If we create a new array, we must delete by **delete[]**:
```cpp
  int* array = new int[50];
  destroy[] array;
```

**OBS**: std::vector allocates elems in heap:
```cpp
vector<Type> vect; // Allocates header info, on the stack, but the elements heap
vector<Type> *vect = new vector<Type>; // Allocates everything in heap
// Elements are in the heap because they can change dynamically
```

