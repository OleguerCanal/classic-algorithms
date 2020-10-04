---
layout: post
title: "Pointers"
permalink: /theory/pointers
index: true
---
{% include start-row.html %}

## Basic pointers

- A pointer is an integer that holds a memory address.

{% include annotation.html %}
The type of pointer is irrelevant, its always an integer
{% include end-row.html %}
{% include start-row.html %}

Example:

```cpp
  int var = 9;
  int* ptr = &var;  // ptr holds where in memory we are storing var
  *ptr = 10;  // Access the variable from the pointer
  // Now var has a value of 10
```

Example:
```cpp
  Entity entity;  // Value based: Local to this function stack frame
  Entity* entity_ptr = &entity;
  std::cout << (*entity_ptr).GetField() << std::endl;  // Option 1 To get value of pointer
  std::cout << entity_ptr->GetField() << std::endl;  // Option 2 (Wrapper) To get value of pointer
```

Pointers are also variables, so we could have pointers of pointers (double pointers)
```cpp
  int var = 9;
  int* ptr = &var;  // ptr is memory address of var
  int** double_ptr = &ptr;  // double_ptr is memory address of ptr
```

## Smart pointers
- Wrapper around raw pointer that automates **new**/**delete** call process **in heap memory**.

### unique_ptr
- Can't be copied (if one dies, it will free the memory its pointing to, so the other will be pointing nowhere)

Example:
```cpp
  include <memory>  // Needs to be included to use smart pointers
  {
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();  // Gets created
  }
  // Here entity is automatically destroyed (out of scope)
```

### shared_ptr
- Keeps track of how many references are there to that shared_ptr.
Once it gets to 0, it is automatically destroyed.

Example:
```cpp
  include <memory>  // Needs to be included to use smart pointers
  {
    std::shared_ptr<Entity> e0;
    {
      std::shared_ptr<Entity> entity = std::make_shared<Entity>();  // Gets created (references count = 1)
      e0 = entity;  // assigned to e0 (references count = 2)
    }
    // entity out of scope but doesnt get destroyed (references count = 1)
  }
  // here the memory is freed, all references are dead (references count = 0)
```

### weak_ptr
- Allows you to copy a shared_ptr without increasing ref count (useful to check if something is still alive without keeping it alive)

Example:
```cpp
  include <memory>  // Needs to be included to use smart pointers
  {
    std::weak_ptr<Entity> e0;
    {
      std::shared_ptr<Entity> entity = std::make_shared<Entity>();  // Gets created (references count = 1)
      e0 = entity;  // assigned to e0 but since its weak: (references count = 1)
    }
    // entity out of scope gets destroyed (references count = 0)
  }
```

{% include end-row.html %}