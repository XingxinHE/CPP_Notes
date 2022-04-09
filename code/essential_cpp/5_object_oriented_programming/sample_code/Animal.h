#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
        virtual void Voice() const
        {
                cout << "Animal voice..." << endl;
        }
public:
        virtual void Name() const
        {
                cout << "Animal name..." << endl;
        }
        ~Animal();

};


#endif