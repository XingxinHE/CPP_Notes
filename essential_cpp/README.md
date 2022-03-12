# Chapter 1. Basic C++ Programming

**📌Composition of a C++ Class**

- A *header* file that provides a declaration of the operation supported by the class
- A *program text file* that contains the implementation of those operations



**📌<u>Common Initialization Syntax</u> VS <u>Constructor Syntax</u>**

- common:

```c++
int number = 0;
```

- constructor syntax:

```c++
int number(10);
```



**📌Constructor Syntax**

The reason behind this syntax refers to multiple parameter initialization.(very common in Class) 

But the primitive type can also be initialized like so.



**📌Initialize an array**

1️⃣:

```c++
int seq_size = 6;
int elem_seq[seq_size] = {
    1, 2, 3,
    4, 5, 6
};
```

2️⃣:

```c++
int elem_seq[] = {
  1, 2, 3,
  4, 5, 6
};
```



**📌Initialize a vector**

1️⃣:

```c++
int seq_size = 3;
vector<int> elem_seq(seq_size);
elem_seq[0] = 1;
elem_seq[1] = 2;
elem_seq[2] = 3;
```

2️⃣:

```c++
int seq_size = 3;
int elem_val[seq_size] = {1, 2, 3};
vector<int> elem_seq(elem_val, elem_val + seq_size);
```

`elem_val` is actually the address passed in the vector. The `+ seq_size` indicates how long the array should be.





**📌Why pointer?**

A *pointer* introduces a level of indirection to a program. Rather than <u>manipulate an object directly</u>😑, we <u>**manipulate a pointer that holds the address of an object**</u>😍.





📌**How to use a pointer?**

```c++
int ival = 1024;
int* pi;             // pi is a pointer to an object of type int
&ival;               // evaluates to the address of ival by using `&`
pi = &ival;          // pass the address of ival to pi
```



**📌Different Style of Pointer**

```c++
int* pi = &ival;
int *pi = &ival;
```

The preceding are both correct. If you prefer the first one, please take into account the following:

```c++
int* pi, pi2;
```

`pi` is a pointer, `pi2` is just an integer. If you want both of them are pointer, you should:

```c++
int* pi, * pi2;
```



📌**Dereference a pointer**

You can take the value of the pointer points to by using `*`.

```c++
if (*pi != 1024)
{
    *pi = 1024;
}
```



**📌Be patient when you are learning pointer**

The initial **complexity** of using a pointer comes from its <u>***confusing syntax***</u>.🤣





**📌Caution using pointer!**⚠

A pointer can possibly points to no object!

```c++
// initialize a pointer to address no object
int *pi = 0;
```

Therefore, to guard against dereferencing a null pointer, we must assure if its address value is zero before using...

```c++
// safe check
if (pi && *pi!=1024)
{
    *pi = 1024;
}
```

The `if (pi && ...)` assure the pointer `pi` is not empty.



**📌Complex Example of Pointers**

We have 6 vector sequence objects:

```c++
vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;
```

Suppose we have a pointer points to `fibonacci`:

```c++
vector<int> *fib_ptr = &fibonacci;
```

Or more than that, an array of pointers whose type is `vector<int>*`...

```c++
vector<int>* ptrs[6] = {
    &fibonacci, &lucas, &pell, &triangular, &square, &pentagonal
};
```





**📌Function using `->()` and `.()`**

In C#, a function can be called like this:

```c#
number.ToString();
```

But in C++, you may see 2 ways of invoking a function:

```c++
xxx.DoSomething();
xxx->DoSomething();
```

The difference is that:

When `xxx` is an **object** of a class, it uses `xxx.Function();`

When `xxx` is a **pointer** to an object, it uses `xxx->Function();`



# Chapter 2. Procedural Programming

**📌Definition of Function**

It is composed of:

1️⃣ the **return type** of a function.

2️⃣ the **name** of the function.

3️⃣ the **parameter list** of the function.

4️⃣ the **body** of the function.

```c++
// a function calculate a fibonacci number
int fibon_elem(int pos)
{
    int elem = 1;
    int n_2 = 1, n_1 = 1;
    for(int ix = 3; ix <= pos; ++ix)
    {
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;
    }
    return elem;
}
```



