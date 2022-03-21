#include <string>
#include "License.h"
using namespace std;

class Person
{
private:
    License license;
public:
    int id;
    string name;
    //Person();  This can be deprecated because we have a default values ctor
    Person(int _id);
    Person(string _name);
    Person(string _name = "Ada", int _id = 0);
    Person(License license, string _name = "Ada", int _id = 0);
    ~Person();
};