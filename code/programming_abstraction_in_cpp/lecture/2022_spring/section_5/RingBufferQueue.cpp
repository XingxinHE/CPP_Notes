#include "RingBufferQueue.h"
#include "testing/SimpleTest.h"

using namespace std;

/**
 * TODO: write a method comment
 */
RBQueue::RBQueue()
       :m_head(0), m_tail(0), m_capacity(INITIAL_CAPACITY),
        m_count(0)
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
    if(!this->isFull())
    {
        m_count++;
        m_array[m_tail] = elem;
        m_tail = nextIndex(m_tail + 1);
    }
}

/**
 * TODO: write a method comment
 */
int RBQueue::dequeue() {
    if(!this->isEmpty())
    {
        m_count--;
        int result = m_array[m_head];
        m_head = nextIndex(m_head + 1);
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
    return m_count == 0;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {
    return m_count == m_capacity;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() {
    return m_count;
}

int RBQueue::nextIndex(int index)
{
    return (index + m_capacity) % m_capacity;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {

    for(int i = queue.m_head; i < queue.m_head + queue.m_count; i++ )
    {
        int index = i % queue.m_capacity;
        out << queue.m_array[index] << " ";
    }

    return out;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout"){
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(!q.isFull());
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
