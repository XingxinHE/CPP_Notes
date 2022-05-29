#include "LinkedIntList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {

    LinkedIntList list;
    cout << list << endl;
    
    // start -> 42 -> 17 -> -3 -> 9 /
    list.addBack(42);
    list.addBack(17);
    list.addBack(-3);
    list.addBack(9);
    assert(("The list has 4 elements", list.size() == 4));

    // insert 88 at front of list
    list.addFront(88);
    assert(("The list has 5 elements", list.size() == 5));

    // print the values, should be:
    // start -> 88 -> 42 -> 17 -> -3 -> 9 /
    assert(("First element is 88", list.first() == 88));
    assert(("Last element is 9", list.last() == 9));
    cout << list << endl;

    list.addBack(777);
    assert(("The list has 6 elements", list.size() == 6));

    // print the values, should be:
    // start -> 88 -> 42 -> 17 -> -3 -> 9 -> 777/
    cout << list << endl;

    list.removeFront();
    cout << "After removeFront(), here is the list again: " << endl;
    // print the values, should be:
    // start -> 42 -> 17 -> -3 -> 9 -> 777/
    cout << list << endl;
    assert(("First element now is 88", list.first() == 42));

    list.removeValueMarty(17);
    cout << "After remove(17), here is the list again: " << endl;
    // start -> 42 -> -3 -> 9 -> 777/
    cout << list << endl;

    list.removeBack();
    cout << "After removeBack(), here is the list again: " << endl;
    // start -> 42 -> -3 -> 9/
    cout << list << endl;

    cout << "Stress test..." << endl;
    for (int i = 0; i < 1000000; i++)
    {
        list.addFront(i);
    }
    assert(("List should greater than 100000", list.size() > 1000000));
    list.clear();
    assert(("List is empty.", list.isEmpty() == true));
    

    return 0;
}
