#include "License.h"
#include <iostream>

using namespace std;

License::License()
{
    cout << "Init a license..." << endl;
}

License::License(int _order)
{
    order = _order;
    cout << "Init a license with Id: " << order << endl;
}

License::~License()
{
}