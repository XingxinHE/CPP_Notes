# C++ Notes



# Table of Content



# 1.Environment Setup

:pushpin:**Text Editor**

This is where you write the source codes.

:pushpin:**C++ Compiler**

Visual Studio IDE, CMake, g++



# 2.Basics of C++

:star: Big picture: A C++ program can be seen as a set of objects where they can interact.

- Object: Object is of status and action and object is the instance of a class.
- Class: A template of any instances.
- Method: also known as a function.
- Instant Variable: the status of an object is determined by this



:pushpin:**The structure of a C++ program**

```c++
#include <iostream>
using namespace std;
 
// main() is the MAIN entry of a C++ program
 
int main()
{
   cout << "Hello World"; // output Hello World
   return 0;
}
```

- header`#include <iostream>`, the decoration at the beginning of the `.cpp` file. It is either a library or a header file `.h`
- namespace `using namespace std`, tell the compiler which namespace to use
- main function`int main()`, the main function is a `int` type function.
- return value`return 0`, it means this program runs successfully.



:pushpin:**Identifier**

The name you assign in C++.



:pushpin:**Keywords**

They are reserved by C++ program which you are not allowed to name the identifier like this. 

The full keywords list is:

https://docs.microsoft.com/en-us/cpp/cpp/keywords-cpp?view=msvc-160



:pushpin:**Trigraph三字符**

What is the purpose of trigraph?

> ​	Convert some symbols to other symbols.(For some keyboard missing some symbols)

What is trigraph anyway?

> ​	Trigraph always starts with `??` which implies this is a trigraph. And it takes the *3* symbols into *1* symbol.

| Trigraph | Result |
| -------- | ------ |
| ??=      | #      |
| ??/      | \      |
| ??'      | ^      |
| ??(      | [      |
| ??)      | ]      |
| ??!      | \|     |
| ??<      | {      |
| ??>      | }      |
| ??-      | ~      |

:warning:Trigraph is deprecated function of C++. If you compile in VS IDE, the warning will be prompted.



:pushpin:**Space in C++**

Not like shell scripting, the space in C++ will be ignored.



:pushpin:**Comments**

Single line comment

```c++
//Single line comment
```

Block of comments

```c++
/*
 * This is a block of comments
 *
 */
```



:pushpin:**Conditional inclusion**

It uses `#ifdef`

```c++
#define ABCD 2
#include <iostream>
 
int main()
{

    //check something is defined?
    #ifdef ABCD
        std::cout << "1: yes\n";
    #else
        std::cout << "1: no\n";
    #endif

    //check something is NOT defined?
    #ifndef ABCD
        std::cout << "2: no1\n";
    #elif ABCD == 2
        std::cout << "2: yes\n";
    #else
        std::cout << "2: no2\n";
    #endif

    //check logic AND
    #if !defined(DCBA) && (ABCD < 2*4-3)
        std::cout << "3: yes\n";
    #endif
}
```

The output will be

```
1: yes
2: yes
3: yes
```



# 3.Data Type

:pushpin:**Fundamental Primitive Data Type**

| Type                  | Keywords |
| --------------------- | -------- |
| Boolean               | `bool`   |
| Character             | `char`   |
| Integer               | `int`    |
| Floating type         | `float`  |
| Double-precision type | `double` |
| Void                  | `void`   |
| Wide character        |          |



:pushpin:**What is `typedef`**

It literally define a type with custom name. The syntax is 

```c++
typedef <type> <new_name>;
```

e.g. `wchar_t` is combined with `short` and `int`.

```c++
typedef short int wchar_t;
```

e.g. you can rename `int`. Now `feet` and `int` are the same.

```c++
typedef int feet;
feet age;
```



:pushpin:**Type decorator**

This can be conceived of as the *adjective(形容词)* of type.

- signed
- unsigned
- short
- long



:pushpin:**Frequently Used Data Type**

