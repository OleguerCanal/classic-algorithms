---
layout: post
title: "Classifying programming languages"
permalink: /theory/languages
index: true
---
{% include start-row.html %}

## Abstraction

- **Low-level**: Commands or functions in the language map closely to processor instructions, there is no abstraction from a computer's instruction architecture.

  - **Machine code**: Is the only language a computer can process directly without a previous transformation. Its encoded in a stream of raw binary data (instructions). Humans don't write it.

  - **Assembly languages**:  Provide a simple mapping of human-readable symbols to machine code. This mapping includes symbolic addresses, opcodes, addresses, numeric constants, strings and so on. Typically, one machine instruction is represented as one line of assembly code. 

- **High-level**: Present strong abstraction from the computer operations (e.g. they automate memory management, architectural agnosticism...). The amount of "abstraction" defines how "high-level" a programming language is. (e.g.  C++, Java, Python)

## Execution modes

{% include end-row.html %}
{% include start-row.html %}

High-level languages present 3 types of execution modes (i.e they can be executed in up to 3 different ways).

- **Interpreted/Dynamic**: Execute instructions directly without previously compiling the program into machine-language. The interpreter follows the program flow and translates each statement into a sequence of subroutines. (Simplest implementation of the behavior of a program)

- **Compiled**: Program syntax is transformed into an executable form before running. Types:

  - **Machine code generation**: Program is translated into machine code. 

  - **Intermediate representation**: Code compiled into an intermediate representation can be optimized or saved for later execution without the need to re-read the source file. When the intermediate representation is saved, it may be in a form such as [bytecode](https://en.wikipedia.org/wiki/Bytecode) (instruction set designed for efficient execution by software interpreter). Java is a good example.

- **Source-to-source translated**: Translates a language into a lower-level one which can be compiled into machine code. For instance, [CoffeeScript](https://en.wikipedia.org/wiki/CoffeeScript) is compiled into [JavaScript](https://en.wikipedia.org/wiki/JavaScript) (it adds syntactic sugar for usability).

{% include annotation.html %}
Note that languages are not strictly **interpreted** or **compiled**. Rather implementations of language behavior use interpreting or compiling.

E.g. C++ is usually implemented as a **compiled** language, but there exist **interpreters** that run C++ code. Furthermore, it can be compiled into **machine code** or other formats (e.g. _.exe_) that run with an OS.

E.g. Python is **compiled** into **bytecode** (_.pyc_). This bytecode is passed into the PVM (Python Virtual Machine) where its either interpreted or both interpreted and compiled to optimized machine code at runtime.

E.g. Java (_.java_) is compiled to **bytecode** (_.class_) (intermediate executable program code). This **bytecode** can be executed by either **intepreting** in a JVM (Java Virtual Machine) or **compiling** with a [just-in-time (JIT)](https://en.wikipedia.org/wiki/Just-in-time_compilation) compiler such as HotSpot (again in a JVM, essentially compiles during execution time).

{% include end-row.html %}
{% include start-row.html %}

## Programming Paradigms

{% include end-row.html %}
{% include start-row.html %}

- **Imperative**: Programmer explicitly instructs the machine **how** to change its state.
    
    - **Procedural**: Defined by procedural blocks (routines containing a series of computational steps) which can be called at any time by other routines (or itself). E.g. BASIC and C languages are procedural.
    
    - **Object Oriented**: Groups functionalities into "objects" which encapsulate data (fields) and code (methods). (C++, Java, and Python are OOP languages)
    
    - **Scripting**: Used for wiring together systems and applications at a very high level. They are almost always extremely expressive (they do a lot with very little code) and usually interpreted (meaning the compiler does very little, while the run-time system does almost everything). (e.g. Perl, PowerShell and Python).

- **Declarative**: The programer declares properties of the desired result but not how to compute it.

    - **Functional**: The desired result is declared as the value of a series of operations (composition of functions). Haskell is an example of a purely functional programming language.

    - **Logic**: The desired result is declared as the answer to a question about a system of facts and rules. The coder states a set of logical forms about the domain. (Prolog is an example of a logic programming language).

    - **Mathematical Programming/Mathematical Optimization**:  The desired result is declared as the solution of an optimization problem.

- **Event-driven**: The flow of the program is determined by user events(e.g. mouse clicks, key presses, sensor outputs...). (e.g. Visual Basic, JavaScript)
  

{% include annotation.html %}
Most programming languages support more than one programming paradigm to allow programmers to use the most suitable programming style and associated language constructs for a given job.

For instance C++ and Python combine both **procedural programming** and  **Object Oriented** programming.
{% include end-row.html %}
{% include start-row.html %}

## Memory management

{% include end-row.html %}
{% include start-row.html %}

- **Garbage collected (GC) languages (managed)**: Form of automatic memory management. The GC attempts to reclaim memory occupied by objects that are no longer in use. While it avoids bugs such as dangling pointer, double pointers, or memory leaks), it may take significant processing time of the program, negatively affecting performance. Automatic GC can be incompatible with manual resource management, being suboptimal at points where the coder can already know how to manage memory. (e.g. C#, Java, Python)

    - **Tracing GC**: Determining which objects should be de-allocated ("garbage collected") by tracing which objects are reachable by a chain of references from certain "root" objects, and considering the rest as "garbage".

    - **Reference counting GC**: Each object has a count of the number of references to it, if this count gets to 0, the object gets destroyed.

- **Manual memory management languages**: Usage of manual instructions to identify and de-allocate unused objects. Heap memory in C, C++ is manually managed (e.g. `malloc` and `free()` in C; `new` and `delete` in C++). This contrasts with automatic variables and local variables, which get allocated in the stack memory and get destroyed at the end of their scope.

{% include annotation.html %}
Notice that when talking about memory management we are mostly talking about managing the Heap memory. Stack memory is usually freed automatically at the end of the scope.

{% include end-row.html %}
{% include start-row.html %}


<!-- Unmanaged code refers to code written in a programming language such as C or C++, which is compiled directly into machine code. It contrasts with managed code, which is written in C#, VB.NET, Java, or similar, and executed in a virtual environment (such as .NET or the JavaVM) which kind of “simulates” a processor in software. The main difference is that managed code “manages” the resources (mostly the memory allocation) for you by employing garbage collection and by keeping references to objects opaque. Unmanaged code is the kind of code that requires you to manually allocate and de-allocate memory, sometimes causing memory leaks (when you forget to de-allocate) and sometimes segmentation faults (when you de-allocate too soon). Unmanaged also usually implies there are no run-time checks for common errors such as null-pointer dereferencing or array bounds overflow.

Strictly speaking, most dynamically-typed languages — such as Perl, Python, PHP and Ruby — are also managed code. However, they are not commonly described as such, which shows that managed code is actually somewhat of a marketing term for the really big, serious, commercial programming environments (.NET and Java). -->

## Type system

{% include end-row.html %}
{% include start-row.html %}

A type system associates a type with each computed value (variable, expression, module) and, by examining the flow of these values, attempts to ensure or prove that no type errors can occur.
The purpose is to formalize and enforce categories to check consistency and reduce bugs.

**Typecasting** deals with the conversion of one data type to another datatype. 

- **Static vs Dynamic**:

    - **Static type checking**: is the process of verifying the type safety of a program based on analysis of a program's text (source code). If a program passes a static type checker, then the program is guaranteed to satisfy some set of type safety properties for all possible inputs. If a compiler can prove that a program is well-typed, then it does not need to emit dynamic safety checks, allowing the resulting compiled binary to run faster and to be smaller. (e.g. C, C++, Java)

    - **Dynamic type checking**: Verifying the type safety of a program at runtime. Most type-safe languages include some form of dynamic type checking, even if they also have a static type checker, as many useful features are difficult/impossible to verify statically. (e.g. Python)

- **Manifested vs Inferred**:

  - **Manifest** typing is explicit identification by the software programmer of the type of each variable being declared. (e.g. C++)
  
  - **Inferred** typed languages use implicit typing, where the type is deduced from context at compile-time or are dynamically typed. (e.g. Python)

- **Nominal vs Duck vs Structural**: 

  - **Nominal type system**: Compatibility and equivalence of data types is determined by explicit declarations and/or the name of the types. (e.g. C++, C#, Java)
  
  - **Duck typing**: _"If it walks like a duck and it quacks like a duck, then it must be a duck"_. An object's suitability is determined by the presence of certain methods and properties, rather than the type of the object itself. The type of object does not matter as long as it presents everything needed. Compatibility is checked at runtime. (e.g. Python, JavaScript, PHP)

  - **Structural type system**: Compatibility and equivalence of data types is determined by the structure of the types in question and do not require explicit declarations. It differs from duck typing as ALL the structure must match. (e.g. GO)


{% include annotation.html %}
A number of useful and common programming language features cannot be checked statically, such as [downcasting](https://en.wikipedia.org/wiki/Downcasting) 
(you cannot know if the object you are trying to downcast was previously upcasted).
Thus, many languages will have both static and dynamic type checking; the static type checker verifies what it can, and dynamic checks verify the rest.

C# distinguishes between statically-typed and dynamically-typed variables.
{% include end-row.html %}
{% include start-row.html %}


## Famous Languages

- **c++**: High-level, usually compiled, multi-paradigm (procedural + object-oriented + functional), unmanaged, static-nominal-(partially inferred) typing.

- **Python**: High-level, compiled into bytecode which gets interpreted, multi-paradigm (procedural + object-oriented + functional), managed, dynamic-inferred-duck typing.

{% include end-row.html %}

