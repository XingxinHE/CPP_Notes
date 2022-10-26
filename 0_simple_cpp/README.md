# C++ Notes



# A. C++ Basics


## 2.Basics of C++



📌**The structure of a C++ program**

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



📌**Trigraph三字符**

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



📌**Conditional inclusion**

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



## 3.Data Type

📌**Fundamental Primitive Data Type**

| Type                  | Keywords |
| --------------------- | -------- |
| Boolean               | `bool`   |
| Character             | `char`   |
| Integer               | `int`    |
| Floating type         | `float`  |
| Double-precision type | `double` |
| Void                  | `void`   |
| Wide character        |          |



📌**What is `typedef`**

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



📌**Type decorator**

This can be conceived of as the *adjective(形容词)* of type.

- signed
- unsigned
- short
- long



📌**Frequently Used Data Type**

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



📌**`sizeof()`**

Return how many bytes will be taken of. e.g.

```c++
cout << "boolean type takes：" << sizeof(bool) << " bytes";
```

The answer is 1 Byte.



📌**Enumeration**

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



📌**Difference between `typedef` and `#define`** 

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



## 4.Variable Type

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

📌**How to declare a variable?**

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



📌**Difference among declare, define, init**

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



## 5.Scope of Variable

:star:Big picture: A trick to find out the scope of a variable - The variable only affects inside its nearest curly bracket `{}`.

📌**Local variable and Global variable**

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

📌**Initial value**

| Data Type | Initial Value |
| --------- | ------------- |
| `int`     | 0             |
| `char`    | '\0'          |
| `float`   | 0             |
| `double`  | 0             |
| `pointer` | NULL          |



## 6.Constant/Literals

There are some general knowledge listing here. In computers, there are 3 different types of integer.

> ​	Prefix

` ` nothing before a number, **decimal** - 10进制

`0` before a number, **octal** - 8进制

`0x` or `0X` before a number, **hexadecimal** - 16进制

> ​	Suffix

`U` or `u` behind a number , **unsigned** value

`L` or `l` behind a number, **long** value



📌**Integer Literals**

```c++
85         // decimal
0213       // octal
0x4b       // hexadecimal 
    
30         // integer
30u        // unsigned integer
30l        // long integer
30ul       // unsigned long integer
```



📌**Floating Literals**

A floating-point constant consists of an **integer part整数部分**, a **decimal separator小数点**, a **decimal小数部分**, and an **exponential part指数部分**. You can use either the *decimal form* or the *exponential form* to represent floating-point constants.



📌**Character Literals**

Wide character `wchar_t` , normally starts with `L` and single quote `''`	 e.g. `L'x'`

Normal character `char`, single quote,	e.g. `'x'`



📌**Escape Sequence**

:star:Big picture: What *escape character* really means is that the C++ compiler would take these character then translate to another form. For example, I wrote

```c++
std::cout << "This is escape character. \\" << std::endl;
```

The output would be

```
This is escape character. \
```

| escape character | meaning                 |
| ---------------- | ----------------------- |
| `\\`             | `\`                     |
| `\'`             | `'`                     |
| `\"`             | `"`                     |
| `\?`             | `?`                     |
| `\a`             | Alarm                   |
| `\b`             | Backspace               |
| `\f`             | Change Page             |
| `\n`             | Change Line             |
| `\r`             | Enter                   |
| `\t`             | Tab                     |
| `\v`             | Vertical Tab            |
| `\ooo`           | 1 to 3 octal            |
| `xhh...`         | One or More Hexadecimal |



📌**Define Constant**

There are **2** ways of defining constant.

1. use `#define` before compiling.
2. use `const` keyword

```c++
#include <iostream>
using namespace std;
 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{
 
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```

:star:Convention: Use **uppercase** for CONSTANT.

```c++
#include <iostream>
using namespace std;
 
int main()
{
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
```



## 7.Modifier

📌**In front of what?**

The modifier is in front of:

- `char`
- `int`
- `double`



📌**They are?**

The modifiers are: 

- `unsigned`  => for `int`, `char`
- `signed`  => for `int`, `char`
- `long ` => for `int`, `double`
- `short`  => for `int`



📌**Type qualifier**

- `const`: short for CONSTANT, can't be modified during execution
- `volatile`: ask compiler not to optimize this variable, just read from the memory. 
- `restrict`: restrict the way to read it



## 8.Storage Class

📌**What is storage class**

A storage class defines the **scope** (visibility) and **life-time** of variables and/or functions.



📌**They are ?...**

- `auto`
- `register`
- `static`
- `extern`
- `mutable`



📌**`auto`, the default**

There is no difference between following variables.

```c++
{
   int mount;
   auto int month;
}
```



📌**`register`**

The **register** storage class is used to define local variables that should be **stored in a register(寄存器)** instead of RAM.

```c++
{
   register int  miles;
}
```

It has following properties:

- usually it is small
- good at quick access such as counters
- does not 100% guarantee saving in register



📌**`static` **

:warning: The `static` in C++ is very **different** from the `static` in C#.

The **static** storage class **instructs the compiler to keep a local variable in existence during the life-time of the program** instead of creating and destroying it each time it comes into and goes out of scope. Therefore, **making local variables static allows them to maintain their values between function calls**.

Following is a very nice example:

```c++
#include <iostream>
 
// Function declaration
void func(void);
 
static int count = 10; /* Global variable */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// Function definition
void func( void )
{
    static int i = 5; // local static variable
    i++;
    std::cout << "i is " << i ;
    std::cout << " and count is " << count << std::endl;
}
```

:star: Take a careful look at `static int i = 5;`! Frankly, it loops for **10** times which it was declared for **10** times. But it increments! That's what `static` means in C++(**making local variables static allows them to maintain their values between function calls**).



📌**`extern`**

The **extern** storage class is used to give a reference of a global variable that is visible to ALL the program files.

:star: In short, `extern` is to use the same variable across different files.

File: `main.cpp`

```c++
#include <iostream>
 
int count ;
extern void write_extern();
 
int main()
{
   count = 5;
   write_extern();
}
```

File: `support.cpp`

```c++
#include <iostream>
 
extern int count;
 
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
```

You can compile it 

```bash
$ g++ main.cpp support.cpp -o write
$ ./write
Count is 5
```

In above files, there are 2 crossing variables.

Use `void write_extern()` **IN** `main.cpp` **FROM** `support.cpp`

Use `int count` **FROM** `main.cpp` **IN** `support.cpp`



📌**`mutable`**

To be continued...



📌**`thread_local` **

It deals with threads.    To be continued...



## 9.Operators

There are:

- Arithmetic Operators 算术运算符
- Relational Operators关系运算符
- Logical Operators逻辑运算符
- Bitwise Operators位运算符
- Assignment Operators赋值运算符
- Misc Operators杂项运算符



📌**Arithmetic Operators**

- `+`
- `-`
- `*`
- `/`
- `%`
- `++`
- `--`

These are no difference with most languages.



📌**Relational Operators**

- `==`
- `!=`
- `>`
- `<`
- `>=`
- `<=`

These are no difference with most languages.



📌**Logical Operators**

- `&&`
- `||`
- `!`



📌**Bitwise Operators**

- `&`, binary AND
- `|`, binary OR
- `^`, binary XOR
- `~`, binary Flip
- `<<`, left shift
- `>>`, right shift

