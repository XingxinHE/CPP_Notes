#include <iostream>
#include "Person.h"
#include "Matrix.h"
#include "Triangular.h"
using namespace std;

// void note_4_2()
// {
//     // init person with name and id
//     Person person1("Tim", 3);
//     // init person (pass by value)
//     Person person2 = person1;
//     // modify person1, and check person2
//     // they are different(pass by value)
//     person1.id = 13;
//     cout << "Person 2 ID: " << person2.id << endl;

//     // init person with default value ctor
//     // check the default value of name
//     Person person3;
//     cout << "Person 3 Name: " << person3.name << endl;

//     // { } init style
//     Person person4{"Lorenzo", 28};
//     cout << "Person 4 Name: " << person4.name << endl;

//     // initialization that C# programmer never seen before...😂
//     Person person5 = 9;
//     cout << "Person 5 Id: " << person5.id << endl;

//     Matrix mat1(4, 4);
//     {
//         // default constructor, member-wise copy here
//         Matrix mat2 = mat1;

//         // suppose you use mat2 here..

//         // mat2 destructor applied here before leaving the bracket
//         // destruct the pointer as well!!
//     }
//     // use mat1 here...

//     // mat1 destructor applied here...
// }

void prog_4_5()
{
  int ival;
  cout << "Please enter a number: " << endl;
  cin >> ival;
  
  // example using static member
  ival = ival > Triangular::start_pos ? ival : Triangular::start_pos;

  // example using static function
  bool is_elem = Triangular::is_elem(ival);
  
}

void prog_4_6()
{
  Triangular trian(1, 8);
  Triangular::iterator;

}

class Test
{
private:
  int x, y;
public:
  Test (int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test& setX(int a) { x = a; return *this; }
  Test& setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main()
{
  Test obj1;
  obj1.setX(10).setY(20);
  obj1.print();
  return 0;
}