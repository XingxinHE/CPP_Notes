#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

using namespace std;

typedef int T;

class Stack
{
private:
        const static int _max_size = 64;
protected:
        vector<T> _stack;
        
public:
        Stack(int size);
        virtual ~Stack(){}
        virtual bool pop( T& );
        virtual bool push( const T& );
        virtual bool peek( int index, T& ) const= 0;
        virtual int  size() const;
        virtual bool empty() const;
        virtual bool full() const;
        virtual ostream& print( ostream& =cout ) const;

        friend ostream& operator<< (ostream &os, const Stack &s)
        {
                return s.print(os);
        }
        
};

Stack::Stack(int size)
{
        this->_stack.reserve(size);
}

bool Stack::pop(T &num)
{
        if (this->_stack.empty())
        {
                return false;
        }
        num = this->_stack.back();
        this->_stack.pop_back();
        return true;
}

bool Stack::push(const T &num)
{
        if (this->_stack.size() + 1 > Stack::_max_size)
        {
                return false;
        }
        this->_stack.push_back(num);
        return true;
}

int Stack::size() const
{
        return this->_stack.size();
}

bool Stack::empty() const
{
        return this->_stack.empty();
}

bool Stack::full() const
{
        return this->_stack.size() == Stack::_max_size ? true : false;
}

ostream& Stack::print(ostream &os) const
{
        // TODO, print the class name as well
        os << "Stack print: " << endl;
        for(int i : _stack)
        {
                os << i << " ";
        }
        os << endl;
        return os;
}


#endif