```c++
A = 0011 1100
B = 0000 1101
    
A&B = 0000 1100
A|B = 0011 1101
A^B = 0011 0001
~A  = 1100 0011
```



📌**Assignment Operators**

- `=`
- `+=`, `-=`, `*=`, `/=`, `%=`
- `<<=` Left shift AND assignment operator.
- `>>=` Right shift AND assignment operator.
- `&=`  Bitwise AND assignment operator.
- `^=` Bitwise exclusive OR and assignment operator.
- `|=` Bitwise inclusive OR and assignment operator.



📌**Misc Operators**

- `sizeof()` , return the size of such variable
- `<condition>? X:Y` , similar to C#,  e.g. `bool gender = flag? true:false;`
- `.` and `->` can BOTH be used to reference individual members of classes, structures, and unions.
- `Cast`, cast value
- `&`,  Pointer operator `&` returns the address of a variable.
- `*`, is pointer to a variable.



## 10.Loop Types

📌**What are they?**

- `for`, `while`, `do-while`
- `break`, `continue`, `goto`



📌**The Infinite Loop**

C++ programmers use `; ;` to indicate infinity.

```c++
#include <iostream>
using namespace std;
 
int main ()
{
 
   for( ; ; )
   {
      printf("This loop will run forever.\n");
   }
 
   return 0;
}
```



## 11.Decision Making

📌**What are they?**

- `if`, `if-else`, `switch`
- `Exp1 ? Exp2 : Exp3;`



## 12.Functions

📌**Defining a Function**

```c++
return_type function_name( parameter list )
{
   body of the function
}
```



📌**Example of Defining a Function**

```c++
// function returning the max between two numbers
 
int max(int num1, int num2) 
{
   // local variable declaration
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```



📌**What's difference between declaration and definition?**

```c++
#include <iostream>
using namespace std;
 
// Function declaration, no need to specify the params. The compiler will know
int max(int, int );
 
int main ()
{
   // local variable
   int a = 100;
   int b = 200;
   int ret;
 
   // call function to calculate the max value
   ret = max(a, b);
 
   cout << "Max value is : " << ret << endl;
 
   return 0;
}
 
// Function definition, now you can write very specifically
int max(int num1, int num2) 
{
   // local variable declaration
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```



## 13.Numbers

📌**Defining Numbers in C++**

```c++
#include <iostream>
using namespace std;
 
int main () {
   // number definition:
   short  s;
   int    i;
   long   l;
   float  f;
   double d;
   
   // number assignments;
   s = 10;      
   i = 1000;    
   l = 1000000; 
   f = 230.47;  
   d = 30949.374;
   
   // number printing;
   cout << "short  s :" << s << endl;
   cout << "int    i :" << i << endl;
   cout << "long   l :" << l << endl;
   cout << "float  f :" << f << endl;
   cout << "double d :" << d << endl;
 
   return 0;
}
```



📌**Math Operations in C++**

The default math library in C++ is **cmath**.

```c++
#include <iostream>
#include <cmath>
using namespace std;
 
int main () {
   // number definition:
   short  s = 10;
   int    i = -1000;
   long   l = 100000;
   float  f = 230.47;
   double d = 200.374;

   // mathematical operations;
   cout << "sin(d) :" << sin(d) << endl;
   cout << "abs(i)  :" << abs(i) << endl;
   cout << "floor(d) :" << floor(d) << endl;
   cout << "sqrt(f) :" << sqrt(f) << endl;
   cout << "pow( d, 2) :" << pow(d, 2) << endl;
 
   return 0;
}
```



📌**Random Numbers in C++**

There are **2** ways calling random numbers:

- `rand()`, return a **pseudo** random number
- `srand()`,  throw a random number relates to time



📌**Example**

To avoid pseudo random number, you can do it like this:

- include the time component, `#include <ctime>`
- use time as the seed, `srand( (unsigned)time( NULL ) );`

```c++
#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
int main ()
{
   int i,j;
 
   // set the seed
   srand( (unsigned)time( NULL ) );
 
   /* loop 10  times */
   for( i = 0; i < 10; i++ )
   {
      // generate random number
      j= rand();
      cout <<"Number： " << j << endl;
   }
 
   return 0;
}
```



## 14.Arrays

📌**What is it?**

**Array** stores a fixed-size sequential collection of elements of the same type.



📌**Declaring Arrays**

Template of Definition:

```
type arrayName [ arraySize ];
```

Example:

```c++
double balance[10];
```



📌**Initializing Arrays**

- Initialize whole array with `{ }`

```c++
double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
```

- Initialize one element

```c++
balance[4] = 50.0;
```



📌**Accessing Array Elements**

```c++
double salary = balance[9];
```



📌**Example**

```c++
#include <iostream>
using namespace std;
 
#include <iomanip>
using std::setw;
 
int main ()
{
   int n[ 10 ]; // n is an array of 10 integers
 
   // initialize elements of array n to 0           
   for ( int i = 0; i < 10; i++ )
   {
      n[ i ] = i + 100; // set element at location i to i + 100
   }
   cout << "Element" << setw( 13 ) << "Value" << endl;
 
   // output each array element's value                   
   for ( int j = 0; j < 10; j++ )
   {
      cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
   }
 
   return 0;
}
```



📌**What is `setw()` function?**

It is for layout.  `setw(n)`,  n is number for how many spaces it should be.

```c++
cout << "Element" << setw( 13 ) << "Value" << endl;
```

It **affects the strings behind**. For example, the above code means the `Value` should be with `13` spaces. If not? Then `8` spaces will be in front of `Value`.



## 15.Arrays Advanced//TODO

https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm

//TODO

📌****

## 16.Strings

📌**The C-Style Character String**

In short, the string is terminated by a **null** character `\0`. 

```c++
//C-Style
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
//Equivalent to
char greeting[] = "Hello";
```



📌**Regular String function of C-Style Character String**

`strcpy(string s1, string s2)`

Copies string s2 into string s1.



`strcat(string s1, string s2)`

Concatenates string s2 onto the end of string s1.



`strlen(string s1)`

Returns the length of string s1.



`strcmp(string s1, string s2)`

Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.



`strchr(string s1, char ch)`

Returns a pointer to the first occurrence of character ch in string s1.



`strstr(string s1, string s2)`

Returns a pointer to the first occurrence of string s2 in string s1.



📌**Example**

```c++
#include <iostream>
#include <cstring>

using namespace std;

int main () {

   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   int  len ;

   // copy str1 into str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;

   // concatenates str1 and str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;

   // total lenghth of str1 after concatenation
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;

   return 0;
}
```



📌**The String Class in C++**

```c++
#include <iostream>
#include <string>

using namespace std;

int main () {

   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total length of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   return 0;
}
```



## 17.Pointers

In short, `pointer` is important! Use `*` to interact with pointer.

📌**Example**

```c++
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var1;
   char var2[10];
 
   cout << "Address of var1 variable: ";
   cout << &var1 << endl;
 
   cout << "Address of var2 variable: ";
   cout << &var2 << endl;
 
   return 0;
}
```

Then we have:

```
Address of var1 variable: 0xbfebd5c0
Address of var2 variable: 0xbfebd5b6
```



📌**What is pointer?**

