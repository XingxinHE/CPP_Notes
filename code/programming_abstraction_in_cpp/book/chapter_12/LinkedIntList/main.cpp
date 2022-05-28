#include "LinkedIntList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedIntList list;
    cout << list.isEmpty() << endl;
    // start -> 42 -> 17 -> -3 -> 9 /
    list.addBack(42);
    list.addBack(17);
    list.addBack(-3);
    list.addBack(9);

    // insert 88 at front of list
    list.addFront(88);

    // print the values, should be:
    // start -> 88 -> 42 -> 17 -> -3 -> 9 /
    cout << list << endl;

    list.addBack(777);

    // print the values, should be:
    // start -> 88 -> 42 -> 17 -> -3 -> 9 -> 777/
    cout << list << endl;

    list.removeFront();
    cout << "After removeFront(), here is the list again: " << endl;
    // print the values, should be:
    // start -> 42 -> 17 -> -3 -> 9 -> 777/
    cout << list << endl;

    list.removeValue(17);
    cout << "After remove(17), here is the list again: " << endl;
    // start -> 42 -> -3 -> 9 -> 777/
    cout << list << endl;

    // list.removeBack();
    // cout << "After removeBack(), here is the list again: " << endl;
    // // start -> 42 -> -3 -> 9/
    // cout << list << endl;


    return 0;
}
