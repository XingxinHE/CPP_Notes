#include <iostream>
#include <string>

using namespace std;

class Dog
{
private:
    int _age;
    string _name;
public:
    Dog(int age, string name);

    void change(Dog &d);
    
    ~Dog();
};

Dog::Dog(int age, string name)
        : _age(age), _name(name) { }

void Dog::change(Dog &d)
{
    if (this != &d)
    {
        this = &d;
    }
}

