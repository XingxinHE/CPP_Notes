#ifndef LIFO_STACK_H
#define LIFO_STACK_H

#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;

class LIFO_Stack : public Stack
{
private:
public:
        
        LIFO_Stack(int size) 
                :Stack(size)
        {
        }

        virtual bool peek( int index, T& ) const override;
};

bool LIFO_Stack::peek(int index, T& output) const
{
        return false;
}

#endif