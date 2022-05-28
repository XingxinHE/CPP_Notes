/*
 * File: charstack.cpp
 * -------------------
 * This file implements the CharStack class.
 */

#include "charstack.h"

/*
* Implementation notes: CharStack constructor
* -------------------------------------------
* The constructor must allocate the array storage for the stack elements
* and initialize the fields of the object.
*/
CharStack::CharStack()
          :m_count(0), m_capacity(INITIAL_CAPACITY)
{
    m_pArray = new char[m_capacity];
}

CharStack::CharStack(const CharStack &src)
{
    deepCopy(src);
}



/*
* Implementation notes: ~CharStack
* --------------------------------
* The destructor frees any heap memory allocated by the class, which
* is just the dynamic array of elements.
*/
CharStack::~CharStack()
{
    delete[] m_pArray;
}



/*
* Implementation notes: size, isEmpty, clear
* ------------------------------------------
* These methods are each a single line and need no detailed documentation.
* Note that size and isEmpty leave the stack unchanged and are therefore
* marked as const.
*/
bool CharStack::isEmpty() const
{
    return m_count == 0;
}

int CharStack::size() const
{
    return m_count;
}

void CharStack::clear()
{
    if (m_pArray != nullptr)
    {
        delete[] m_pArray;
        m_count = 0;
        m_pArray = new char[m_capacity];
    }
}



/*
* Implementation notes: push
* --------------------------
* This function must first check to see whether there is enough room for
* the character and expand the array storage if necessary.
*/
void CharStack::push(char input)
{
    if (m_count == m_capacity)
    {
        resize(true);
    }
    m_pArray[m_count++] = input;
}



/*
* Implementation notes: pop, peek
* -------------------------------
* These functions must check for an empty stack and report an
* error if there is no top element.
*/
char CharStack::peek() const
{
    if(!isEmpty())
    {
        char item = m_pArray[m_count-1];
        return item;
    }
    else
    {
        return '\0';
    }
}

char CharStack::pop()
{
    if(!isEmpty())
    {
        char item = m_pArray[--m_count];
        if (m_count < (int(0.5 * m_capacity)))
        {
            resize(false);
        }
        return item;
    }
    else
    {
        return '\0';
    }
}


/*
* Operator: =
* Usage: s1 = s2;
* ---------------
* Assigns s2 to s1 so that the two stacks function as independent copies.
* For the CharStack class, this kind of assignment requires making a
* deep copy that includes the dynamic array.
*/
CharStack & CharStack::operator=(const CharStack &src)
{
    if (this != &src)
    {
        delete[] m_pArray;
        deepCopy(src);
    }
    return *this;
}



/*
* Implementation notes: resize
* ----------------------------
* This private method doubles OR shrink the capacity of the elements array
* whenever it runs out of space. To do so, it must copy the pointer to the old
* array, allocate a new array with twice the capacity, copy the characters
* from the old array to the new one, and finally free the old storage.
*/
void CharStack::resize(bool isIncrement)
{
    if (isIncrement)
    {
        char *oldPtr = m_pArray;
        m_capacity *= 2;
        m_pArray = new char[m_capacity];
        for (int i = 0; i < m_count; i++)
        {
            m_pArray[i] = oldPtr[i];
        }
        delete[] oldPtr;
    }
    else
    {
        char *oldPtr = m_pArray;
        m_capacity = int(0.5 * m_capacity);
        m_pArray = new char[m_capacity];
        for (int i = 0; i < m_count; i++)
        {
            m_pArray[i] = oldPtr[i];
        }
        delete[] oldPtr;
    }
}



/*
* Private method: deepCopy
* ------------------------
* Copies all the data from the CharStack passed as an argument into
* the current object, including the characters in the dynamic array.
*/
void CharStack::deepCopy(const CharStack &src)
{
    m_count = src.m_count;
    m_capacity = src.m_capacity;
    m_pArray = new char[m_capacity];
    for(int i = 0; i < m_count; i++)
    {
        m_pArray[i] = src.m_pArray[i];
    }
}