**📌The `&` in front of a parameter in a function**

The `&` in front of a variable is to take its address.

```c++
int num = 10;
int* ptr = &num;
```

The `&` in front of a parameter is to indicate that modifying the original:

```c++
// pass by reference
void IncrementA(int &num)
{
    num++;
}
// pass by value
void IncrementB(int num)
{
    num++;
}
```

Apparently, the `IncrementA` does increment the number, because it modifies the origin by using `&`.



📌**`&` in C++ and `ref` in C#**

`&` in a function declaration is very much the same as `ref` in a function declaration.

```c#
// pass by reference
static void IncrementA(ref int num)
{
    num++;
}
// pass by value
static void IncrementB(int num)
{
    num++;
}
```

Apparently, `IncrementA` does increment.



**📌Things behind invoking a function**

When we invoke a function, a special area of memory is set up on ***stack***. Within this special area of memory there is a space to hold the value of each function parameter and variables inside the scope(local variables). 

```c++
void SomeFunction(int param)
{
    ======================
    ||                  ||
    ||                  ||
    ||      STACK       ||
    ||                  ||
    ||                  ||
    ======================
}
```

When the function completes, this area of memory is discarded.(***popped*** from the program stack)

By default, an object is passed to a function, its value is copied to the local definition. That is called ***pass by value***.

```c++
// pass by value
void SomeFunction(int num);
```

If we want to modify the original value, it is called ***pass by reference***.

```c++
// pass by reference
void SomeFunction(int &num);
```

 

**📌Can't return pointer/reference inside the stack**

Due to the preceding mechanism, returning the address of one of these *local* objects results in serious run-time program errors❌.

```c++
// This is WRONG!!!
int* GetAnInteger()
{
	int num = 10;
	return &num;
}

int main()
{
	int* ptr;
	ptr = GetAnInteger();	
	return 0;
}
```