| Type                 | Length      | Range                                                        |
| -------------------- | ----------- | ------------------------------------------------------------ |
| `char`               | 1 Byte      | -128 to 127 or 0 to 255                                      |
| `unsigned char`      | 1 Byte      | 0 to 255                                                     |
| `signed char`        | 1 Byte      | -128 to 127                                                  |
| `int`                | 4 Byte      | -2147483648 to 2147483647                                    |
| `unsigned int`       | 4 Byte      | 0 to 4294967295                                              |
| `signed int`         | 4 Byte      | -2147483648 to 2147483647                                    |
| `short int`          | 2 Byte      | -32768 to 32767                                              |
| `unsigned short int` | 2 Byte      | 0 to 65,535                                                  |
| `signed short int`   | 2 Byte      | -32768 to 32767                                              |
| `long int`           | 8 Byte      | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807      |
| `signed long int`    | 8 Byte      | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807      |
| `unsigned long int`  | 8 Byte      | 0 to 18,446,744,073,709,551,615                              |
| `float`              | 4 Byte      | 4 Byte（32-bits），+/- 3.4e +/- 38 (~7 characters long number) |
| `double`             | 8 Byte      | 8 Byte（6-bits），+/- 1.7e +/- 308 (~15 characters long number) |
| `long double`        | 16 Byte     | 16 Byte（128-bits），18-19 characters long number            |
| `wchar_t`            | 2 or 4 Byte | 1 wide character                                             |



:pushpin:**`sizeof()`**

Return how many bytes will be taken of. e.g.

```c++
cout << "boolean type takes：" << sizeof(bool) << " bytes";
```

The answer is 1 Byte.



:pushpin:**Enumeration**

It is a set of enumerated constants.

The pattern declaring `enum` is:

```c++
enum enum_name{identifier1, identifier2, identifier3} var_name;
```

Therefore, you can declare an `enum` like this:

```c++
enum color { red, green, blue } c;
c = blue;
```

The default constant for the elements start from 0,1,2,...n. But you can also overwrite this default values.

```c++
enum color { red, green=5, blue };
```



:pushpin:**Difference between `typedef` and `#define`** 

> ​	1.Different in execute time

`typedef` executes in compiling therefore `type-check` will be associated.

`#define` is a macro. It executes in linking. It literally replace A to B.

```c++
typedef unsigned int UINT;
 
void func()
{
    UINT value = "abc"; // error C2440: 'initializing' : cannot convert from 'const char [4]' to 'UINT'
    cout << value << endl;
}
```

```c++
// #define example
#define f(x) x*x
int main()
{
    int a=6, b=2, c;
    c=f(a) / f(b);
    printf("%d\n", c);
    return 0;
}
```

> ​	2.Different in their function

`typedef` define the **alias** of something, its definition is not relevant to the data type.

`#define` not only can giving an **alias** but also can define **constant, variable, option of compile**.

> ​	3.Different in their scope

`typedef` has its own scope.

`#define` does not have a scope.

```c++
//typedef only affect its scope
void method1()
{
    typedef unsigned int UINT;
}
 
void method2()
{
    UINT uValue = 5;//error C2065: 'UINT' : undeclared identifier
}
```

```c++
//  #define can apply out of its scope
void method1()
{
    #define HW "HelloWorld";
}
 
void method2()
{
    string str = HW;
    cout << str << endl;
}
```

> 	4. Different in pointers

```c++
typedef int * pint;
#define PINT int *
 
int i1 = 1, i2 = 2;
 
const pint p1 = &i1;    //change of p[X], what p points to[√],  equivalent to int * const p;
const PINT p2 = &i2;    //change of p[√]，what p points to[X], equivalent to const int *p；or int const *p；
 
pint s1, s2;    //s1 and s2 are of pointer 
PINT s3, s4;    //equivalent to int * s3，s4; there is only 1 pointer
 
void TestPointer()
{
    cout << "p1:" << p1 << "  *p1:" << *p1 << endl;
    //p1 = &i2; //error C3892: 'p1' : you cannot assign to a variable that is const
    *p1 = 5;
    cout << "p1:" << p1 << "  *p1:" << *p1 << endl;
 
    cout << "p2:" << p2 << "  *p2:" << *p2 << endl;
    //*p2 = 10; //error C3892: 'p2' : you cannot assign to a variable that is const
    p2 = &i1;
    cout << "p2:" << p2 << "  *p2:" << *p2 << endl;
}
```



