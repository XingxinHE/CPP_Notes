#ifndef PEEKBACK_STACK_H
#define PEEKBACK_STACK_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Stack.h"

using namespace std;

class Peekback_Stack : public Stack
{
private:
public:
        Peekback_Stack(int size) 
                :Stack(size)
        {
        }

        virtual bool peek(int index, T& output) const override;
};

bool Peekback_Stack::peek(int index, T& output) const
{
        if(empty())
        {
                return false;
        }

        output = _stack[index];
        return true;
}



#endif