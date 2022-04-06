#ifndef LIBRARY_MATERIAL_H
#define LIBRARY_MATERIAL_H

#include <iostream>

using namespace std;

class LibraryMaterial
{
private:
        /* data */
public:
        LibraryMaterial();
        ~LibraryMaterial();
        virtual void print() const;
};

LibraryMaterial::LibraryMaterial()
{
        cout << "LibraryMaterial::LibraryMaterial() default constructor!" << endl;
}

LibraryMaterial::~LibraryMaterial()
{
        cout << "LibraryMaterial::~LibraryMaterial() default destructor!" << endl;
}

void LibraryMaterial::print() const
{
        cout << "LibraryMaterial::print() -- I am a LibraryMaterial Object." << endl;
}

#endif