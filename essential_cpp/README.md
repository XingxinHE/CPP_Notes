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

3️⃣:

```c++
vector<int> elem_seq{1, 2, 3};
```

The preceding is very much similar to C# `List<>` initialization.



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





# Chapter 3. Generic Programming

In this chapter, the word "generic" refers to be independent of both the type of element they are operating on and the type of container within which the elements are held.

## 3.1. The Arithmetic of Pointers

**📌Find specific value in a vector**

```c++
int* find(const vector<int> &vec, int value)
{
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        if(vec[ix]==value)
        {
            return &vec[ix];
        }
    }
    return 0;
}
```



**📌(Generic Version)Find specific value in a vector**

```c++
template <typename T>
T* find(const vector<T> &vec, const T &value)
{
    for (int ix = 0; ix < vec.size(); ++ix)
    {
        if(vec[ix] == value)
        {
            return &vec[ix];
        }
    }
    return 0;
}
```



**📌The magic and fun fact of pointer**

Do you know in C++, an array is also a pointer? This is so much fun. The followings are the same!

```c++
array[2]
*(array + 2)
```

If you are a C# programmer, you would say what the heck?? 😨😨

That's because an <u>array is a pointer which records the 1st address of that array</u>. Therefore, they are the same.



**📌Find specific value in an array(Normal Version)**

```c++
template <typename T>
T* find(const T *array, int size, const T &value)
{
    // the difference between vector and array is that
    // array(pointer) could not be empty
    // therefore you should check it first
    if(!array || size < 1)
    {
        return 0;
    }
    for (int ix = 0; ix < size; ix++)
    {
        if(array[ix]==value)
        {
            return &array[ix];
        }
    }
    return 0;
}
```



**📌Find specific value in an array(Pointer Version)**

```c++
template <typename T>
T* find(const T *array, int size, const T &value)
{
    if(!array || size < 1)
    {
        return 0;
    }
    // Please take a look here!! The pointer arithmetic!
    // rather shifting the index, here increment the address
    for(int ix = 0; ix < size; ix++, array++)
    {
        // dereference the pointer, so can be compared with value
        if(*array == value)
        {
            return array;
        }
    }
    return 0;
}
```

//TODO , here 🤔, in Qt, the function declaration should remove `const` from `const T *array`. Is it because the new standard of C++?



**📌Find specific value in an array(Pointer Version with sentinel)**

In this version, we use the address of last element of the array as sentinel[^2] address.

```c++
template <typename T>
T* find( T *first, const T *last, const T &value)
{
    if(!first || !last)
    {
        return 0;
    }
    // here the last address served as sentinel address
    for(; first!=last; first++)
    {
        if(*first == value)
        {
            return first;
        }
    }
    return 0;
}
```

You can use it as the following:

```c++
int main()
{
    int arr_int[5] = {1,2,3,4,5};
    int* ptr = find(arr_int,arr_int+5, 3);
    cout << "Integer value: " << endl;
    cout << "ptr: " << ptr 
         << "*ptr: "<< *ptr<< endl;
    
    double arr_double[] = {1.1,2.3,1.6};
    double* ptr_double = find(arr_double, arr_double+3, 1.1);
    cout << "ptr_double: " << ptr_double 
         << "*ptr_double: "<< *ptr_double<< endl;
    
    return 0;
}
```



**📌Behind the `vec.begin()`**

Since a `vector` could be empty, therefore, it may cause error if we directly query like `vec[0]`. A safer way would be like this:

```c++
template <typename T>
inline T* begin(vector<T> &vec)
{
    // check if it is empty
    return vec.empty()? 0 : &vec[0];
}
```



## 3.2. Iterators

The iterators here are very similar to the `IEnumerable` in C#. In short, iterator is a set of classes that are programmed using the same syntax as that of a pointer to collection in STL. For example, the `++` for vector is to query the next element, so as `++` for linked list. But the next address of a linked list cannot be just incremented. Therefore, we can override their operator.

```
// a pseudo code could be like this
for(iter = numbers.begin(); iter!=numbers.end(); iter++)
{

}
```



**📌What is an iterator?**