:star:A **pointer** is a variable whose value is the address of another variable. Different from normal variable, use `*` to identify this is a pointer.

```
type *var-name;
```

A clear example:

```c++
int    *ip;    // pointer to an integer
double *dp;    // pointer to a double
float  *fp;    // pointer to a float
char   *ch     // pointer to character
```



📌**Using Pointers in C++**

In C++, using pointers have followings:

- Define a pointer variable.
- Assign the address of a variable to a pointer
- Access the value at the address available in the pointer variable

Example:

```c++
#include <iostream>

using namespace std;

int main () {
   int  var = 20;   // actual variable declaration.
   int  *ip;        // pointer variable 

   ip = &var;       // store address of var in pointer variable

   cout << "Value of var variable: ";
   cout << var << endl;

   // print the address stored in ip pointer variable
   cout << "Address stored in ip variable: ";
   cout << ip << endl;

   // access the value at the address available in pointer
   cout << "Value of *ip variable: ";
   cout << *ip << endl;

   return 0;
}
```



📌**`*` and `&`** 

`*` can:

1. it appears in pointer declaration
2. it can access the value from the pointer

`&`:

1. read the address of this variable

## 18.Advanced Pointers

📌 **`NULL` pointer**

It is a good practice to assign `null` pointer if there is no address.

```c++
int main()
{
	int* p = NULL;
	
	if (p)
	{
		cout << "Pointer is not NULL." << endl;
	}
	else
	{
		cout << "Pointer is NULL." << endl;
        cout << "The value is: " << p << endl;
	}

	return 0;
}
```

The output would be:

```
Pointer is NULL.
The value is: 00000000
```



📌**Increment Pointer**

Pointer points to the 1st element in default implicitly!! (even in an array):star:

```c++
int main()
{
	//1. Create an array and a pointer
	const int MAX = 3;
	int num_array[MAX] = { 10, 20, 30 };
	int* p_num = NULL;

	//2. The pointer always point to the 1st value
	p_num = num_array;
	cout << "Pointer address: " << p_num << endl;
	cout << "Pointer value: " << *p_num << endl;
	cout << "\n" << endl;

	//3. Increment the pointer
	for (size_t i = 0; i < MAX ; i++)
	{
		cout << "Address of num_array[" << i << "]: " << p_num << endl;
		cout << "Value of num_array[" << i << "]: " << *p_num << endl;
		cout << "\n" << endl;
		p_num++;
	}

	return 0;
}
```

The output is:

```
Pointer address: 006FFB2C
Pointer value: 10

Address of num_array[0]: 006FFB2C
Value of num_array[0]: 10

Address of num_array[1]: 006FFB30
Value of num_array[1]: 20

Address of num_array[2]: 006FFB34
Value of num_array[2]: 30
```



📌**Array of Pointers**

You may be confused by the preceding code:

```c++
const int MAX = 3;
int num_array[MAX] = { 10, 20, 30 };
int* p_num = NULL;
p_num = num_array;
```

Why :heavy_check_mark::

```c++
p_num = num_array;
```

but not:x::

```c++
p_num = &num_array;
```

`p_num` is a pointer, `num_array` is an array, if I want the pointer to point the array, I should use `&` to get the address right?:thinking:

Actually not, in C++, the name of an array is considered as a pointer!:star::star::star: The pointer points to the 1st element!



📌**Out of index**

Since an array is just a pointer points to the 1st element, therefore you can access index out of range without a warning!!:warning: Because they are merely  addresses. This is typically dangerous!

```c++
double d_array[5] = { 3.1, 2.3, 54.1, 312.21, 754.34 };
for (int i = 0; i < 8; i++)
{
    cout << "Value: " << d_array[i] << endl;
    cout << "Address: " << &d_array[i] << endl;
    cout << endl;
}
```

The output:

```
Value: 3.1
Address: 006FF800

Value: 2.3
Address: 006FF808

Value: 54.1
Address: 006FF810

Value: 312.21
Address: 006FF818

Value: 754.34
Address: 006FF820

Value: -1.0775e-269
Address: 006FF828

Value: 1.11007e-305
Address: 006FF830

Value: 4.17158e-306
Address: 006FF838
```



📌**Decrement Pointer**

Now it is much more easier to understand decrementing pointer.

```c++
int main()
{
	//1. Create an array and a pointer
	const int MAX = 3;
	int num_array[MAX] = { 10, 20, 30 };

	//2. Assign the address of last element to the pointer
	int* p_num = &num_array[MAX - 1];

	//3. Decrement the pointer
	for (int i = 2; i > -1 ; i--)
	{
		cout << "Address of num_array[" << i << "]: " << p_num << endl;
		cout << "Value of num_array[" << i << "]: " << *p_num << endl;
		cout << "\n" << endl;
		p_num--;
	}

	return 0;
}
```

The output:

```
Address of num_array[2]: 0075F730
Value of num_array[2]: 30


Address of num_array[1]: 0075F72C
Value of num_array[1]: 20


Address of num_array[0]: 0075F728
Value of num_array[0]: 10
```



📌**Difference between `Pointer` and `Pointer of Array`**

In short, 

> ​	a pointer can be modified.:heavy_check_mark:
>
> ​	a pointer of an array can't be modified:x:

Why? :thinking: Because the pointer of array is a **CONSTANT** pointer which points to the 1st element of that array. :star:

Suppose we have static array and pointer as followed:

```c++
int* ptr = NULL;
int num_array[3] = { 1, 2, 3 };
```

:one:Increment the pointer points to one array, :heavy_check_mark: ok to increment:

```c++
//1. Assign the address of the array to a pointer variable
ptr = num_array;
for (int i = 0; i < 3; i++)
{
    cout << ptr << endl;  //print the address
    cout << *ptr << endl;  //print the value that address point to
    //2. Increment the pointer
    ptr++;
}
```

Output:

```
0135FB70
1
0135FB74
2
0135FB78
3
```

:two:Increment the pointer of array itself:x:, NOT ok to increment:

```c++
for (int i = 0; i < 3; i++)
{
    cout << num_array << endl;  //print the address
    cout << *num_array << endl;  //print the value that address point to (the 1st element)
    num_array++;  //ERROR!! as num_array is a CONSTANT pointer pointing to the 1st element of that array
}
```

:three:But we can access the address directly:heavy_check_mark:

```c++
for (int i = 0; i < 3; i++)
{
    cout << num_array << endl;
    *(num_array + i) = 100+i;
    cout << *(num_array+i) << endl;
}
```

Output:

```
0135FB70
100
0135FB70
101
0135FB70
102
```

As you can see, the array(is a **CONSTANT** pointer) never change but we can access the address and modify the value.



📌**Array of Pointers**

In short, each element in that array is a pointer.

Therefore, if you really want to have a pointer for each element of that `int` array, you can use array of pointers.

```c++
//array of int
int num_array[5] = { 5, 10, 15, 20, 25 };
//array of pointers (which points to int)
int* pts_array[5];

//1. Assign the address of that integer to the pointer
for (int i = 0; i < 5; i++)
{
    pts_array[i] = &num_array[i];
}

//2. Access the pointer and value points to
for (int i = 0; i < 5; i++)
{
    cout << "Pointer: " << pts_array[i] << endl;
    cout << "Value: " << *pts_array[i] << endl;
}
```

