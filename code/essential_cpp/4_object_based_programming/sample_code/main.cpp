#include <iostream>
#include "Person.h"
using namespace std;

void note_4_2()
{
    // init person with name and id
    Person person1("Tim", 3);
    // init person (pass by value)
    Person person2 = person1;
    // modify person1, and check person2
    // they are different(pass by value)
    person1.id = 13;
    cout << "Person 2 ID: " << person2.id << endl;

    // init person with default value ctor
    // check the default value of name
    Person person3;
    cout << "Person 3 Name: " << person3.name << endl;

    // { } init style
    Person person4{"Lorenzo", 28};
    cout << "Person 4 Name: " << person4.name << endl;

    // initialization that C# programmer never seen before...😂
    Person person5 = 9;
    cout << "Person 5 Id: " << person5.id << endl;
}

int main()
{
    note_4_2();

    return 0;
}