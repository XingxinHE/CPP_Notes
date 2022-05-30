/*
* File: vector.h
* --------------
* This interface exports the Vector template class, which provides an
* efficient, safe, convenient replacement for the array type in C++.
*/

#ifndef _vector_h
#define _vector_h

#include <iostream>
#include <exception>

/*
* Class: Vector<ValueType>
* ------------------------
* This class stores an ordered list of values similar to an array. It
* supports traditional array selection using square brackets, but also
* supports inserting and deleting elements.
*/
template<typename ValueType>
class Vector
{

public:
    /*
    * Constructor: Vector
    * Usage: Vector<ValueType> vec;
    * Vector<ValueType> vec(n, value);
    * ---------------------------------------
    * Initializes an empty vector.
    */
    Vector();
    Vector(int n, ValueType value = ValueType());
    Vector(const Vector<ValueType> &src);
    /*
    * Destructor: ~Vector
    * Usage: (usually implicit)
    * -------------------------
    * Frees any heap storage allocated by this vector.
    */
    ~Vector();
    /*
    * Method: size
    * Usage: int nElems = vec.size();
    * -------------------------------
    * Returns the number of elements in this vector.
    */
    int size() const;
    /*
    * Method: isEmpty
    * Usage: if (vec.isEmpty()) . . .
    * -------------------------------
    * Returns true if this vector contains no elements.
    */
    bool isEmpty() const;
    /*
    * Method: clear
    * Usage: vec.clear();
    * -------------------
    * Removes all elements from this vector.
    */
    void clear();
    /*
    * Method: get
    * Usage: ValueType val = vec.get(index);
    * --------------------------------------
    * Returns the element at the specified index in this vector. This method
    * signals an error if the index is not in the array range.
    */
    ValueType get(int index) const;
    /*
    * Method: set
    * Usage: vec.set(index, value);
    * -----------------------------
    * Replaces the element at the specified index in this vector with a new
    * value. The previous value at that index is overwritten. This method
    * signals an error if the index is not in the array range.
    */
    void set(int index, ValueType value);
    /*
    * Method: insertAt
    * Usage: vec.insertAt(0, value);
    * ------------------------------
    * Inserts the element into this vector before the specified index. All
    * subsequent elements are shifted one position to the right. This method
    * signals an error if the index is outside the range from 0 up to and
    * including the length of the vector.
    */
    void insertAt(int index, ValueType value);
    /*
    * Method: removeAt
    * Usage: vec.removeAt(index);
    * ---------------------------
    * Removes the element at the specified index from this vector. All
    * subsequent elements are shifted one position to the left. This method
    * signals an error if the index is outside the array range.
    */
    void removeAt(int index);
    /*
    * Method: add
    * Usage: vec.add(value);
    * ----------------------
    * Adds a new value to the end of this vector.
    */
    void add(ValueType value);

    /*
    * Operator: []
    * Usage: vec[index]
    * -----------------
    * Overloads [] to select elements from this vector. This extension
    * enables the use of traditional array notation to get or set individual
    * elements. This method signals an error if the index is outside the
    * array range.
    */
    ValueType &operator[](int index);

    friend ostream &operator<<(ostream &os, const Vector<ValueType> &src);


private:

    static const int INITIAL_SIZE = 10;
    int m_capacity;
    int m_count;
    ValueType *array;

    void deepCopy(const Vector<ValueType> &src);
    void resize(bool isIncrement)

};

template<typename ValueType>
Vector<ValueType>::Vector()
                 :m_capacity(INITIAL_SIZE), m_count(0)
{
    array = new ValueType[m_capacity];
}

template<typename ValueType>
Vector<ValueType>::Vector(int n, ValueType value = ValueType())
                 :m_capacity(INITIAL_SIZE), m_count(n)
{
    m_capacity = n > m_capacity? 2 * n : m_capacity;
    array = new ValueType[m_capacity];
    for (int i = 0; i < m_count; i++)
    {
        array[i] = value;
    }
}

template<typename ValueType>
Vector<ValueType>::Vector(const Vector<ValueType> &src)
{
    this->deepCopy(src);
}

template<typename ValueType>
Vector<ValueType>::~Vector()
{
    delete[] array;
}

template<typename ValueType>
int Vector<ValueType>::size() const
{
    return m_count;
}

template<typename ValueType>
bool Vector<ValueType>::isEmpty() const
{
    return m_count == 0;
}

template<typename ValueType>
void Vector<ValueType>::clear()
{
    m_count = 0;
    m_capacity = INITIAL_SIZE;
    delete[] array;
    array = new ValueType[m_capacity];
}

template<typename ValueType>
void Vector<ValueType>::deepCopy(const Vector<ValueType> &src)
{
    if(this != &src)
    {
        this->m_capacity = src.m_capacity;
        this->m_count = src.m_count;
        delete[] array;
        array = new ValueType[m_capacity];
        for (int i = 0; i < m_count; i++)
        {
            array[i] = src.array[i];
        }
    }
}

template<typename ValueType>
ValueType Vector<ValueType>::get(int index) const
{
    if (0 < index && index < m_count)
    {
        ValueType result = array[index];
        return result;
    }
    else
    {
        throw std::invalid_argument("Index is out of bound.");
    }
}

template<typename ValueType>
void Vector<ValueType>::set(int index, ValueType value)
{
    if (0 < index && index < m_count)
    {
        ValueType *temp = array;
        temp += index;
        *temp = value;
    }
    else
    {
        throw std::invalid_argument("Index is out of bound.");
    }
}

template<typename ValueType>
void Vector<ValueType>::insertAt(int index, ValueType value)
{
    if (0 < index && index < m_count)
    {
        if((m_count + 1) > m_capacity)
        {
            resize(true);
        }
        for (int i = m_count; i > index+1; i--)
        {
            array[i+1] = array[i]
        }
        
        ValueType *temp = array;
        temp += index;
        *temp = value;
    }
    else
    {
        throw std::invalid_argument("Index is out of bound.");
    }
}

template<typename ValueType>
void Vector<ValueType>::resize(bool isIncrement)
{
    ValueType *oldArray = array;

    if (isIncrement)
    {
        m_capacity *= 2;
    }
    else
    {
        m_capacity = int(0.5 * m_capacity);
    }

    array = new ValueType[m_capacity];
    for (int i = 0; i < m_count; i++)
    {
        array[i] = oldArray[i];
    }

    delete[] oldArray;
}

#endif