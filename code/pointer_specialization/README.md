# Pointer Specialization

This note is what I documented after reading the C++ Pointer Specialization from the following link.

https://docs.microsoft.com/en-us/cpp/cpp/pointers-cpp



## Raw Pointer

**📌Definition**

Raw pointer is what I learned and used in the book "Essential C++" and "Programming Abstraction in C++". 



**📌Pointer in Stack**

```c++
int* p = nullptr; // declare pointer and initialize it
// so that it doesn't store a random address
int i = 5;
p = &i; // assign pointer to address of object
int j = *p; // dereference p to retrieve the value at its address
```



**📌Pointer in Heap**

```c++
MyClass* mc = new MyClass(); // allocate object on the heap
mc->print(); // access class member
delete mc; // delete object (please don't forget!)
```



**📌`const` keyword related to pointer**

<u>WARNING</u>! This is a pretty 😵 tough topic.



> ​	The pointer points to something that can't change.

```c++
const char* str = "Hello world";
str[0] = 'G';  //ERROR!! ❌
```

The pointer points to a `char` array and <u>that array can't be change</u>.



```c++
const char* str = "Hello world";
str = "Salve mondo";  //OK✅
```

But I can change that pointer point to something is `const`. (FYI, the string here is treated as constant.)



```c++
const double PI = 3.14159;

double* pConst = &PI;
// ERROR!❌ the pointer is not declared to points to const double
```

Same logic applies to other data type.



```c++
const double PI = 3.14159;
const double* pConst = &PI;  // OK✅
const double EPSILON = 1.0e-09;
pConst = &EPSILON;
```





**📌`void*` pointer**

A pointer to **`void`** simply points to a raw memory location.



**📌When should we use `void*` pointer?**

Interpolation between C and C++.



**📌Don't use `void*` pointer**⚠⭐

Modern C++ discourages the use of `void` pointers in almost all circumstances.



**📌Pointer to functions**

This is the analogy to the `delegate` in C#.