# 4.Variable Type

A variable is really nothing more than the name of a storage area. Each variable in C++ has a specified type, and the type determines the size and location of the variable's storage. 

| Type      | Description              |
| --------- | ------------------------ |
| `bool`    | either `true` or `false` |
| `char`    | 1 byte(8 bits)           |
| `int`     |                          |
| `float`   |                          |
| `double`  |                          |
| `void`    |                          |
| `wchar_t` |                          |

:pushpin:**How to declare a variable?**

> ​	The syntax is following:

```c++
type variable_name;  //declare but not init
type variable_name = value;  //declare + init
```

> ​	declare

```c++
int    i, j, k;
char   c, ch;
float  f, salary;
double d;
```

> ​	declare + init

```c++
extern int d = 3, f = 5;
int d = 3, f = 5;
byte z = 22;
char x = 'x';
```



:pushpin:**Difference among declare, define, init**

From top to bottom, they are `declare`->`define`  -> `init`.

```c++
#include <iostream>
using namespace std;
 
// declare
extern int a, b;
extern int c;
extern float f;
  
int main ()
{
  // define
  int a, b;
  int c;
  float f;
 
  // init
  a = 10;
  b = 20;
  c = a + b;
 
  return 0;
}
```

**"declare"** can not only apply to this `.cpp` file but others file in one program! 

You can see `extern` as telling the compiler that I will have a variable called `xxx` but I don't know where I will use it.



# 5.Scope of Variable

:star:Big picture: A trick to find out the scope of a variable - The variable only affects inside its nearest curly bracket `{}`.

:pushpin:**Local variable and Global variable**

> ​	Local

```c++
#include <iostream>
using namespace std;
 
int main ()
{
  // declare/define local variable
  int a, b;
  int c;
 
  // init
  a = 10;
  b = 20;
  c = a + b;
 
  cout << c;
 
  return 0;
}
```

> ​	Global

```c++
#include <iostream>
using namespace std;
 
// declare global variable
int g;
 
int main ()
{
  // declare local
  int a, b;
 
  // init
  a = 10;
  b = 20;
  g = a + b;
 
  cout << g;
 
  return 0;
}
```

> ​	:warning: Unlike C#, you can declare one variable twice in global and local scope. BUT! The local will overwrite global one.

:pushpin:**Initial value**

| Data Type | Initial Value |
| --------- | ------------- |
| `int`     | 0             |
| `char`    | '\0'          |
| `float`   | 0             |
| `double`  | 0             |
| `pointer` | NULL          |



# 6.Constant

There are some general knowledge listing here. In computers, there are 3 different types of integer.

> ​	Prefix

` ` nothing before a number, **decimal** - 10进制

`0` before a number, **octal** - 8进制

`0x` or `0X` before a number, **hexadecimal** - 16进制

> ​	Suffix

`U` or `u` behind a number , **unsigned** value

`L` or `l` behind a number, **long** value



:pushpin:**Integer Constant**

```c++
85         // decimal
0213       // octal
0x4b       // hexadecimal 
    
30         // integer
30u        // unsigned integer
30l        // long integer
30ul       // unsigned long integer
```



:pushpin:**Floating Constant**

A floating-point constant consists of an **integer part整数部分**, a **decimal separator小数点**, a **decimal小数部分**, and an **exponential part指数部分**. You can use either the *decimal form* or the *exponential form* to represent floating-point constants.

When using the fractional form, you must include the integer part, the fractional part, or both. When using exponential form, you must include the decimal part, the exponent, or both. The signed exponent is introduced with e or E.







:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



:pushpin:****



