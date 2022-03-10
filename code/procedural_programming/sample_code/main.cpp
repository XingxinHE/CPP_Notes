#include <iostream>
#include <vector>

using namespace std;

bool fibon_elem(int pos, int &elem)
{
        if (pos <= 0 || pos > 1024)
        {
                cerr << "Invalid position: " << pos
                     << " -- cannot handle request!\n";

                elem = 0;
                return false;
        }
        elem = 1;
        int n_2 = 1, n_1 = 1;
        for (int ix = 3; ix <= pos; ix++)
        {
                elem = n_2 + n_1;
                n_2 = n_1;
                n_1 = elem;
        }
        return true;
}