`iter` is defined to be an iterator for vectors of `T` elements. It is initialized to address the first element of a `vector`.

```c++
vector<int> ivec;
// normal iterator
vector<int>::iterator iter = ivec.begin();
// const iterator(you can loop them but not modify them)
vector<int>::const_iterator cst_iter = ivec.begin();
```

The double colon `::` indicates that iterator is a type nested within the `T` vector definition.



**📌Example Function using iterator**

//TODO currently this is compiled with error

The display function can be implemented like so:

`T` could be saw as the element type of that container.

```c++
template <typename T>
void display(const vector<T> &vec, ostream &os)
{
    vector<T>::const_iterator iter = vec.begin();
    vector<T>::const_iterator end_it = vec.end();

    for(; iter!=end_it; iter++)
    {
        os << *iter << ' ';
    }
    os << endl;
}
```



//TODO why in the end return `last` but not `0`?

The find function can be implemented like so:

`T` could be saw as the iterator type, while `S` could be saw as the element type.

```c++
template <typename T, typename S>
S find(T first, T last, const S &value)
{
    for(; first!=last; first++)
    {
        if(*first==value)
        {
            return first;
        }
    }
    return last;
}
```



You can use **1** 

```c++
// arrange data
const int asize = 8;

// array, vector, and linked list
int ia[asize] {1,1,2,3,5,8,13,21};
vector<int> i_vec (ia, ia+asize);
list<int> i_list(ia, ia+asize);

// find in array
int* pia = find(ia, ia+asize, 1024);
if(pia != ia+asize)
{
    cout << "1024 found in ia..." << endl;
}

// find in vector
vector<int>::iterator it;
it = find(i_vec.begin(), ivec.end(), 1024);
if(it != ivec.end())
{
    cout << "1024 found in ivec..." << endl;
}

// find in linked list
list<int>::iterator it_list;
it_list = find(i_list.begin(), i_list.end(), 1024);
if(it_list!=i_list.end())
{
    cout << "1024 found in ilist..." << endl;
}
```



**📌Frequently Used Method**

- **search algorithms**: `find()`, `count()`, `adjacent_find()`, `find_if()`, `count_if()`, `binary_search()`, and `find_first_of()`
- **sorting and general ordering algorithms**: `merge()`, `partial_sort()`, `partition()`, `random_shuffle()`, `reverse()`, `rotate()`, and `sort()`
- **copy, deletion, and substitution and algorithms**: `copy()`, `remove()`, `remove_if()`, `replace()`, `replace_if()`, `swap()`, and `unique()`
- **relational algorithms:** `equal()`, `includes()`, and `mismatch()`
- **generation and mutation algorithms:** `fill()`, `for_each()`, `generate()`, and `transform()`
- **numeric algorithms**: `accumulate()`, `adjacent_difference()`, `partial_sum()`, and `inner_product()`
- **set algorithms**: `set_union()` and `set_difference()`





## 3.3. Operations Common to All Containers

**📌A Function Definition Cover All Common Functions of Containers**

```c++
void compare(vector<int> &vec1, vector<int> &vec2)
{
    // equality
    if(vec1 == vec2) return;

    // isEmpty?
    if(vec1.empty() || vec2.empty()) return;

    // the size
    if(vec1.size() != vec2.size()) return;

    // clear all the data
    vec1.clear();

    // begin and end
    for(auto iter = vec1.begin(); iter!= vec2.end(); iter++)
    {
        cout << "+";
    }

    // insert and erase
    vec1.insert(vec1.begin()+1, 2);
    vec2.erase(vec2.end()-3);
}
```



## 3.4. Using the Sequential Containers

**📌Initialization of Container**

The following are the common ways of initialized the containers.

```c++
// 1.Create an empty container
list<string> slist;
deque<int> ideque;

// 2.Create a container of some size
list<int> ilist(1024);
vector<double> dvec(32);

// 3.Create a container of a given size specified with initial value
vector<char> chvec(10, 'X');
list<string> slist1(16, "unassigned");
deque<double> dd(10, 3.2);

// 4.Create a container with iterator
bool barr[3] = {true, false, true};
vector<bool> bvec(barr, barr+3);

// 5.Create a container by full copy another
list<string> slist2(slist);
```





