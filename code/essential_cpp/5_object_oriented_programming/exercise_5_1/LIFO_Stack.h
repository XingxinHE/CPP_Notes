#ifndef LIFO_STACK_H
#define LIFO_STACK_H

#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;

class LIFO_Stack : public Stack
{
private:
        vector<int> _stack;
        const static int _max_size = 64;
public:
        virtual void     pop() override;
        virtual void     push(int num) override;
        int             size() const override;
        bool            empty() const override;
        bool            full() const;
        virtual int     peek() const;
        virtual ostream& print(ostream &os = cout) const;
        LIFO_Stack(int size) 
        {
                _stack.reserve(size);
        }
};



void LIFO_Stack::pop()
{
        if (this->_stack.empty())
        {
                return;
        }
        this->_stack.pop_back();
        return;
}

void LIFO_Stack::push(int num)
{
        if (this->_stack.size() + 1 > LIFO_Stack::_max_size)
        {
                return;
        }
        this->_stack.push_back(num);
        return;
}

int LIFO_Stack::size() const
{
        return this->_stack.size();
}

bool LIFO_Stack::empty() const
{
        return this->_stack.empty()? true : false;
}

bool LIFO_Stack::full() const
{
        return this->_stack.size() == LIFO_Stack::_max_size ? true : false;
}

int LIFO_Stack::peek() const
{
        return this->_stack.back();
}

ostream& LIFO_Stack::print(ostream &os) const
{
        os << "print: " << endl;
        for(int i : _stack)
        {
                os << i << " ";
        }
        os << endl;
        return os;
}


#endif