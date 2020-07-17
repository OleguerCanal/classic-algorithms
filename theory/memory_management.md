# Memory management notes

## Pointers
Positions in memory:
Variables:
```cpp
  Entity entity;  // Value based: Local to this function stack frame
  Entity* entity_ptr = &entity;
  std::cout << (*entity_ptr).GetField() << std::endl;  // Option 1 To get value of pointer
  std::cout << entity_ptr->GetField() << std::endl;  // Option 2 (Wrapper) To get value of pointer
```
Params in functions:

```cpp
  Something getSomething(const Entity& entity) {  // Pass by reference (always protected by const)
  // OBS: This something will be copied, if possible try to avoid returning things
  }
```


```cpp
  void doSomethingInPlace(Entity* entity) {  // Pass pointer
  }
  
  doSomethingInPlace(&entity);  // User is aware variable will get changed
```

## Stack allocation:
Stores temporary variables created by each function with a LIFO data structure managed by CPU.

Example:
```cpp
  Entity entity("oleguer");  // Value based: Local to this function stack frame
  std::cout << entity.GetName() << std::endl;
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

## Pointers
- Integer that holds a memory adress.
**OBS**: type of pointer is irrelevant, its always an integer

Example:
```cpp
  int var = 9;
  int* ptr = &var;  // ptr holds where in memory we are storing var
  *ptr = 10;  // Access the variable from the pointer
  // Now var has a value of 10
```

**OBS:** Pointers are also variables, so we could have pointers of pointers (double pointers)
```cpp
  int var = 9;
  int* ptr = &var;  // ptr is memory address of var
  int** double_ptr = &ptr;  // double_ptr is memory address of ptr
```

## Smart pointers
- Wrapper around raw pointer that automates **new**/**delete** call process in heap memory.

### unique_ptr
- Can't be copied (if one dies, it will free the memory its pointing to, so the other will be pointing nowhere)

Example:
```cpp
  include <memory>  // Needs to be included to use cmart pointers
  {
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();  // Gets created
  }
  // Here entity is automatically destroyed (out of scope)
```

### shared_ptr
- Keeps track of how many references are there to that shared_ptr (once it gets to 0, its automatically destroyed)

Example:
```cpp
  include <memory>  // Needs to be included to use cmart pointers
  {
    std::shared_ptr<Entity> e0;
    {
      std::shared_ptr<Entity> entity = std::make_shared<Entity>();  // Gets created (referennces count = 1)
      e0 = entity;  // assigned to e0 (referennces count = 2)
    }
    // entity out of scope but doesnt get destryed (referennces count = 1)
  }
  // here the memory is freed, all references are dead (references count = 0)
```

### weak_ptr
- Allows you to copy a shared_ptr without increasing ref count (useful to check if something is still alive without keeping it alive)

Example:
```cpp
  include <memory>  // Needs to be included to use cmart pointers
  {
    std::weak_ptr<Entity> e0;
    {
      std::shared_ptr<Entity> entity = std::make_shared<Entity>();  // Gets created (referennces count = 1)
      e0 = entity;  // assigned to e0 but since its weak: (referennces count = 1)
    }
    // entity out of scope gets destryed (referennces count = 0)
  }
```

