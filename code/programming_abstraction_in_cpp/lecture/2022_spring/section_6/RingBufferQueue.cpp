#include "RingBufferQueue.h"
#include "testing/SimpleTest.h"

using namespace std;

/**
 * TODO: write a method comment
 */
RBQueue::RBQueue() {
    // Delete these lines, then implement
    // this method.

}

/**
 * TODO: write a method comment
 */
RBQueue::~RBQueue() {
    // Delete these lines, then implement
    // this method.

}

/**
 * TODO: write a method comment
 */
void RBQueue::enqueue(int elem) {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    (void) elem;
}

/**
 * TODO: write a method comment
 */
int RBQueue::dequeue() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return 0;
}

/**
 * TODO: write a method comment
 */
int RBQueue::peek() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return 0;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isEmpty() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return false;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return false;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    return 0;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    (void) queue;
    return out;
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
