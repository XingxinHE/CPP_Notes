#include "RingBufferQueue.h"
#include "testing/SimpleTest.h"

using namespace std;
/**
 * TODO: write a method comment
 */
RBQueue::RBQueue()
       :m_head(0), m_tail(0), m_capacity(INITIAL_CAPACITY)
{
    m_array = new int[m_capacity];
}

/**
 * TODO: write a method comment
 */
RBQueue::~RBQueue() {
    delete[] m_array;
}

/**
 * TODO: write a method comment
 */
void RBQueue::enqueue(int elem) {
    if(size() == m_capacity-1) expandCapacity();
    m_array[m_tail] = elem;
    m_tail = (m_tail + 1) % m_capacity;
}

/**
 * TODO: write a method comment
 */
int RBQueue::dequeue() {
    if(!this->isEmpty())
    {
        int result = m_array[m_head];
        m_head = (m_head + 1) % m_capacity;
        return result;
    }
    else
    {
        error("Sorry, the queue is empty.");
    }
}

/**
 * TODO: write a method comment
 */
int RBQueue::peek() {
    if(!this->isEmpty())
    {
        return m_array[m_head];
    }
    else
    {
        error("Sorry, the queue is empty.");
    }
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isEmpty() {
    return m_head == m_tail;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {
    return size() == m_capacity;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() const{
    return (m_tail + m_capacity - m_head) % m_capacity;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {

    int count = queue.size();
    for(int i = 0; i < count; i++ )
    {
        int index = (queue.m_head + i) % queue.m_capacity;
        out << queue.m_array[index] << " ";
    }

    return out;
}

void RBQueue::expandCapacity()
{
    int *oldArray = m_array;
    m_array = new int[m_capacity * 2];
    int count = size();
    for(int i = 0; i < count; i++ )
    {
        int index = (m_head + i) % m_capacity;
        m_array[i] = oldArray[index];
    }
    m_capacity *= 2;
    m_head = 0;
    m_tail = count;
    delete[] oldArray;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout, No resizing") {
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(q.isFull());
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.peek(), 3);
    q.enqueue(6);
    EXPECT_EQUAL(q.dequeue(), 3);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT(q.isEmpty());
}

PROVIDED_TEST("Example from Handout, with Resizing") {
    RBQueue q;
    for (int i = 10; i <= 50; i+= 10) {
        q.enqueue(i);
    }
    EXPECT(q.isFull());
    // Adding the 6th element should trigger a resizing
    q.enqueue(60);
    EXPECT(!q.isFull());
    for (int i = 10; i <= 60; i += 10) {
        EXPECT_EQUAL(i, q.peek());
        EXPECT_EQUAL(i, q.dequeue());
    }
    EXPECT(q.isEmpty());
}
