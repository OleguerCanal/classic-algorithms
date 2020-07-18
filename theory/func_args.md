# Passing args to functions

**Passing by value:**
- Slower
- Modifications of the object don't affect original object

```cpp
  Something getSomething(const Entity entity) {  // Passing a copy of the object
  }
```

**Passing by reference:**
- Fast
- Passes a pointer to the object
- Usually protected by const since user does not want to get it modified

```cpp
  Something getSomething(const Entity& entity) {  // Pass by reference (always protected by const)
  // OBS: Returning Something will be copied, if possible try to avoid returning things an
  }
```

**Passing pointer:**
- Fast
- Passes a pointer to the object
- No need to protect it with const since user is aware it can get modified.
- 
```cpp
  void doSomethingInPlace(Entity* entity) {  // Pass pointer
  }
  
  doSomethingInPlace(&entity);  // User is aware variable will get changed
```