#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
        /* data */
public:
        virtual void     pop() = 0;
        virtual void     push(int num) = 0;
        virtual int     size() const;
        virtual bool    empty() const;
        virtual bool    full() const;
        virtual int     peek() const = 0;
        Stack(/* args */);
        ~Stack();
};

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}

#endif