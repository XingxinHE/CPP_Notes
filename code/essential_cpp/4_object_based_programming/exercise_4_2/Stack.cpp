/********************************/
/***********Stack.cpp************/
/********************************/

#include "Stack.h"
#include <iostream>
#include <algorithm>
#include <iterator>

inline bool
Stack::empty()
{
        return _stack.empty();
}

bool
Stack::pop(string &elem)
{
        if (empty())
        {
                return false;
        }
        elem = _stack.back();
        _stack.pop_back();
        return true;
}

inline bool
Stack::full()
{
        return _stack.size() == _stack.max_size();
}

bool
Stack::peek(string &elem)
{
        if (empty())
        {
                return false;
        }
        elem = _stack.back();
        return true;
}

bool
Stack::push(const string &elem)
{
        if (full())
        {
                return false;
        }

        _stack.push_back(elem);
        return true;
}

bool
Stack::find(string &elem)
{
        if (!elem.length() || empty())
        {
                cerr << "ERROR! The input and the stack might be empty..." << endl;
        }

        vector<string>::const_iterator it;
        it = std::find(_stack.begin(), _stack.end(), elem);

        return it != _stack.end() ? true : false;
}

int
Stack::count(string &elem)
{
        return std::count(_stack.begin(), _stack.end(), elem);
}