Output:

```
Pointer: 008FF948
Value: 5
Pointer: 008FF94C
Value: 10
Pointer: 008FF950
Value: 15
Pointer: 008FF954
Value: 20
Pointer: 008FF958
Value: 25
```



📌**Pointer to Pointer**(Multiple Indirection)

One `*` stands for one pointer. Therefore, two `*` stands for pointer to pointer which is a form of multiple indirection or a chain of pointers.

```c++
//0. Declare variables
float num = 0.3;
float* p_num;
float** pp_num;

//1. Assign values
p_num = &num;
pp_num = &p_num;

//2. Print
cout << "num: " << num << endl;
cout << "p_num: " << p_num << endl;
cout << "pp_num: " << pp_num << endl;
cout << "[value] p_num: " << *p_num << endl;
cout << "[value] pp_num: " << *pp_num << endl;
```

Output:

```
num: 0.3
p_num: 008FF820
pp_num: 008FF814
[value] p_num: 0.3
[value] pp_num: 008FF820
```



📌**A pointer in a function declaration**

In short, a pointer as a parameter in a function declaration.

```c++
#include <iostream>
using namespace std;

void set_zero(int* num);

int main()
{
    //1. Init value is 100
	int number = 100;
	//2. Set as zero
	set_zero(&number);
    //3. Print
	cout << number << endl;

	return 0;
}

//the parameter is a pointer
void set_zero(int* num)
{
    //the pointer points to
	*num = 0;
}
```

I really appreciate Visual IDE's formatting which illustrates the idea properly.:smile:

The following are the same, which declare an `int` pointer and its name is `ptr`.

```c++
int* ptr;
int *ptr;
```

But! The former one is clearer. `int* ptr`, the `*` right after `int` indicates it is a pointer!

Therefore, inside the function, `*num = 0` means assign `0` to what `num` points to.



📌**Array as parameter in a function**

In C++,

```c++
#include <iostream>
using namespace std;

double cal_average(int*, int);

int main()
{
	int array[5] = { 2, 6, 8, 19, 26 };
	double val = cal_average(array, 5);
	cout << val << endl;

	return 0;
}

double cal_average(int* num_array, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += num_array[i];
	}
	return double(sum) / size;  //increase the precision of sum, otherwise will return int
}
```

In C#,

```c#
static double calAverage(int[] array)
{
    double average = (double)array.Sum() / array.Length;
    return average;
}
static void Main(string[] args)
{

    int[] numArray = { 2, 6, 8, 19, 26 };
    double avg = calAverage(numArray);
    Console.WriteLine(avg);
}
```

In comparison! 

| C++                                         | C#                                |
| ------------------------------------------- | --------------------------------- |
| use pointer                                 | does not use pointer in general   |
| set the array(also a pointer) as parameter  | set the array itself as parameter |
| no function to get the length of that array | has length property of that array |



📌**`static` shxt in a function**

Considering you want to design a function which:

1. initialize an array with random value
2. print out the random value

```c++
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int* get_random();

int main()
{
	int* ptr;
	ptr = get_random();

	for (int i = 0; i < 5; i++)
	{
		cout << "Access Value -> *(ptr + " << i << ") :";
		cout << *(ptr + i) << endl;
	}

	return 0;
}

int* get_random()
{
	int num_array[5];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		num_array[i] = rand();
		cout << "Assign Value -> num_array[" << i << "]=";
		cout << num_array[i] << endl;
	}

	return num_array;
}

```

You may find out the output is not what you desired:thinking::

```
Assign Value -> num_array[0]=7915
Assign Value -> num_array[1]=27867
Assign Value -> num_array[2]=693
Assign Value -> num_array[3]=20502
Assign Value -> num_array[4]=20821
Access Value -> *(ptr + 0) :1002325240
Access Value -> *(ptr + 1) :15988012
Access Value -> *(ptr + 2) :15988736
Access Value -> *(ptr + 3) :8483917
Access Value -> *(ptr + 4) :8463838
```

Do the following check:

```c++
int* get_random()
{
    //..
}
//add the following
int* get_random()
{
    //..
    
    //insert the following
    for (int i = 0; i < 5; i++)
	{
		cout << "**Double Check** Value -> num_array[" << i << "]=";
		cout << num_array[i] << endl;
	}
    return num_array;
}
```

The output:

```
Assign Value -> num_array[0]=7827
Assign Value -> num_array[1]=32572
Assign Value -> num_array[2]=9881
Assign Value -> num_array[3]=26152
Assign Value -> num_array[4]=4472
**Double Check** Value -> num_array[0]=7827
**Double Check** Value -> num_array[1]=32572
**Double Check** Value -> num_array[2]=9881
**Double Check** Value -> num_array[3]=26152
**Double Check** Value -> num_array[4]=4472
Access Value -> *(ptr + 0) :-74576046
Access Value -> *(ptr + 1) :18414008
Access Value -> *(ptr + 2) :18414732
Access Value -> *(ptr + 3) :1012813
Access Value -> *(ptr + 4) :992734
```

:mag: The value does not change before jumping out of the function!! See double check. But they are changed outside of the scope.

:warning:Because the array you create inside `get_random()` is not static!! Do the following changes:

```c++
int num_array[5];
//change to
static int num_array[5];
```

Please remember: **Static** elements are allocated storage **only once in a program lifetime** in static storage area.

Now the output is fine:

```
Assign Value -> num_array[0]=7977
Assign Value -> num_array[1]=2711
Assign Value -> num_array[2]=12433
Assign Value -> num_array[3]=18953
Assign Value -> num_array[4]=20190
**Double Check** Value -> num_array[0]=7977
**Double Check** Value -> num_array[1]=2711
**Double Check** Value -> num_array[2]=12433
**Double Check** Value -> num_array[3]=18953
**Double Check** Value -> num_array[4]=20190
Access Value -> *(ptr + 0) :7977
Access Value -> *(ptr + 1) :2711
Access Value -> *(ptr + 2) :12433
Access Value -> *(ptr + 3) :18953
Access Value -> *(ptr + 4) :20190
```



## 19.References

:warning:References sometimes can be easily confused with Pointers!



📌**References VS Pointers**

| References                             | Pointers                            |
| -------------------------------------- | ----------------------------------- |
| No NULL references                     | Yes NULL pointers                   |
| Cannot refer to another obj after init | Can refer to another obj after init |
| Init and create at the same time       | Init any time                       |

It's very easy to understand why there is no NULL references. Because `reference` literally means reference, if it has nothing to be referred, it makes no sense.



📌**`&`**

Use `&` to refer value.



📌**Example**

```c++
#include <iostream>
 
using namespace std;
 
int main () {
   // declare simple variables
   int    i;
   double d;
 
   // declare reference variables
   int&    r = i;
   double& s = d;
   
   i = 5;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 
   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   
   return 0;
}
```



## 20.Date&Time

Include `<ctime>` header file. Please refer to the document when you need to use it.



📌**Current Date and Time**

```c++
#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "The UTC date and time is:"<< dt << endl;
}
```



📌**Format Time using `struct` tm**

```c++
#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);

   cout << "Number of sec since January 1,1970 is:: " << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<< ltm->tm_mday << endl;
   cout << "Time: "<< 5+ltm->tm_hour << ":";
   cout << 30+ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}
```



