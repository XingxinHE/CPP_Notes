#include <iostream>
#include <string>
#include <cassert>
#include "BinarySearchTree.h"

using namespace std;

int main()
{   
    BinarySearchTree bTree;
    bTree.add(5);
    bTree.add(4);
    bTree.add(1);
    bTree.add(3);
    bTree.add(2);
    bTree.add(6);
    assert(("Tree contains 3.", bTree.contains(3)));
    assert(("Tree does not contains 9.", !bTree.contains(9)));
    assert(("Tree's max is 6.", bTree.findMax() == 6));
    assert(("Tree's min is 1.", bTree.findMin() == 1));
    cout << bTree << endl;

    

    return 0;
}