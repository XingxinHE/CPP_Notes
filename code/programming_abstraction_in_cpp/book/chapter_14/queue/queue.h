#include <stdexcept>
/*
* File: queue.h
* -------------
* This interface exports the Queue class, a collection in which values are
* ordinarily processed in a first-in/first-out (FIFO) order.
*/
#ifndef _queue_h
#define _queue_h
/*
* Class: Queue<ValueType>
* -----------------------
* This class models a linear structure called a queue in which values are
* added at one end and removed from the other. This discipline gives rise
* to a first-in/first-out behavior (FIFO) that is the defining feature of
* queues.
*/
template <typename ValueType>
class Queue
{
    
/* Public Section */
public:
    /*
    * Constructor: Queue
    * Usage: Queue<ValueType> queue;
    * ------------------------------
    * Initializes a new empty queue.
    */
    Queue<ValueType>();



    /*
    * Destructor: ~Queue
    * Usage: (usually implicit)
    * -------------------------
    * Frees any heap storage associated with this queue.
    */
    ~Queue<ValueType>();



    /*
    * Method: size
    * Usage: int n = queue.size();
    * ----------------------------
    * Returns the number of values in the queue.
    */
    int size() const;



    /*
    * Method: isEmpty
    * Usage: if (queue.isEmpty()) . . .
    * ---------------------------------
    * Returns true if the queue contains no elements.
    */
    bool isEmpty() const;



    /*
    * Method: clear
    * Usage: queue.clear();
    * ---------------------
    * Removes all elements from the queue.
    */
    void clear();



    /*
    * Method: enqueue
    * Usage: queue.enqueue(value);
    * ----------------------------
    * Adds value to the end of the queue.
    */
    void enqueue(ValueType value);



    /*
    * Method: dequeue
    * Usage: ValueType first = queue.dequeue();
    * -----------------------------------------
    * Removes and returns the first item in the queue.
    */
    ValueType dequeue();



    /*
    * Method: peek
    * Usage: ValueType first = queue.peek();
    * --------------------------------------
    * Returns the first value in the queue, without removing it.
    */
    ValueType peek() const;



/* Private Section */
private:

/* Type for linked list cell */
    struct LinkNode
    {
        ValueType value;                  /* The data value.                 */
        LinkNode *next;                       /* Link to the next cell.          */

        LinkNode(ValueType input)             /* Constructor.                    */
            :value(input), next(nullptr)
        {
        }
    };
    
    int m_count;
    LinkNode *m_startCell;
    LinkNode *m_endCell;

};


template<typename ValueType>
Queue<ValueType>::Queue()
                :m_count(0), m_startCell(nullptr), m_endCell(nullptr)
{
}

template<typename ValueType>
Queue<ValueType>::~Queue()
{
    clear();
}

template<typename ValueType>
int Queue<ValueType>::size() const
{
    return m_count;
}


template<typename ValueType>
bool Queue<ValueType>::isEmpty() const
{
    return m_count == 0;
}

template<typename ValueType>
void Queue<ValueType>::clear()
{
    while (m_startCell != nullptr)
    {
        LinkNode *node = m_startCell;
        m_startCell = m_startCell->next;
        delete node;
    }
    m_endCell = nullptr;
}

template<typename ValueType>
void Queue<ValueType>::enqueue(ValueType value)
{
    m_count++;
    LinkNode *node = new LinkNode(value);
    if (m_startCell == nullptr)
    {
        m_startCell = node;
        m_endCell = node;
        return;
    }

    m_endCell->next = node;
    m_endCell = node;
    return;
}

template<typename ValueType>
ValueType Queue<ValueType>::dequeue()
{
    if(m_count == 0)
    {
        throw std::invalid_argument("Try to dequeue from an empty queue.");
    }
    m_count--;

    ValueType result = m_startCell->value;
    LinkNode *node = m_startCell;
    m_startCell = m_startCell->next;
    delete node;
    if (m_count == 0)
    {
        m_endCell = nullptr;
    }
    
    return result;
}

template<typename ValueType>
ValueType Queue<ValueType>::peek() const
{
    if(m_count == 0)
    {
        throw std::invalid_argument("Try to peek from an empty queue.");
    }
    ValueType result = m_startCell->value;
    
    return result;
}

#endif