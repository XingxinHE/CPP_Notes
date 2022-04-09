#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <vector>
#include "num_sequence.h"

using namespace std;

class Fibonacci : public num_sequence
{
protected:
        static vector<int>   _elems;
        virtual void         gen_elems(int pos) const;

public:
        Fibonacci(int len = 1, int beg_pos = 1)
                :num_sequence(len, beg_pos, Fibonacci::_elems)
        {

        }
        virtual              ~Fibonacci() {};
        virtual const char*  what_am_i() const {return "Fibonacci";}
};


void Fibonacci::gen_elems(int pos) const
{
        cout << "Fibonacci::gen_elems(int pos) const;" << endl;
}

#endif