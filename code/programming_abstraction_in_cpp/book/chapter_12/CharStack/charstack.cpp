#include "charstack.h"

CharStack::CharStack()
          :m_count(0), m_capacity(10)
{
    m_pArray = new char[m_capacity];
}

CharStack::~CharStack()
{
    delete[] m_pArray;
}

bool CharStack::isEmpty()
{
    return m_count == 0;
}

int CharStack::size()
{
    return m_count;
}

void CharStack::push(char input)
{
    if (m_count == m_capacity)
    {
        resize(true);
    }
    
    m_pArray[m_count] = input;
    m_count++;
}

char CharStack::peek()
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
        char item = m_pArray[m_count-1];
        m_pArray[m_count-1] = '\0';
        m_count--;
        if (m_count < (0.5 * m_capacity))
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

void CharStack::clear()
{
    if (m_pArray != nullptr)
    {
        delete[] m_pArray;
        m_count = 0;
        m_pArray = new char[m_capacity];
    }
}

void CharStack::resize(bool isIncrement)
{
    if (isIncrement)
    {
        char *pNew = new char[m_capacity * 2];
        for (int i = 0; i < m_capacity; i++)
        {
            pNew[i] = m_pArray[i];
        }
        char *pTemp = m_pArray;
        m_pArray = pNew;
        delete[] pTemp;
        m_capacity *= 2;
    }
    else
    {
        char *pNew = new char[int(0.5 * m_capacity)];
        for (int i = 0; i < m_count; i++)
        {
            pNew[i] = m_pArray[i];
        }
        char *pTemp = m_pArray;
        m_pArray = pNew;
        delete[] pTemp;
        m_capacity = int(0.5 * m_capacity);
    }
}