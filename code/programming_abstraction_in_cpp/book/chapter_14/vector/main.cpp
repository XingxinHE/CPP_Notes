#include <iostream>
#include <cassert>
#include "vector.h"

using namespace std;

int main()
{
    Vector<int> intVec;
    assert(("The vector is empty.", intVec.isEmpty()));
    for (int i = 0; i < 10; i++)
    {
        intVec.add(i);
    }
    assert(("The vector is not empty.", !intVec.isEmpty()));
    assert(("The vector has 10 elements.", intVec.size() == 10));
    assert(("intVec[3] is 3.", intVec[3] == 3));
    assert(("intVec.get(6) is 6.", intVec.get(6) == 6));
    
    intVec.insertAt(5, 999);
    assert(("intVec[5] is 999.", intVec[5] == 999));
    assert(("intVec[6] is 5.", intVec[6] == 5));
    assert(("intVec.size() is 11.", intVec.size() == 11));

    intVec.removeAt(2);
    assert(("intVec[2] is 3.", intVec[2] == 3));
    assert(("intVec.size() is 10.", intVec.size() == 10));

    intVec.set(4, 444);
    intVec[9] = 999;
    assert(("intVec[4] is 4.", intVec[4] == 444));
    assert(("intVec[9] is 999.", intVec[9] == 999));

    cout << intVec << endl;
    
    return 0;
}