#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

class Dog : public Animal
{
protected:
        virtual void Voice() const
        {
                cout << "Dog voice..." << endl;
        }
public:
        virtual void Name() const
        {
                cout << "Dog name..." << endl;
        }
        Dog(/* args */);
        ~Dog();
};

Dog::Dog()
{
        
}


#endif