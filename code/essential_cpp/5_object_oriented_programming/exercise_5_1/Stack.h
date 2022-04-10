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
        virtual         ~Stack() {};
        virtual void     pop() = 0;
        virtual void     push(int num) = 0;
        virtual int     size() const = 0;
        virtual bool    empty() const = 0;
        virtual bool    full() const = 0;
        virtual int     peek() const = 0;
        virtual ostream& print(ostream&os = cout) const = 0;

        friend ostream& operator<< (ostream &os, const Stack &s)
        {
                return s.print(os);
        }
        
};



#endif