## 21.Basic Input/Output

📌**I/O Library Header Files**

There are:

- `<iostream>`, regularly used header
- `<iomanip>`, for formatting
- `<fstream>`, services for user-controlled file processing



📌**The Standard Output Stream (cout)**

When you saw `<<` , it means the stream is flow out of the screen... :laughing:

```c++
#include <iostream>
 
using namespace std;
 
int main( )
{
   char str[] = "Hello C++";
 
   cout << "Value of str is : " << str << endl;
}
```



📌**The Standard Input Stream (cin)**

When you saw `>>` , it means the stream is flow into the screen... :laughing:

```c++
#include <iostream>
 
using namespace std;
 
int main() {
   char name[50];
 
   cout << "Please enter your name: ";
   cin >> name;
   cout << "Your name is: " << name << endl;
 
}
```



📌**The Standard Error Stream (cerr)**

Display **error** messages using `cerr` stream

```c++
#include <iostream>
 
using namespace std;
 
int main( )
{
   char str[] = "Unable to read....";
 
   cerr << "Error message : " << str << endl;
}
```



📌**The Standard Log Stream (clog)**

Display **log** messages using `clog` stream

```c++
#include <iostream>
 
using namespace std;
 
int main() {
   char str[] = "Unable to read....";
 
   clog << "Error message : " << str << endl;
}
```



## 22.Data Structure

📌**What is a structure? (`struct`)**

**Structure** is **a user-defined data type** which allows you to combine data items of different kinds.

Pseudo struct:

```
struct [structure tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  
```

Example:

```c++
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;  
```



📌**Pointers to Structures**

No difference with defining a pointer to other variables

```
struct Books *struct_pointer;
```

Use `&` to have the address of `Book1`

```
struct_pointer = &Book1;
```

Access the members of a structure using a pointer to that structure, you must use the `->` rather than `.`

```
struct_pointer->title;
```



📌**Access `struct` members with `.`**

There is no difference doing it in C#.

```c++
#include <iostream>
#include <cstring>
 
using namespace std;
 
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main() {
   struct Books Book1;        // Declare Book1 of type Book
   struct Books Book2;        // Declare Book2 of type Book
 
   // book 1 specification
   strcpy( Book1.title, "Learn C++ Programming");
   strcpy( Book1.author, "Chand Miyan"); 
   strcpy( Book1.subject, "C++ Programming");
   Book1.book_id = 6495407;

   // book 2 specification
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Yakit Singha");
   strcpy( Book2.subject, "Telecom");
   Book2.book_id = 6495700;
 
   // Print Book1 info
   cout << "Book 1 title : " << Book1.title <<endl;
   cout << "Book 1 author : " << Book1.author <<endl;
   cout << "Book 1 subject : " << Book1.subject <<endl;
   cout << "Book 1 id : " << Book1.book_id <<endl;

   // Print Book2 info
   cout << "Book 2 title : " << Book2.title <<endl;
   cout << "Book 2 author : " << Book2.author <<endl;
   cout << "Book 2 subject : " << Book2.subject <<endl;
   cout << "Book 2 id : " << Book2.book_id <<endl;

   return 0;
}
```



📌**Access `struct` member with `&`** 

```c++
#include <iostream>
#include <cstring>
 
using namespace std;
void printBook( struct Books *book );

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
int main() {
   struct Books Book1;        // Declare Book1 of type Book
   struct Books Book2;        // Declare Book2 of type Book
 
   // Book 1 specification
   strcpy( Book1.title, "Learn C++ Programming");
   strcpy( Book1.author, "Chand Miyan"); 
   strcpy( Book1.subject, "C++ Programming");
   Book1.book_id = 6495407;

   // Book 2 specification
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Yakit Singha");
   strcpy( Book2.subject, "Telecom");
   Book2.book_id = 6495700;
 
   // Print Book1 info, passing address of structure
   printBook( &Book1 );

   // Print Book1 info, passing address of structure
   printBook( &Book2 );

   return 0;
}

// This function accept pointer to structure as parameter.
void printBook( struct Books *book ) {
   cout << "Book title : " << book->title <<endl;
   cout << "Book author : " << book->author <<endl;
   cout << "Book subject : " << book->subject <<endl;
   cout << "Book id : " << book->book_id <<endl;
}
```



📌**What is the difference?**

1.Function declaration

```c++
void printBook( struct Books book );
```

```c++
void printBook( struct Books *book );
```

2.Calling function

```c++
printBook( Book1 );
```

```c++
printBook( &Book1 );
```

3.Access member

```c++
cout << "Book subject : " << book.subject <<endl;
```

```c++
cout << "Book subject : " << book->subject <<endl;
```



📌**The `typedef` Keyword**

You can use `typedef` to define a `struct`.

Before:

```c++
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
```

```c++
struct Books Book1;        // Declare Book1 of type Book
struct Books Book2;  
```

After:

```c++
typedef struct {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Books;
```

```c++
Books Book1, Book2;
```



📌**Misc of `typedef`**

You can also use `typedef` in non-structs:

```c++
typedef long int *pint32;
 
pint32 x, y, z;
```

`x`,`y`,`z` are all pointers to `long` `int`.



# B. C++ Object Oriented

## 1.Classes&Objects

📌**How to define a class?**

```c++
class ClassName
{
  	Access specifiers:
    		Date members/variables;
    		Member functions(){}
    
};
```

- access specifiers are: `private`, `public`, `protected`
- variables(members) are fields in C#
- :warning:different from C#, there should be a `;` at the end of class declaration.



📌**Example of class definition**

```c++
class Box
{
   public:
      double length;   // Box's length
      double breadth;  // Box's breadth
      double height;   // Box's height
};
```



📌**Define C++ Objects(Create Instance)**

```c++
Box Box1;          // Declare Box1 of type Box
Box Box2;          // Declare Box2 of type Box
```



📌**Accessing the Data Members**

If the members are decorated with `public`, you can access them via `.`

```c++
#include <iostream>

using namespace std;

class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
};

int main() {
   Box Box1;        // Declare Box1 of type Box
   Box Box2;        // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;

   // box 2 specification
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;
   
   // volume of box 1
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Volume of Box2 : " << volume <<endl;
   return 0;
}
```

## 2.Advanced Classes//TODO

https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm

## 3.Inheritance

📌**Base and Derived Classes**

Similar to C#, you can also have inheritance in C++.

```c++
class derived_class: access-specifier base_class
```

Example:

```c++
#include <iostream>
 
using namespace std;

// Base class
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
   //protected member can be inherited by derived class   
   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
```



📌**Access Control and Inheritance**

The following is the table illustrating the access among `public`, `protected`, and `private`.

|     Access      | public | protected | private |
| :-------------: | :----: | :-------: | :-----: |
|   Same class    |  yes   |    yes    |   yes   |
| Derived classes |  yes   |    yes    |   no    |
| Outside classes |  yes   |    no     |   no    |

A derived class inherits all base class methods with the following exceptions −

- Constructors, destructors and copy constructors of the base class.
- Overloaded operators of the base class.
- The friend functions of the base class.

//TODO Please explain above 3 conditions.



📌**Type of Inheritance**

In practice, the frequency of use are:

`public` : commonly used :arrow_double_up::arrow_double_up::arrow_double_up:

