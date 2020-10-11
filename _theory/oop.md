---
layout: post
title: "Object Oriented Programming"
permalink: /theory/oop
index: true
---

{% include start-row.html %}

## Definitions

- **Class**: Means of bundling data and functionality together.
- **Object**: Instance of a class. It has its own state, behavior, and identity.

## Inheritance
It lets programmers create new classes that share some of the attributes of existing classes.
This lets us build on previous work without repeating code.

- **Base class**: Does not inherit from any other class.
- **Subclass**: Child class or inheriting (gets the stuff from the parent).
- **Superclass**: Parent class.


## Composition
When a class contains an instance of another class.
In general composition is preferred over inheritance:

- If a class **has** another class, you should use **composition**.
- If a class **is** a type of class, you should use **inheritance**.


## Encapsulation

It is the mechanism that binds together code (methods) and the data it manipulates (fields).
It works on the implementation level.

This concept is also used for protecting data by restricting the access to values or states to unauthorized parties: **information hiding**.
Public accessible methods are provided in the class ("getters" and "setters") to access these values.

Advantages:
- **Data hiding**: User does not need to know how the private elements of the class work.
- **Increased flexibility**: We can make the variables of the class as read-only or write-only depending on our requirement.

Main access modifier levels:
- **Private**: Only accessible within the class
- **Protected**: Only accessible within the class or children.
- **Public**: Accessible by everybody.


## Abstraction

{% include end-row.html %}
{% include start-row.html %}
Abstractions operates in the design level.
It is used for hiding unwanted data and only showing the functionality to the users.
Encapsulation, in contrast, is the technique for packaging the information in such a way as to hide what should be hidden, and make visible what is intended to be visible.

Concepts:
- **Abstract class**: Template definition of methods and variables of a class. It cannot be instantiated, only inherited, and the child classes must implement the **abstract methods**.

  - **Abstract method**: Reside in base abstract classes and have no body (no implementation). They must be implemented (overriden) by child classes.

  - **Virtual method**: Can reside in either abstract base or non-abstract base classes. They must have a body, which can be **overridden** (it is not necessary to). Used to achieve **run-time polymorphism**. Cannot be static, or friend functions of other classes. [Example](https://www.geeksforgeeks.org/virtual-function-cpp/) of virtual method usage.
  
  - **Friend function**: A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Useful for logging and unit testing, while still having proper encapsulation.

{% include annotation.html %}
**Encapsulation vs Abstraction:**
Consider a calculator. **Encapsulation** is the internal circuits, battery, etc., that combine to make it a calculator (internal). **Abstraction** is the different buttons like on-off, clear and other buttons provided to operate it (design).

{% include end-row.html %}
{% include start-row.html %}

- **Interface**: Object with only abstract methods. Abstract class can provide an implementation of interface, but interface cannot provide implementation of abstract class. An interface can extend another interface, an abstract class can extend another class and implement multiple interfaces. In Java it only have final and static variables public by default (no non-final nor non-static or protected/private fields as Abstract class can).

{% include annotation.html %}
Interfaces are mostly a Java and C# thing.
C++ has no interfaces but they can be imitated by having a class with only pure virtual methods. 

{% include end-row.html %}
{% include start-row.html %}

## Polymorphism
{% include end-row.html %}
{% include start-row.html %}

Polymorphism allows us to perform a single action in different ways.
In other words, polymorphism allows you to define one interface and have multiple implementations.

- **Static/Compile-time polymorphism**: This type of polymorphism is achieved by function **overloading** (or operator overloading). Same function presents different behaviors.

  - **Function Overloading**: A function is overloaded when there exist multiple functions with the same name but different parameters. Depending on how we call them, one or the other will be used.

  - **Operator Overloading**: Same idea but with operators. (e.g `+` operator is used to concatenate two strings when arguments are both strings, or to add two values when arguments are numbers).

- **Dynamic/Run-time polymorphism**: This type of polymorphism is achieved by function **overriding**. If an object is treated as its parent class, we can access a method parent implementation if marked as **virtual function**.

  - **Function overriding**: When a child class has a definition of a parent class method.

{% include annotation.html %}
**Overloading**: Static Polymorphism
```cpp
class A{
  // Same name, different args
  int method(int a);
  int method(int a, int b);
}
```

**Overriding**: Dynamic Polymorphism
```cpp
class A{
  int method(int a);
}

class B{
  // Re-implementation
  int method(int a);
}
```
In the overriding case, if method in A is marked as virtual, we can access the original implementation by 

{% include end-row.html %}
{% include start-row.html %}

## Constructor/Destructor

Types of constructor:
- **Default**: No parameters passed. 
- **Parametric**: Creates a new instance (object) passing arguments simultaneously.
- **Copy**: Creates a new object copying it from an existing object.


## Object Casting

{% include end-row.html %}
{% include start-row.html %}

- **Upcasting**: Implicitly (only 1 exists) converting and object to its parent class, specific child fields and methods are not available, but originally overriden methods are accessible.

- **Downcasting**: Explicitly (multiple can exist) converting an object to a child class.

{% include annotation.html %}
You can only downcast an object which has been upcasted. Essentially the object is the same but the way you see it changes:

{% include end-row.html %}