#ifndef TRIANGULAR_H
#define TRIANGULAR_H


#include <vector>
#include <string>
#include "Triangular_iterator.h"

using namespace std;

class Triangular
{
private:
        int _length;                // number of elements
        int _begin_pos;             // beginning position of range
        mutable int _next;                  // next element to iterate over
        static vector<int> _elems;  // static vector to store the elments
        
        typedef Triangular_iterator iterator;

        
public:

        Triangular_iterator begin() const
        {
                return Triangular_iterator(_begin_pos);
        }

        Triangular_iterator end() const
        {
                return Triangular_iterator(_begin_pos + _length);
        }

        // const member functions
        int length() const {return _length;}
        int begin_pos() const {return _begin_pos;}
        int elem(int pos) const;
        Triangular& copy(const Triangular &rhs);
        bool next (int &val) const;
        static bool is_elem(int);
        static int start_pos;

        // non-const member functions
        void next_reset() {_next = _begin_pos - 1;}

        static Triangular_iterator iterator;

        Triangular();
        Triangular(int, int);
        ~Triangular();
};

Triangular::Triangular()
{
}

Triangular::~Triangular()
{
}

vector<int> Triangular::_elems;

int sum(const Triangular &trian)
{
        int beg_pos = trian.begin_pos();
        int length = trian.length();
        int sum = 0;
        for (int ix = 0; ix < length; ix++)
        {
                sum += trian.elem(beg_pos + ix);
        }
        return sum;
}

bool Triangular::next(int &val) const
{
        if (_next < _begin_pos + _length - 1)
        {
                //ERROR: modifying _next
                val = _elems[_next++];
                return true;
        }
        return false;
}

int Triangular::elem(int pos) const
{
        return _elems[pos - 1];
}

Triangular& Triangular::copy(const Triangular &rhs)
{
        if (this != &rhs)
        {
                this->_length = rhs._length;
                this->_begin_pos = rhs._length;
                this->_next = rhs._next;
        }
        
}

#endif