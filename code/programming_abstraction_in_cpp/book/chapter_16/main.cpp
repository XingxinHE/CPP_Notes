#include <iostream>
#include <string>
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

    cout << bTree << endl;

    return 0;
}