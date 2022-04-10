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
        vector<int> _stack;
        const static int _max_size = 64;
public:
        virtual void     pop() override;
        virtual void     push(int num) override;
        int             size() const override;
        bool            empty() const override;
        bool            full() const;
        virtual int     peek() const;
        virtual int     peek(int pos) const;
        virtual ostream& print(ostream &os = cout) const;
        Peekback_Stack(int size) 
        {
                _stack.reserve(size);
        }
};

void Peekback_Stack::pop()
{
        if (this->_stack.empty())
        {
                return;
        }
        this->_stack.pop_back();
        return;
}

void Peekback_Stack::push(int num)
{
        if (this->_stack.size() + 1 > Peekback_Stack::_max_size)
        {
                return;
        }
        this->_stack.push_back(num);
        return;
}

int Peekback_Stack::size() const
{
        return this->_stack.size();
}

bool Peekback_Stack::empty() const
{
        return this->_stack.empty()? true : false;
}

bool Peekback_Stack::full() const
{
        return this->_stack.size() == Peekback_Stack::_max_size ? true : false;
}

int Peekback_Stack::peek() const
{
        return this->_stack.back();
}

int Peekback_Stack::peek(int pos) const
{
        if (pos < 0 || pos > _stack.size())
        {
                throw exception();
        }
        return int(_stack[pos]);
}

ostream& Peekback_Stack::print(ostream &os) const
{
        os << "Peekback_Stack print: " << endl;
        for(int i : _stack)
        {
                os << i << " ";
        }
        os << endl;
        return os;
}

#endif