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
        const static int _max_size;
public:
        virtual void     pop() override;
        virtual void     push(int num) override;
        int             size() const override;
        bool            empty() const override;
        bool            full() const;
        virtual int     peek() const;
        LIFO_Stack(/* args */) {}
        ~LIFO_Stack() {}
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


#endif