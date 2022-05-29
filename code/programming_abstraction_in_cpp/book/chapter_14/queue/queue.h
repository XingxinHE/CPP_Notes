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
    
public:
    /*
    * Constructor: Queue
    * Usage: Queue<ValueType> queue;
    * ------------------------------
    * Initializes a new empty queue.
    */
    Queue();



    /*
    * Destructor: ~Queue
    * Usage: (usually implicit)
    * -------------------------
    * Frees any heap storage associated with this queue.
    */
    ~Queue();



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



    private:

};
#endif