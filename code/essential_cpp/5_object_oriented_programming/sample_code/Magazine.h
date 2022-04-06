#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <iostream>
#include "LibraryMaterial.h"

using namespace std;

class Magazine : public LibraryMaterial
{
private:
        
public:
        Magazine(/* args */);
        ~Magazine();
};

Magazine::Magazine(/* args */)
{
}

Magazine::~Magazine()
{
}

#endif