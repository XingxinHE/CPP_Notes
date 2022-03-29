#include <iostream>
#include <algorithm>
#include "Person.h"
#include "Matrix.h"
#include "Triangular.h"
#include "LessThan.h"
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

// void prog_4_6()
// {
//   Triangular trian(1, 8);
//   Triangular::iterator;

// }

int count_less_than(const vector<int> &vec, int comp)
{
  LessThan less_than(comp);

  int count = 0;
  for (int ix = 0; ix < vec.size(); ix++)
  {
    if (less_than(vec[ix]))
    {
      ++count;
    }
  }
  return count;  
}

void print_less_than(const vector<int> &vec, int comp, ostream &os = cout)
{
  LessThan less_than(comp);
  vector<int>::const_iterator iter = vec.begin();
  vector<int>::const_iterator it_end = vec.end();

  os << "elements less than " << less_than.comp_val() << endl;
  while ( (iter = find_if(iter, it_end, less_than)) != it_end)
  {
    os << *iter << ' ';
    ++iter;
  }
}


void prog_4_7()
{
  int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 
                14, 23, 67, 9, 0, 27, 55, 8, 16};
  vector<int> vec(ia, ia+16);
  int comp_val = 20;

  cout << "Number of elements less than "
       << comp_val << " are "
       << count_less_than(vec, comp_val) << endl;
  
  print_less_than(vec, comp_val);
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
  prog_4_7();
  return 0;
}