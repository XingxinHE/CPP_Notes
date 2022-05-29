/*
* File: stack.h
* -------------
* This interface exports the Stack class, which implements a collection
* that processes values in a last-in/first-out (LIFO) order.
*/

#ifndef _Stack_h
#define _Stack_h

#include <iostream>

/*
* Class: Stack<ValueType>
* -----------------------
* This class models a linear structure called a stack in which values are
* added and removed only from one end. This discipline gives rise to a
* last-in/first-out behavior (LIFO) that is the defining feature of
* stacks. The fundamental stack operations are push (add to top) and pop
* (remove from top).
*/
template <typename ValueType>
class Stack
{

public:
/*
* Constructor: Stack
* Usage: Stack<ValueType> stack;
* ------------------------------
* Initializes a new empty stack.
*/
    Stack<ValueType>();

/*
 * Constructor: Stack
 * Usage: Stack cstk(src);
 * ----------------------
 * Initializes the current object to be a deep copy of the specified source.
 */
    Stack<ValueType>(const Stack<ValueType> &src);

/*
* Destructor: ~Stack
* Usage: (usually implicit)
* -------------------------
* Frees any heap storage associated with this stack.
*/
    ~Stack<ValueType>();

/*
* Method: size
* Usage: int n = stack.size();
* ----------------------------
* Returns the number of values in this stack.
*/
    int size() const;

/*
* Method: isEmpty
* Usage: if (stack.isEmpty()) . . .
* ---------------------------------
* Returns true if this stack contains no elements.
*/
    bool isEmpty() const;

/*
* Method: clear
* Usage: stack.clear();
* ---------------------
* Removes all elements from this stack.
*/
    void clear();

/*
* Method: push
* Usage: stack.push(value);
* -------------------------
* Pushes the specified value onto this stack.
*/
    void push(ValueType input);

/*
* Method: pop
* Usage: ValueType top = stack.pop();
* -----------------------------------
* Removes the top element from this stack and returns it. This
* method signals an error if called on an empty stack.
*/
    ValueType pop();

/*
* Method: peek
* Usage: ValueType top = stack.peek();
* ------------------------------------
* Returns the value of top element from this stack, without removing
* it. This method signals an error if called on an empty stack.
*/
    ValueType peek() const;

/*
 * Operator: =
 * Usage: dst = src;
 * -----------------
 * Assign src to dst so that the two stacks are independent copies.
 */
Stack<ValueType> & operator=(const Stack<ValueType> &src);

private:
/*  Private constants  */
    static const int INITIAL_CAPACITY = 10;
/*  Instance Variables  */
    int m_capacity;
    int m_count;
    ValueType *m_pArray;
/*  Private function prototypes  */
    void resize(bool isIncrement);
    void deepCopy(const Stack<ValueType> &src);
};

/*
* Implementation notes: Stack constructor
* ---------------------------------------
* The constructor must allocate the array storage for the stack elements
* and initialize the fields of the object.
*/
template <typename ValueType>
Stack<ValueType>::Stack()
          :m_count(0), m_capacity(INITIAL_CAPACITY)
{
    m_pArray = new ValueType[m_capacity];
}

template <typename ValueType>
Stack<ValueType>::Stack(const Stack<ValueType> &src)
{
    deepCopy(src);
}



/*
* Implementation notes: ~Stack
* ----------------------------
* The destructor frees any heap memory allocated by the class, which
* is just the dynamic array of elements.
*/
template <typename ValueType>
Stack<ValueType>::~Stack()
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
template <typename ValueType>
bool Stack<ValueType>::isEmpty() const
{
    return m_count == 0;
}

template <typename ValueType>
int Stack<ValueType>::size() const
{
    return m_count;
}

template <typename ValueType>
void Stack<ValueType>::clear()
{
    if (m_pArray != nullptr)
    {
        delete[] m_pArray;
        m_count = 0;
        m_pArray = new ValueType[m_capacity];
    }
}



/*
* Implementation notes: push
* --------------------------
* This function must first check to see whether there is enough room for
* the ValueTypeacter and expand the array storage if necessary.
*/
template <typename ValueType>
void Stack<ValueType>::push(ValueType input)
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
template <typename ValueType>
ValueType Stack<ValueType>::peek() const
{
    if(!isEmpty())
    {
        ValueType item = m_pArray[m_count-1];
        return item;
    }
    else
    {
        return '\0';
    }
}

template <typename ValueType>
ValueType Stack<ValueType>::pop()
{
    if(!isEmpty())
    {
        ValueType item = m_pArray[--m_count];
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
* For the Stack class, this kind of assignment requires making a
* deep copy that includes the dynamic array.
*/
template <typename ValueType>
Stack<ValueType> & Stack<ValueType>::operator=(const Stack<ValueType> &src)
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
* array, allocate a new array with twice the capacity, copy the ValueType
* from the old array to the new one, and finally free the old storage.
*/
template <typename ValueType>
void Stack<ValueType>::resize(bool isIncrement)
{
    if (isIncrement)
    {
        ValueType *oldPtr = m_pArray;
        m_capacity *= 2;
        m_pArray = new ValueType[m_capacity];
        for (int i = 0; i < m_count; i++)
        {
            m_pArray[i] = oldPtr[i];
        }
        delete[] oldPtr;
    }
    else
    {
        ValueType *oldPtr = m_pArray;
        m_capacity = int(0.5 * m_capacity);
        m_pArray = new ValueType[m_capacity];
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
* Copies all the data from the Stack passed as an argument into
* the current object, including the ValueType in the dynamic array.
*/
template <typename ValueType>
void Stack<ValueType>::deepCopy(const Stack &src)
{
    m_count = src.m_count;
    m_capacity = src.m_capacity;
    m_pArray = new ValueType[m_capacity];
    for(int i = 0; i < m_count; i++)
    {
        m_pArray[i] = src.m_pArray[i];
    }
}

#endif