**📌Operations supported per container**

|                                               | `vector` | `list` | `deque` |
| --------------------------------------------- | -------- | ------ | ------- |
| `front()`                                     | ✔        | ✔      | ✔       |
| `push_front()`➕                               | ❌        | ✔      | ✔       |
| `pop_front()`➖                                | ❌        | ✔      | ✔       |
| `[0]`<br>`[1]`<br>`...`<br>`[n-2]`<br>`[n-1]` |          |        |         |
| `pop_back()`➖                                 | ✔        | ✔      | ✔       |
| `push_back()`➕                                | ✔        | ✔      | ✔       |
| `back()`                                      | ✔        | ✔      | ✔       |



**📌Different Ways Using `insert()`**

1️⃣the `insert()` is like: `iterator insert(iterator position, elemType value)`

```c++
// arrange
int ival = 6;
int ia[3] = {1, 2, 9};  // make a linked list with contiguous order
list<int> ilist(ia, ia+3);
list<int>::iterator it = ilist.begin();

// loop over the linked list
while(it != ilist.end())
{
    // if a specific value is > such value
    if(*it >= ival)
    {
        // insert
        ilist.insert(it, ival);
        break;
    }
    it++;
}
// if iterator is at the end(a.k.a. no value in the linked list > such value)
// the value should be at the end of linked list
if(it == ilist.end())
{
    ilist.push_back(ival);
}
// display it
for(int ix:ilist )
{
    cout << ix;
}
```



2️⃣`void insert(iterator position, int count, elemType value)` inserts <u>"count" elements</u> of `value` before `position`.

The following

```c++
// arrage
list<string> slist(3, string("Hello"));
list<string>::iterator it = slist.begin();

// iterator as the 2nd position
it++;

// insert after that position
slist.insert(it, 5, string("dummy"));

// display
for(auto val : slist)
{
    cout << val << "  ";
}
```



There are many other overloaded version. Please refer to docs.



**📌`erase` in STL**

```c++
// arrage
list<string> slist(6, string("Hello"));
list<string>::iterator it = slist.begin();
// iterator as the 2nd position
it++;
list<string>::iterator first = slist.begin();
list<string>::iterator last = slist.end();
last--;

// before erase
for(auto v : slist)
{
    cout << v << "  ";
}
cout << endl;

// since I decrement last once
// then erase will be 0 to n-2
slist.erase(first, last);
// after erase
for(auto v : slist)
{
    cout << v << "  ";
}
```



**📌Linked list does not support offset arithmetic**

```c++
list<string> slist(6, string("Hello"));
list<string>::iterator it = slist.begin();

// ERROR
it = it + 2; //failed to offset 2 position
// OK
it++;        //succeed because the ++ has overloaded version
```

