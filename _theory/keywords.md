# Basic C++ KeyWords

## const

## constexpr

## static

#### Variables in functions

Space for the variable gets allocated for the lifetime of the program.
When the function is called multiple times, the value of variable in the previous call gets carried through the next function call:
Useful for implementing coroutines (or other state-storing applications)

```cpp
void demo() 
{  
    static int count = 0;  // count value will be stored in next call
    std::cout << count << " "; 
    count++; 
} 
  
int main() 
{ 
    for (int i=0; i<5; i++)     
        demo(); 
    return 0; 
}
// Prints: 0, 1, 2, 3, 4, 5
```

#### Variables in classes

Same idea. Value gets shared across all instances of that class.

**OBS**: As there cannot be multiple copies of the shared object, they cannot be instantiated in constructors.

```cpp
class Entity 
{ 
   public: 
     static int i; 
     Entity() { };  // Do nothing 
}; 
  
int main() 
{ 
  Entity ent1; 
  Entity ent2; 
  ent1.i = 2; 
  ent2.i = 3; 
    
  std::cout << ent1.i << " " << ent2.i;    
}
// Prints: 3 3
```

You can also modify the value by doing:

```cpp
int Entity::i = 1; 
```

#### Static class objects

Changes the scope of the object to be the life time of program.

```cpp
class Entity
{ 
    int i = 0; 
  public: 
    Entity() 
    { 
        i = 0; 
        cout << "Inside Constructor\n"; 
    } 
      
    ~Entity() 
    { 
        cout << "Inside Destructor\n"; 
    } 
}; 
  
int main() 
{ 
    int x = 0; 
    if (x==0) 
    { 
        static Entity obj; 
    } 
    cout << "End of main\n"; 
}
// Prints: Construction, End of main, Destruction
// If not declared as static would have printed: Construction, Destruction, End of main
```

#### Static functions in a class

Static member functions also do not depend on object of class.
They can not access the non-static data members or member functions of the class.

It is recommended to call them by the scope resolution operator: "::".


```cpp
class Entity 
{ 
  public: 
    static void printMsg() 
    { 
        cout << "Welcome!"; 
    } 
}; 
  
int main() 
{ 
    Entity::printMsg(); 
} 
```