`protected`&`private` : hardly used :arrow_double_up:



:arrow_right: **Public Inheritance**

```c++
class DerivedClass: public BaseClass
```

| BaseClass           | Transform:arrow_right: | DerivedClass                                                 |
| ------------------- | ---------------------- | ------------------------------------------------------------ |
| `public` members    | :arrow_right:          | still `public`                                               |
| `protected` members | :arrow_right:          | still `protected`                                            |
| `private` members   | :arrow_right:          | can't be accessed directly, but it can be access via `public`/`protected` function |



:arrow_right: **Protected Inheritance**

```c++
class DerivedClass: protected BaseClass
```

| BaseClass           | Transform:arrow_right: | DerivedClass                                                 |
| ------------------- | ---------------------- | ------------------------------------------------------------ |
| `public` members    | :arrow_right:          | become `protected`                                           |
| `protected` members | :arrow_right:          | still `protected`                                            |
| `private` members   | :arrow_right:          | can't be accessed directly, but it can be access via `protected` function |



:arrow_right: **Private Inheritance**

```c++
class DerivedClass: private BaseClass
```

| BaseClass           | Transform:arrow_right: | DerivedClass     |
| ------------------- | ---------------------- | ---------------- |
| `public` members    | :arrow_right:          | become `private` |
| `protected` members | :arrow_right:          | become `private` |
| `private` members   | :arrow_right:          | still `private`  |



📌**Multiple Inheritance**

A C++ Class can inherit members from more than one class!

```c++
class DerivedClass: access baseA, access baseB....
```

Example:

```c++
#include <iostream>

using namespace std;

// Base class Shape
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};

// Base class PaintCost
class PaintCost {
   public:
      int getCost(int area) {
         return area * 70;
      }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
      int getArea() {
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();
   
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}
```



## 4.Overloading

Overloading has no difference with its concept in C#. The elements can be overloaded are:

- function
- operator

📌**Function Overloading**

The params vary in the function declaration. See the `print()` function, it can receive `int`, `double`, and `char*`.

```c++
#include <iostream>
using namespace std;
 
class printData {
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }
      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }
      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

int main(void) {
   printData pd;
 
   // Call print to print integer
   pd.print(5);
   
   // Call print to print float
   pd.print(500.263);
   
   // Call print to print character
   pd.print("Hello C++");
 
   return 0;
}
```



📌**Operator Overloading**

Operator overloading can be defined like this:

```c++
// case 1
Box operator+(const Box&);
// case 2
Box operator+(const Box&, const Box&);
```

:question: What is the difference above?

- The former is defined as a **member** function.

- The latter is defined as **non-member** function of a class.



:book: Example:

```c++
#include <iostream>
using namespace std;

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }
      
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
      
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   return 0;
}
```

:mag: Take a deep look on these code

```c++
Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
```

Because `length`, `breadth`, and `height` are defined as `private` members. Therefore, you can use the first operator overloading mode. 

See this line `box.length = this->length + b.length;` 

`this->length`  means the length of this instance! 

`(const Box& b)`  means the **reference** the object `b`. You can see `&` as `ref` in C#. 

`return box` means in the end the operation will return a new Box.



📌**Overloadable/Non-overloadable Operators**

Following is the list of operators which can be overloaded −

| +    | -    | *    | /      | %      | ^         |
| ---- | ---- | ---- | ------ | ------ | --------- |
| &    | \|   | ~    | !      | ,      | =         |
| <    | >    | <=   | >=     | ++     | --        |
| <<   | >>   | ==   | !=     | &&     | \|\|      |
| +=   | -=   | /=   | %=     | ^=     | &=        |
| \|=  | *=   | <<=  | >>=    | []     | ()        |
| ->   | ->*  | new  | new [] | delete | delete [] |



Following is the list of operators, which can not be overloaded −

| ::   | .*   | .    | ?:   |
| ---- | ---- | ---- | ---- |



## 5.Advanced Overloading //TODO

https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

📌****





## 6.Polymorphism 

In Chinese, polymorphism is 多态。 In short, polymorphism is just a concept playing with `virtual`, `override`, etc. Very similar in C#! Nothing particular to be scared.



📌**Example of `virtual` function** 

```c++
#include <iostream> 
using namespace std;

class Shape {
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    }
    virtual int area() {
        cout << "Parent class area :" << endl;
        return 0;
    }
};
class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) :Shape(a, b) { }

    int area() {
        int area = (width * height);
        cout << "Rectangle class area : " << area << endl;
        return area;
    }
};

class Triangle : public Shape {
public:
    Triangle(int a = 0, int b = 0) :Shape(a, b) { }

    int area() {
        int area = (width * height / 2);
        cout << "Triangle class area :" << area << endl;
        return area;
    }
};

// Main function for the program
int main() {
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle  tri(10, 5);

    // store the address of Rectangle
    shape = &rec;

    // call rectangle area.
    shape->area();

    // store the address of Triangle
    shape = &tri;

    // call triangle area.
    shape->area();

    return 0;
}
```

The outputs are:

```
Rectangle class area : 70
Triangle class area :25
```



:+1: Several interesting things can be mentioned:

1.Function only with`virtual` can be overwritten in derived class

```c++
//in Base Class

//Function can be overrided
virtual int area() 
{
    cout << "Parent class area :" << endl;
    return 0;
}

//Function can't be overrided
int area() 
{
    cout << "Parent class area :" << endl;
    return 0;
}
```

2.You can explicitly write `override` or not. FYI, the position of `override` is **different** from C#.

```c++
//in derived class..

//Override implicitly
int area() 
{
    int area = (width * height / 2);
    cout << "Triangle class area :" << area << endl;
    return area;
}
//Override explicitly
int area() override
{
    int area = (width * height / 2);
    cout << "Triangle class area :" << area << endl;
    return area;
}
```

:star:3.Interesting way using pointer as a way of polymorphism

```c++
Shape* shape;
Rectangle rec(10, 7);
Triangle  tri(10, 5);

shape = &rec;
shape->area();

shape = &tri;
shape->area();
```

One pointer variable can call different functions based on the address of derived class. That's polymorphism!!



📌**early binding & late binding**

These 2 concepts are in together. 

early binding + static linkage VS late binding + dynamic linkage

`BaseClass`+no virtual specifier function -> `DerivedClass` early binding + static linkage

`BaseClass`+`virtual` specifier function -> `DerivedClass` late binding + dynamic linkage



📌**What is Pure Virtual Functions?**

Function has no body and following virtual function will be called **pure virtual function**.

```c++
virtual int area() = 0;
```





## 7.Abstraction

Alright, what is this so-called abstraction? It is a philosophy playing `public` and `private` data. In the meantime, it is art of constructing `api` and `datastructure`.  



📌**Data Abstraction Example**

```c++
#include <iostream>
using namespace std;

class Adder {
   public:
      // constructor
      Adder(int i = 0) {
         total = i;
      }
      
      // interface to outside world
      void addNum(int number) {
         total += number;
      }
      
      // interface to outside world
      int getTotal() {
         return total;
      };
      
   private:
      // hidden data from outside world
      int total;
};

int main() {
   Adder a;
   
   a.addNum(10);
   a.addNum(20);
   a.addNum(30);

   cout << "Total " << a.getTotal() <<endl;
   return 0;
}
```



