#include <string>
#include "Person.h"

using namespace std;

// Member Initialization method
Person::Person(string _name, int _id)
: license(License(23))
{
    id = _id;
    name = _name;
}

// Person::Person(string _name, int _id)
// {
//     id = _id;
//     name = _name;
//     license = License(23);
// }

Person::Person(License _license, string _name, int _id)
{

}

Person::Person(string _name)
{
    name = _name;
}

Person::Person(int _id)
{
    id = _id;
}

Person::~Person()
{
}