Because the addresses of Linked List are not contiguous! Please refer to [my Algorithm Repo](https://github.com/XingxinHE/Algorithms/blob/main/README.md#232-linked-list-sequence).





## 3.5. Using the Generic Algorithm

**📌Prerequisite**

```c++
#include <algorithm>
```



**📌Generic Search Algorithm**

| Function          | Description                                                  | Return                                                       |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `find()`          | searches **unordered** collection                            | `true` found, `false` not found                              |
| `binary_search()` | searches **ordered** collection, more efficient than `find()` | `true` found, `false` not found                              |
| `count()`         | count the number of that container                           | `int` represents the number                                  |
| `search()`        | matches a subsequence, e.g. find `{5,7}` in `{1,3,5,7,2,9}`  | the iterator of at the beginning of subsequence if found, the end if not found |



**📌Implement search element in Fibonacci sequence using generic algorithm**

```c++
#include <algorithm>
// function to grow the vector if element is bigger than current array
extern bool grow_vec(vector<int> &vec, int elem);

// query if an element inside the vector
bool is_elem(vector<int> &vec, int elem)
{
    // find the max value first
    int max_value = max_element(vec.begin(), vec.end());
    // if the query element is outside of max
    if(max_value < elem)
    {
        //grow it
        return grow_vec(vec, elem);
    }
    if(max_value == elem)
    {
        return true;
    }

    // search it 
    return binary_search(vec.begin(), vec.end(), elem);
}
```



**📌`binary_seach()` only works for sorted container**

It is left to the programmer to guarantee the preceding requirement! What if we are not sure?

```c++
// unsure vector
vector<int> vec;
// duplicate vector with same size
vector<int> vec_copy(vec.size());
// copy from start to end
copy(vec.begin(), vec.end(), vec_copy.begin());
// sort that copy vector
sort(vec_copy.begin(), vec_copy.end());

// query...
int query_num = 13;
bool is_found = binary_search(
    vec_copy.begin(),
    vec_copy.end(),
    query_num);
```





## 3.6. Design a Generic Algorithm

**📌A filer function**

Suppose we have a function to filter out numbers less than 10:

```c++
vector<int> less_than_10(const vector<int> &vec)
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ix++)
    {
        if(vec[ix] < 10)
        {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}
```

It is just a very simple `for` loop to filter out the `vector`. But the constraints❌ are:

- cannot specify the value for filtering
- cannot specify $>$ or $<$

Therefore, we could implement something like this:

```c++
//  a function compared is bigger
bool is_bigger(int lhs, int rhs)
{
    return lhs > rhs? true : false;
}
//  a function compared is smaller
bool is_smaller(int lhs, int rhs)
{
    return lhs < rhs? true : false;
}

//  filter with some value
//  the last argument is a pointer to function
vector<int> filter_with_value(vector<int> &vec, int value, bool (*flag)(int, int))
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ix++)
    {
        if(flag(vec[ix], value))
        {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}

// how to use it
void prog_6()
{
    int arr[5] = {12,13,20,100, 5};
    vector<int> ivec(arr, arr+5);
    vector<int> vec_bigger_10 = filter_with_value(ivec, 13, is_bigger);

    for(auto v : vec_bigger_10)
    {
        cout << v << "  ";
    }
}
```

 

**📌Function Objects**

Definition: A ***function object*** is an instance of a class that provides an overloaded instance of the function call operator.

Analogy: Delegate in C#, Pointer to Function in C++

Example:

Suppose we have a sequence of numbers:
$$
S_1 = \{s_1,s_2,\cdots,s_n\}
$$
Do the element wise addition:
$$
S_1 = \{s_1+s_1,s_2+s_2,\cdots,s_n+s_n\}
$$
Do the element wise multiplication:
$$
S_1 = \{s_1*s_1,s_2*s_2,\cdots,s_n*s_n\}
$$
Then add to another sequence:
$$
S_1 = \{s_1,s_2,\cdots,s_n\}\\
S_2 = \{s^1,s^2,\cdots,s^n\}\\
S_F = \{s^1+s_1,s^2+s_2,\cdots,s^n+s_n\}\\
$$


We can use `transform()` function to do element-wise operation. It takes 5 arguments:

1️⃣  start of elements range to transform

2️⃣  end of elements range to transform

3️⃣  start position fetching data  (iterator points to the beginning of container which fetch data)

4️⃣  start position apply those data  (iterator points to the beginning of the container where apply those transformation)

5️⃣  function object (delegate / pointer to function) to apply those changes

```c++
#include <functional>
void func_obj_example()
{
    int s1[5] = {1, 2, 3, 6, 9};
    int s2[5] = {2, 3, 5, 6, 9};
    vector<int> vec_s1(s1, s1+5);
    vector<int> vec_s2(s2, s2+5);
    vector<int> vec_sf(5);

    transform(vec_s1.begin(),       // 1.
              vec_s1.end(),         // 2.
              vec_s1.begin(),       // 3.
              vec_s1.begin(),       // 4.
              plus<int>());         // 5.

    transform(vec_s1.begin(),       // 1.
              vec_s1.end(),         // 2.
              vec_s1.begin(),       // 3.
              vec_s1.begin(),       // 4.
              multiplies<int>());   // 5.

    transform(vec_s1.begin(),       // 1.
              vec_s1.end(),         // 2.
              vec_s2.begin(),       // 3.
              vec_s1.begin(),       // 4.
              plus<int>());         // 5.
}
```



**📌Function Object Adapter**

In short, the <u>function object adapter</u> **modifies** a <u>function object</u> by specifying lhs/rhs as input. For example, 

`bind1st` binds the 1st operand. `bind2nd` binds the 2nd operand.

```c++
vector<int> filter(const vector<int> &vec, int val, less<int> &lt)
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    // bind2nd(less<int>, val) binds val to the second value of less<int>
    // less<int> now compares each value against val
    while( (iter =
            find_if(iter,
                    vec.end(),
                    bind2nd(lt, val))
            ) != vec.end())
    {
        // each time iter != vec.end(),
        // iter addresses an element less than val
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}
```



**📌More General Version**

The following is a really excellent example. Please digest!

```c++
template <typename InputIterator,
          typename OutputIterator,
          typename ElemType,
          typename Comp>
OutputIterator filter (InputIterator first,
                       InputIterator last,
                       OutputIterator at,
                       const ElemType &val,
                       Comp pred)
{
    while( (first = find_if(first, last, bind2nd(pred, val)))
           != last)
    {
        // just to see what is going on ...
        cout << "found value: " << *first << endl;
        // assign value, then advance both iterators
        *at++ = *first++;
    }
    return at;
}
```

The `*at++ = *first++;` is just the following:

```c++
*at = *first;
at++;
first++;
```



**📌A Subdivision method on `vector`**

The following function is kind of similar to C# (`where x => x< ???`)

```c++
vector<int> sub_vec(vector<int> &vec, int val)
{
    // clone a vector
    vector<int> nvec(vec);
    // sort it first
    sort(nvec.begin(), nvec.end());

    vector<int>::iterator iter;
    // find the pos marked > val
    iter =  find_if(nvec.begin(), nvec.end(), bind2nd(greater<int>(), val));

    // delete the part
    nvec.erase(iter, nvec.end());

    return nvec;
}
```



## 3.7. Using a Map

**📌Regular Operation with `map`**

The analogy of `map` in C++ in C# is `Dict< , >`.

```c++
#include <map>
#include <fstream>

// Declare a map with key:string, value:int
map<string, int> words;

// Add a key-value pair:
words["Torso"] = 1;

ifstream infile("./material/serenity_prayer.txt");
if(infile)
{
    // Suppose we want to analyze the word occurence:
    string tword;
    while(infile >> tword)
    {
        words[tword]++;
    }
}

// check the occurence
map<string, int>::iterator iter = words.begin();
for(; iter!=words.end(); iter++)
{
    cout << "key: " << iter->first
        << "value: " << iter->second << endl;
}
```

Taking into account that the syntax query a `key-value` pair, `first` refers to `key`, `second` refers to `value`.



**📌Appropriate Way Finding a Value**

Suppose you want to find out if a value is in that `map`, you may do something like this:

```c++
// NOT APPROPRIATE

map<string, int> words;

if(words["vermeer"])
{
    cout << "Exist." << endl;
}
else
{
    cout << "Not exist." << endl;
}
```

It can work but it is not appropriate❌. First, `words["vermeer"]` return some value, if it is `0`, then it is `false` as well. Therefore it could work. But the point is if there is no such key before, using statement like this will add the `key-value` pair to the `map`! 



```c++
// APPROPRIATE

map<string, int> words;
string query_word("vermeer");

if(words.count(query_word))
{
    cout << "Found. ";
    cout << "Value: " << words[query_word] << endl;
}
else
{
    cout << "Not found.";
}
```

The preceding method using `map.count()` will return the occurrence but it will not add an empty key.✔



```c++
// APPROPRIATE

map<string, int> words;
map<string, int>::const_iterator iterator;
// Find such word,
// if found=> that iterator
// if not found => the end() iterator
iterator = words.find("vermeer");
if(iterator!=words.end())
{
    cout << "Found.";
    cout << "Value: " << iterator->second << endl;
}
else
{
    cout << "Not found." << endl;
}
```

The preceding method using `map.find()` will return the iterator at such position.✔



## 3.8. Using a Set

You know what set is...

**📌Turn a vector to set**

```c++
// init words vector
string words_array[5] = {"Daniel", "Haley", "Daniel", "Bob", "Maria"};
vector<string> words(words_array, words_array+5);
// turn vector to set
set<string> words_set(words.begin(), words.end());

for(auto w : words)
{
    cout << w << " ";
}
cout << endl;
for(auto w: words_set)
{
    cout << w << " ";
}

// OUTPUT
// Daniel Haley Daniel Bob Maria 
// Bob Daniel Haley Maria
```



**📌Insert value to set**

```c++
// arrange
string words_array[5] = {"Daniel", "Haley", "Daniel", "Bob", "Maria"};
vector<string> words(words_array, words_array+5);
string some_words[3] = {"Roma", "Milano", "Torino"};
// init set
set<string> words_set;

// insert range of array
words_set.insert(some_words, some_words+3);
// insert vector
words_set.insert(words.begin(), words.end());
// insert single element
words_set.insert("Fendi");

for(auto w : words_set)
{
    cout << w << " ";
}

// OUTPUT
// Bob Daniel Fendi Haley Maria Milano Roma Torino
```



**📌Iteration over a set**

```c++
// arrange
string words_array[7] = {"Daniel", "Haley", "Daniel", "Bob", "Maria", "Fendi", "Armani"};
set<string> words_set(words_array, words_array+7);
// loop over a set
set<string>::const_iterator iter = words_set.begin();
for(; iter!=words_set.end(); iter++)
{
    cout << *iter << " ";
}
```







## 3.9. Iterator Inserters

**📌Why should we use iterator inserter?**

In short, for saving memory! Preceding methods are good but they must be required with sufficient size of such container(iterator pos). Therefore, here comes "inserter" which <u>does not require specific size of container</u>.



**📌Common Iterator Inserters**

Parallel to container operation, the inserter works as the following:

| Container Operation | Iterator Operation |
| ------------------- | ------------------ |
| `push_back()`       | `back_inserter()`  |
| `insert()`          | `inserter()`       |
| `push_front()`      | `front_inserter()` |



**📌add a range of elements into vector using inserter** 

I think this is the primary advantage of inserters.

```c++
// ERROR, you can't push back a range❌
vector<int> ivec{1, 2, 3};
vector<int> ivec2{4, 5, 6};
ivec.push_back(ivec2);
```

Instead, you can insert range like this:

```c++
vector<int> ivec{1, 2, 3};
vector<int> ivec2{4, 5, 6};

// OK✔
copy(ivec2.begin(), ivec2.end(), back_inserter(ivec));
for(auto v : ivec)
{
    cout << v << " ";
}
```



## 3.10. iostream Iterators





```
textline: lippman danny anna
family name: lippman children: 2
textline: smith john henry frieda
family name: smith children: 3
textline: mailer tommy june
family name: mailer children: 2
textline: franz
family name:  children: 1
textline: orlen orley
family name: orlen children: 1
textline: ranier alphonse lou robert brodie
family name: ranier children: 4
Please enter a family name or q to quit lippman
The lippman family  has 2 children: danny anna 
Please enter a family name or q to quit xingxin
Sorry. The xingxin family is not currently entered.
Please enter a family name or q to quit q
The  family has 1 children: franz 
The lippman family has 2 children: danny anna 
The mailer family has 2 children: tommy june 
The orlen family has 1 children: orley 
The ranier family has 4 children: alphonse lou robert brodie 
The smith family has 3 children: john henry frieda 
```









[^1]: 假设一个大方法里面有很多小方法，这些小方法实际上非常小。<u>数据转换过程所占用的时间</u>大于<u>方法运行本身所占用的时间</u>要多，因此才要用`inline` 函数。

[^2]: A **sentinel value** (also referred to as a **flag value**, **trip value**, **rogue value**, **signal value**, or **dummy data**)[[1\]](https://en.wikipedia.org/wiki/Sentinel_value#cite_note-1) is a special [value](https://en.wikipedia.org/wiki/Value_(computer_science)) in the context of an [algorithm](https://en.wikipedia.org/wiki/Algorithm) which uses its presence as a condition of termination, typically in a [loop](https://en.wikipedia.org/wiki/Control_flow) or recursive algorithm.











































































































































