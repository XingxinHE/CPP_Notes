#ifndef _charstack_h
#define _charstack_h

#include <iostream>

class CharStack
{
private:
    int m_capacity;
    int m_count;
    char *m_pArray;
    void resize(bool isIncrement);
public:
    CharStack();
    ~CharStack();

    int size();
    bool isEmpty();
    void clear();
    void push(char input);
    char pop();
    char peek();
};


#endif
