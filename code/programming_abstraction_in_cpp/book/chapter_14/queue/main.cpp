#include <iostream>
#include <cassert>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> intQ;
    assert(("The queue is empty.", intQ.size() == 0));
    assert(("The queue is empty.", intQ.isEmpty() == true));

    intQ.enqueue(1994);
    intQ.enqueue(10);
    intQ.enqueue(28);
    assert(("The queue is not empty.", intQ.isEmpty() == false));
    assert(("The queue has 3 items.", intQ.size() == 3));
    assert(("Peek the queue is 1994.", intQ.peek() == 1994));

    assert(("1st dequeue is 1994.", intQ.dequeue() == 1994));
    assert(("2nd dequeue is 10.", intQ.dequeue() == 10));
    assert(("3rd dequeue is 28.", intQ.dequeue() == 28));
    assert(("The queue is empty.", intQ.isEmpty() == true));

    Queue<char> charQ;
    for(int i = 0; i< 26; i++)
    {
        char item = 'A' + i;
        charQ.enqueue(item);
    }
    assert(("The queue has 26 items.", charQ.size() == 26));
    assert(("The first one is 'A'.", charQ.peek() == 'A'));
    charQ.clear();
    assert(("The queue is empty.", charQ.isEmpty() == true));

    return 0;
}