From above code, we know that `addNum()` and `getTotal()` are exposed to user. :star:They don't need to know the fundamental logic behind. That's the power of **interface**.

|            | Interface          | Body               |
| ---------- | ------------------ | ------------------ |
| User       | :heavy_check_mark: | :x:                |
| Programmer | :heavy_check_mark: | :heavy_check_mark: |

:thinking: You may ask what is so good of this shit? The answer is, user only needs to know the interface for instance:

```c++
void DogBarking();
```

The user only needs to use it as it is. But programmer can modify as:

```c++
//Function before
void DogBarking()
{
    cout << "Wang! Wang! Wang!" << endl;
}
//Function after
void DogBarking()
{
    cout << "Waong! Waong! Waong!" << endl;
}
```

Programmer will update all the shit, the user only needs to know how to use it. Simple!



📌**Designing Strategy**

*Abstraction* **separates** code into **interface** and **implementation**. So while designing your component, you:warning: **must keep interface independent of the implementation**:warning:.

In this case whatever programs are using these interfaces, they would not be impacted and would just need a recompilation with the latest implementation.



## 8.Data Encapsulation

OK, another "new" concept. What the heck is encapsulation? Don't be afraid man, you have already learned everything in C# although you don't know the definition of *encapsulation*. You are already doing it!



📌**Fundamental Elements in C++ Program**

- :one: **Program statements (code)** − This is the part of a program that performs actions and they are called functions.
- :two: **Program data** − The data is the information of the program which gets affected by the program functions.



📌**What is encapsulation?**

[`data`:heavy_plus_sign:`functions` ]

Encapsulation is an Object Oriented Programming concept that **binds together the data and functions that manipulate the data**, and that keeps both safe from outside interference and misuse. 



📌**What is `data encapsulation` & `data abstraction`?**

**Data encapsulation** led to the important OOP concept of **data hiding**.

**Data abstraction** is a mechanism of **exposing only the interfaces** and **hiding the implementation** details from the user.



📌**What is the tool to tackle encapsulation?**

Nothing mysterious! Just `public`, `protected`, and `private`!



📌**Designing Strategy**

Most of us have learnt to make class members `private` by default unless we really need to expose them. That's just good **encapsulation**.

This is applied most frequently to data members, but it applies equally to all members, including virtual functions.



## 9.Abstract & Interfaces

📌**Achtung! Disclaimer!!**

The noun *interface* has different meaning regarding different contexts.

:one: *interface* in general and programming:

> ​	The set of operations supported by a data structure is called an **interface**. 

:two: `interface` in C++ and C# class

> ​	C#: An interface contains definitions for a group of related functionalities that a non-abstract [`class`](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/class) or a [`struct`](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/struct) :warning:**must**:warning: implement.
>
> ​	C++: An interface :warning:describes:warning: the behavior or capabilities of a C++ class without committing to a particular implementation of that class.

So you see the difference! It is super important!!



📌**Abstract Class Example in C++**

```c++
#include <iostream>
using namespace std;

//base class
class Shape
{
public:
	virtual int ComputeArea() = 0;

	void setHeight(int h)
	{
		this->height = h;
	}
	void setWidth(int w)
	{
		this->width = w;
	}
protected:
	int height;
	int width;
};

//derived class A
class Rectangle : public Shape
{
public:
	int ComputeArea() override
	{
		int area = this->width * this->height;
		cout << "Rectangle area: " << area << endl;
		return area;
	}
};

//derived class B
class Triangle : public Shape
{
public:
	int	ComputeArea() override
	{
		int area = this->width * this->height * 0.5;
		cout << "Triangle area: " << area << endl;
		return area;
	}
};

//Main function
int main()
{
	Triangle t;
	t.setHeight(10);
	t.setWidth(20);

	Rectangle r;
	r.setHeight(10);
	r.setWidth(20);

	cout << "Start computing area...\n" << endl;
	r.ComputeArea();
	t.ComputeArea();

	return 0;
}
```



📌**Difference of Abstract and Interface  in C# & C++**  :star::star::star:

This is super IMPORTANT!

|                                               | C++                                                          | C#                                                           |
| --------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Literally exist an `abstract` class           | :x:                                                          | :heavy_check_mark:                                           |
| Literally exist `interface`                   | :x:                                                          | :heavy_check_mark:                                           |
| Abstract class can't have instance            | :heavy_check_mark:Correct                                    | :heavy_check_mark:Correct                                    |
| How to know this is an abstract class         | It has at least **1** pure virtual function                  | Specify with `abstract`                                      |
| How to prevent abstract class having instance | The pure virtual function prevent instantiate objects with err | the compiler know this is `abstract` class and it prevent it |
| How to push user implement `interface`        | No `interface` literally, but it takes advantage of pure virtual function as a MUST to implement | Take advantage of `interface`, derived class must implement  |

Since C# is developed after C++, it absorbs lots feature of C++ and make it clear. You can think of 

- C#  :  explicit 

- C++  :  implicit

For instance, the concept of abstract and interface is originated in C++ but C# makes it clear.



# C.C++ Advanced

## 1.Files and Streams

📌**What are they?**

They are:

- `ofstream` - (output file stream) for output stream, create files, and write information to files
- `ifstream` - (input file stream) read information from files
- `fstream` - (both input and output) create files, write information to files, and read information from files.



📌**Opening a File**

Opening is always the first step.

:warning: A file **MUST** be opened before you can read from it or write to it. 

Typical `open` function looks like this:

```c++
void open(const char *filename, ios::openmode mode);
```

`filename` specifies the name and location of the file to be opened.

`ios::openmode` defines the mode in which the file should be opened.



📌**Model Flag & Operation**

| flag         | function                                                     |
| ------------ | ------------------------------------------------------------ |
| `ios::app`   | **Append** mode. All output to that file to be appended to the end. |
| `ios::ate`   | (*at the end*) Open a file for output and move the read/write control to the **end** of the file. |
| `ios::in`    | Open a file for **reading**.                                 |
| `ios::out`   | Open a file for **writing**.                                 |
| `ios::trunc` | If the file already exists, its contents will be **truncated** before opening the file. |



📌**Combine different flag**

```c++
//Example 1
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );

//Example 2
fstream  afile;
afile.open("file.dat", ios::out | ios::in );
```



📌**Closing a File**

A programmer should close all the opened files before program termination.

Typical `close` function in C++.

```c++
void close();
```



📌**Write to and Read from files **

`<<`  ,  this is for writing

`>>`  ,  this is for reading



📌**Read and Write Example**

```c++
#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   char data[100];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("README.md");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile; 
   infile.open("README.md"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   // write the data at the screen.
   cout << data << endl;
   
   // again read the data from the file and display it.
   infile >> data; 
   cout << data << endl; 

   // close the opened file.
   infile.close();

   return 0;
}
```



📌**File Position Pointers**

It is a function to locate the pointer at stream.

> ​	Function: These member functions are `seekg` ("seek get") for `istream` and `seekp` ("seek put") for `ostream`.

> ​	Flag to start: The second flag can be specified to indicate the seek direction.

```c++
// position to the nth byte of fileObject (assumes ios::beg)
fileObject.seekg( n );

// position n bytes forward in fileObject
fileObject.seekg( n, ios::cur );

// position n bytes back from end of fileObject
fileObject.seekg( n, ios::end );

// position at end of fileObject
fileObject.seekg( 0, ios::end );
```



