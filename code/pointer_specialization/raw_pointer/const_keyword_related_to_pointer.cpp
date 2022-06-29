#include <iostream>

using namespace std;

int main()
{
    const double PI = 3.14159;
    const double* pConst = &PI;  // OK✅
    cout << *pConst << endl;

    const double EPSILON = 1.0e-09;
    pConst = &EPSILON;
    cout << *pConst << endl;

    return 0;
}