However, if you do want to return something inside the stack. You have to declare it as `static`. This is very special in C++(compared to C#).

```c++
// This is OK...
int* GetAnInteger()
{
	static int num = 10;
	return &num;
}

int main()
{
	int* ptr;
	ptr = GetAnInteger();	
	cout << *ptr << endl;
	return 0;
}
```





**📌MAIN DIFFERENCE in pass by reference between C++ and C#!!**⭐⚠

In C#:

```c#
void SortA(List<int> numbers)
{
    //...
}

void SortB(ref List<int> numbers)
{
    //...
}

// the invoking are different
SortA(number_list);
SortB(ref number_list);
```

The preceding 2 declarations are the **same**. Because in C#, `List<T>` is passed by reference by **default**.



In C++:

```c++
void IncrementA(vector<int> numbers)
{
	//...
}

void IncrementB(vector<int> &numbers)
{
	//...
}

// the invoking are the same
IncrementA(numbers_vector);
IncrementB(numbers_vector);
```

The preceding 2 declarations are **different**. Because in C++, everything is passed by value by **default**. You have to explicitly assure whether is passed by reference or passed by value.



**📌Pass by Reference  Semantics**

The `&` mark has 3️⃣ meaning and usage:

1️⃣: retrieve the address of a variable

```c++
int ival = 10;
int *pi = &ival;
```

2️⃣: indicate a function is pass by reference

```c++
void IncrementB(vector<int> &numbers);
```

3️⃣: Set up a reference between objects.

```c++
int ival = 1024;
int &rval = ival;
rval = 10;        // then ival is now 10 as well.
                  // the mechanism behind is that ival and rval are with same address.
```





**📌Benefit Using Pass by Reference**🌟

The following 3 functions do the same thing which merely `cout` the value. But he **difference** is that the former one is much **FASTER**.

```c++
void DisplayA(const vector<int> &numbers)  //FAST!!
{
	for(int i = 0; i<numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
}

void DisplayB(const vector<int> numbers)
{
	for(int i = 0; i<numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
}

void DisplayC(const vector<int>* numbers)  //FAST!!
{
	if (!numbers)
	{
		cout << "The pointer is null"  << endl;
		return;
	}
	for(int i = 0; i<numbers->size(); i++)
	{
		cout << (*numbers)[i] << endl;
	}
}
```

The `const` keyword indicates that the function **will not modify the input**.🌟



**📌Difference between reference parameter and pointer parameter**

Before we dereference a pointer, we **MUST** always <u>make sure</u> the pointer is <u>not set to 0</u>. 

A reference always refers to some objects and therefore the <u>check for 0</u> is **unnecessary**.



**📌👍Lippman's advice on passing by reference**

> ​	"I recommend *not* passing built-in types by reference. The reference mechanism is primarily intended to support the passing of class objects as parameters to functions."





**📌What is Storage Duration(extent)?**

It refers to the period of time for which memory is allocated for an object is called its <u>*storage duration*</u> or *<u>extent</u>*.



**📌Categories of Extent**

There are **3** extents:

1️⃣Local extent

- easy to understand, e.g. the local variable

- managed <u>automatically</u>

2️⃣File extent(static extent)

- the variables in file scope, which are outside of `main()` function. Its memory is allocated before the beginning of `main()` and remains allocated until the program is terminated.

- managed <u>automatically</u>

3️⃣Dynamic extent

- The memory comes from the ***heap***.
- managed by programmer <u>explicitly</u> with `new` and `delete`.



**📌Example of Dynamic Memory Allocation**

The syntax is:

```
new Type(initial value);
```

Declare, but not initialized:

```c++
int *pi;
pi = new int;
```

Declare, also initialized:

```c++
int *pi;
pi = new int(1024);
```

Allocate an array of heap elements:

```c++
int *pia = new int[24];
```

Delete an object:

```c++
delete pi;
```

Delete an array:

```c++
delete [] pia;
```



**📌Dangerous! Memory Leak⚠**

If you don't remember to `delete` something, in the end it will cause ***memory leak***.



**📌Lippman' advice on designing a function**👍

> ​	"It is better to communicate between functions using parameters rather than use objects defined at file scope. Since function dependent on file scope is harder to reuse in a different context."

```c++
void SomeFunction()
{
    // here use some value in file scope
    // therefore it is hard to check
}
```



**📌`inline` Functions**

- What is it?

An `inline` function represents a request to the compiler to expand the function at each call point. With an `inline` function, the compiler replaces the function call with a copy of the code to be executed.



- Why use it?

To reduce the function call overhead[^1].



- When to use it?

`inline` function only suits to **small** function. 



- What is its analogy?

The analogy of C++ `inline` function in C# are `Action<>` and `Func<>`.





**📌Template Functions**

```c++
template <typename T>
void ReverseVector(vector<T> &vec)
{
	stack<T> sta;

	for (size_t i = 0; i < vec.size(); i++)
	{
		sta.push(vec[i]);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = sta.top();
		sta.pop();
	}
}
```





**📌Pointers to Functions**

God damn it. This is really really hard...

//TODO well explained next time...



**📌Header Files**

- use ".h" as suffix by convention
- ok to multiple declarations
- only one definition of a function in a program
- usually no definition in header files
- `inline` functions definition and `template` class definition should be in header files



**📌What is `extern`?**

Suppose we have something in the header file:

```c++
const int seq_cnt = 6;
const vector<int>* (*seq_array[seq_cnt])(int);
```

It is not right... Since the `seq_cnt` as 6 will be passed in the function declaration. While the declaration is merely declaration. Therefore we could use:

```c++
const int seq_cnt = 6;
extern const vector<int>* (*seq_array[seq_cnt])(int);
```

The `extern` means the following is just declaration, please ignore the parameter name. It does not have any relationships with others.



**📌Different `include`**

You might see:

```c++
#include <iostream>
#include "igl_mesh"
```

The short answer is:

Use `" "`, if the header file is in the same directory as the program text file including it.

Use `< >`, if the header file is anywhere else.

























[^1]: 假设一个大方法里面有很多小方法，这些小方法实际上非常小。<u>数据转换过程所占用的时间</u>大于<u>方法运行本身所占用的时间</u>要多，因此才要用`inline` 函数。













































































































































