/*
* File: queue.h
* -------------
* This interface exports the Queue class, a collection in which values are
* ordinarily processed in a first-in/first-out (FIFO) order.
*/
#ifndef _queue_h
#define _queue_h

#include <stdexcept>
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
    * Constructor: Queue
    * Usage: Queue<ValueType> dst(src);
    * ---------------------------------
    * Initializes a new empty queue.
    */
    Queue<ValueType>(const Queue<ValueType> &src);



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


    /*
    * Operator: =
    * Usage: Queue<ValueType> q1;
    *        Queue<ValueType> q2;
    *        q1 = q2;
    * ---------------------------
    * Overload the '== operator.
    */
    Queue<ValueType> & operator=(const Queue<ValueType> &src);



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

/* Private Members */    
    int m_count;
    LinkNode *m_startCell;
    LinkNode *m_endCell;

/* Private Functions */
void deepCopy(const Queue<ValueType> &src);

};


/*
* Implementation notes: Queue data structure
* ------------------------------------------
* The list-based queue uses a linked list to store the elements
* of the queue. To ensure that adding a new element to the tail
* of the queue is fast, the data structure maintains a pointer to
* the last cell in the queue as well as the first. If the queue is
* empty, both the head pointer and the tail pointer are set to NULL.
*
*/



/*
* Implementation notes: Queue constructor
* ---------------------------------------
* The constructor creates an empty linked list and sets the count to 0.
*/
template<typename ValueType>
Queue<ValueType>::Queue()
                :m_count(0), m_startCell(nullptr), m_endCell(nullptr)
{
}



/*
* Implementation notes: copy operator
* -----------------------------------
* These methods follow the standard template, leaving the work to deepCopy.
*/
template<typename ValueType>
Queue<ValueType>::Queue(const Queue<ValueType> &src)
                :m_count(0), m_startCell(nullptr), m_endCell(nullptr)
{
    deepCopy(src);
}



/*
* Implementation notes: ~Queue destructor
* ---------------------------------------
* The destructor frees any heap memory allocated by the queue.
*/
template<typename ValueType>
Queue<ValueType>::~Queue()
{
    clear();
}



/*
* Implementation notes: size, isEmpty, clear
* ------------------------------------------
* The implementation maintains count so that size remains O(1).
*/
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
    while (m_count > 0)
    {
        this->dequeue();
    }
}



/*
* Implementation notes: enqueue
* -----------------------------
* This method allocates a new list cell and chains it in at the tail of
* the queue. If the queue is currently empty, the new cell must also
* become the head pointer in the queue.
*/
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



/*
* Implementation notes: dequeue, peek
* -----------------------------------
* These methods must check for an empty queue and report an error if
* there is no first element. The dequeue method must also check for
* the case in which the queue becomes empty and set both the head
* and tail pointers to NULL.
*/
template<typename ValueType>
ValueType Queue<ValueType>::dequeue()
{
    if(isEmpty())
    {
        throw std::invalid_argument("Try to dequeue from an empty queue.");
    }
    m_count--;

    ValueType result = m_startCell->value;
    LinkNode *node = m_startCell;
    m_startCell = m_startCell->next;
    if (m_startCell == nullptr)
    {
        m_endCell = nullptr;
    }
    delete node;
    
    return result;
}

template<typename ValueType>
ValueType Queue<ValueType>::peek() const
{
    if(isEmpty())
    {
        throw std::invalid_argument("Try to peek from an empty queue.");
    }
    
    return m_startCell->value;
}



/*
* Implementation notes: assignment operator
* -----------------------------------------
* These methods follow the standard template, leaving the work to deepCopy.
*/
template<typename ValueType>
Queue<ValueType> & Queue<ValueType>::operator=(const Queue<ValueType> &src)
{
    if(this != &src)
    {
        clear();
        deepCopy(src);
    }
    return *this;
}



/*
* Implementation notes: deepCopy
* ------------------------------
* This function copies the data from the src parameter into the current obejct.
* This implementation simply walks down the linked list in the source object
* and enqueue each value in the destination.
*/
template<typename ValueType>
void Queue<ValueType>::deepCopy(const Queue<ValueType> &src)
{
    for(LinkNode *start = src.m_startCell; start != nullptr; start = start->next)
    {
        this->enqueue(start->value);
    }
}

#endif