#include <iostream>
#include <cassert>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
    /*--------------------ASSERT Integer Queue--------------------*/
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

    /*--------------------ASSERT Char Queue--------------------*/
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

    /*--------------------ASSERT String Queue--------------------*/
    Queue<string> stringQ;
    stringQ.enqueue(string("SEX"));
    stringQ.enqueue(string("WORLD"));
    stringQ.enqueue(string("peace"));
    Queue<string> stringQcopy1(stringQ);
    Queue<string> stringQcopy2 = stringQ;
    assert(("Dequeue 1st is SEX.", stringQcopy1.dequeue() == string("SEX")));
    assert(("Dequeue 2nd is SEX.", stringQcopy1.dequeue() == string("WORLD")));
    assert(("Dequeue 3rd is SEX.", stringQcopy1.dequeue() == string("peace")));
    assert(("Dequeue 1st is SEX.", stringQcopy2.dequeue() == string("SEX")));
    assert(("Dequeue 2nd is SEX.", stringQcopy2.dequeue() == string("WORLD")));
    assert(("Dequeue 3rd is SEX.", stringQcopy2.dequeue() == string("peace")));

    /*--------------------PLAYGROUND double Queue--------------------*/
    cout << "cout playground..." << endl;
    Queue<double> doubleQ;
    cout << doubleQ.isEmpty() << endl;
    cout << doubleQ.size() << endl;
    doubleQ.enqueue(3.14);
    doubleQ.enqueue(-3131.4332);
    doubleQ.enqueue(12.13);
    cout << doubleQ.isEmpty() << endl;
    cout << doubleQ.size() << endl;
    cout << doubleQ.peek() << endl;
    cout << doubleQ.dequeue() << endl;
    cout << doubleQ.dequeue() << endl;
    cout << doubleQ.dequeue() << endl;
    cout << doubleQ.isEmpty() << endl;
    cout << doubleQ.size() << endl;
    doubleQ.enqueue(983213.1231);
    doubleQ.enqueue(-67.567);
    doubleQ.enqueue(-3.237);
    cout << doubleQ.isEmpty() << endl;
    cout << doubleQ.size() << endl;
    doubleQ.clear();
    cout << doubleQ.isEmpty() << endl;
    cout << doubleQ.size() << endl;

    return 0;
}