## 2.Exception Handling

📌**The difference with C#**

C++ does not support `finally`, only supports the following:

- `throw, try, catch`

C# supports the following:

- `throw, try, catch, finally`



📌**`throw` example**

It is no big difference with C#.

```c++
double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
```



📌**`try-catch` solution**

- explicitly catch the exception

```c++
try
{
   // protected code
}catch( ExceptionName e )
{
  // code to handle ExceptionName exception
}
```

- implicitly catch the exception

```c++
try
{
   // protected code
}catch(...)
{
  // code to handle any exception
}
```



📌 **Example**

```c++
#include <iostream>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main () {
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
      z = division(x, y);
      cout << z << endl;
   } catch (const char* msg) {
     cerr << msg << endl;
   }

   return 0;
}
```



📌**Define New Exceptions**

```c++
#include <iostream>
#include <exception>  //the library with exception
using namespace std;

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};
 
int main() {
   try 
   {
      throw MyException();
   } 
   catch(MyException& e) 
   {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } 
   catch(std::exception& e) 
   {
      //Other errors
   }
}
```



📌****



📌****



📌****



📌****



## 3.Dynamic Memory

📌**stack & heap**

- **The stack** − All variables declared inside the function will take up memory from the stack.
- **The heap** − This is unused memory of the program and can be used to allocate the memory dynamically when program runs.



📌**`new` & `delete`**

`new`: **allocate** memory at run time within the heap for the variable and return the address of the space allocated

`delete`:  **de-allocates** memory that was previously allocated



The syntax using `new` could be:

```c++
new data-type;
```

The **data-type** could be **any built-in data type** including an array or any user defined data types include class or structure.



📌**`new` and `delete` example**

```c++
#include <iostream>
using namespace std;

int main () {
   double* pvalue  = NULL; // Pointer initialized with null
   pvalue  = new double;   // Request memory for the variable
 
   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   delete pvalue;         // free up the memory.

   return 0;
}
```



📌**Good practice of checking if `NULL`**

It is always a good practice to check the variable if it is `null`.

```c++
double* pvalue  = NULL;
if( !(pvalue  = new double )) {
   cout << "Error: out of memory." <<endl;
   exit(1);
}
```



📌**Dynamic Memory Allocation for Arrays**

In short, the `*` stands for $k$-dimensional array.

> ​	1-D Array

```c++
//dynamically allocated, the length is m
int *array=new int [m];
 
//release memory
delete [] array;
```

> ​	2-D Array

```c++
#include <iostream>
using namespace std;
 
int main()
{
    int **p;   
    int i,j;   //p[4][8] 
    //start allocating..
    //row=4, col=8
    p = new int *[4];
    for(i=0;i<4;i++){
        p[i]=new int [8];
    }
 
    for(i=0; i<4; i++){
        for(j=0; j<8; j++){
            p[i][j] = j*i;
        }
    }   
    
    //cout data...   
    for(i=0; i<4; i++){
        for(j=0; j<8; j++)     
        {   
            if(j==0) cout<<endl;   
            cout<<p[i][j]<<"\t";   
        }
    }   
    //release the heap   
    for(i=0; i<4; i++){
        delete [] p[i];   
    }
    delete [] p;   
    return 0;
}
```

> ​	3-D Array

```c++
#include <iostream>
using namespace std;
 
int main()
{   
    int i,j,k;   // p[2][3][4]
    
    int ***p;
    p = new int **[2]; 
    for(i=0; i<2; i++) 
    { 
        p[i]=new int *[3]; 
        for(j=0; j<3; j++) 
            p[i][j]=new int[4]; 
    }
    
    //cout p[i][j][k] 3D Array data
    for(i=0; i<2; i++)   
    {
        for(j=0; j<3; j++)   
        { 
            for(k=0;k<4;k++)
            { 
                p[i][j][k]=i+j+k;
                cout<<p[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    // release memory
    for(i=0; i<2; i++) 
    {
        for(j=0; j<3; j++) 
        {   
            delete [] p[i][j];   
        }   
    }       
    for(i=0; i<2; i++)   
    {       
        delete [] p[i];   
    }   
    delete [] p;  
    return 0;
}
```



📌**Dynamic Memory Allocation for Objects**

```c++
#include <iostream>
using namespace std;

class Box {
   public:
    //constructor
      Box() { 
         cout << "Constructor called!" <<endl; 
      }
    //deconstructor
      ~Box() { 
         cout << "Destructor called!" <<endl; 
      }
};
int main() {
   Box* myBoxArray = new Box[4];
   delete [] myBoxArray; // Delete array

   return 0;
}
```

The output would be:

create 4 times, delete 4 times as well.

```
Constructor called!
Constructor called!
Constructor called!
Constructor called!
Destructor called!
Destructor called!
Destructor called!
Destructor called!
```



## 4.Namespaces

The methodology behind is self-evident like in C#.

📌**Define Namespace**

Define like following:

```c++
namespace namespace_name 
{
   // code declarations
}
```

Call the function or variable like following:

```c++
namespace_name::code;  // code could be variable or function.
SimplicialComplexOperators::boundary(const MeshSubset& subset);  // an example from ddg-exercise
```



📌**Example**

```c++
#include <iostream>

using namespace std;
//Define 1st namespace
namespace first_namespace
{
	void func()
	{
		cout << "Func in first_namespace!" << endl;
	}
}
//Define 2nd namespace
namespace second_namespace
{
	void func()
	{
		cout << "Func in second_namespace!" << endl;
	}
}

int main()
{

	first_namespace::func();  //call func from 1st namespace
	second_namespace::func();  //call func from 2nd namespace

	return 0;
}
```



📌**`using` directive**

This directive tells the compiler that the subsequent code is making use of names in the specified namespace.

Suppose you have 2 functions:

```c++
namespace first_namespace
{
	void func();
}
namespace second_namespace
{
	void func();
}
```

You can explicitly use one of them:

```c++
#include <iostream>

using namespace first_namespace;

int main()
{
	func();  //this will call func from 1st namespace

	return 0;
}
```



You can also use to explicitly call one of the function, just like in python

> ​	C++:

```c++
using std::cout;
```

> ​	python:

```python
from Rhino.Geometry import Point3d
```

In both case, you don't have to explicitly use the function with namespace.

```c++
#include <iostream>
using std::cout;

int main () {
   cout << "std::endl is used with std!" << std::endl;
   
   return 0;
}
```



📌**Discontiguous Namespaces**

In short, it allows you to define functions in **different files** but in the **same namespace**.

> ​	File A.cpp:

```c++
namespace namespace_name
{
    void FuncA();
}
```

> ​	File B.cpp:

```c++
namespace namespace_name
{
    void FuncB();
}
```

> ​	File C.cpp:

```c++
using namespace namespace_name;
int main()
{
    FuncA();
    FuncB();
    return 0;
}
```



📌**Nested Namespaces**

```c++
#include <iostream>
using namespace std;

namespace out_space
{
	namespace in_space
	{
		void func()
		{
			cout << "Nested namespace." << endl;
		}
	}
}

int main()
{
	out_space::in_space::func();
	return 0;
}
```



