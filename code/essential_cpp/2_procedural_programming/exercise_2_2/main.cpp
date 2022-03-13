#include <iostream>
#include <string>
#include <vector>

using namespace std;

// query a number from pentagonal sequence
bool cal_penta(int pos, int &val)
{
    if(pos < 0 || pos > 1024)
    {
        cerr << "Invalid number: n should be 1<=n<=1024!" << endl;
        val = 0;
        return false;
    }
    val = pos*(3*pos-1)/2;
    return true;
}

// define a function to fill a vector of elements passed into
// the function calculated to some user-specified position
bool fill(vector<int> &vec, int size)
{
    if(size < 0 || size > 1024)
    {
        cerr << "Invalid length of sequence." << endl;
        return false;
    }
    for(int i = vec.size(); i < size; i++)
    {
        int num;
        if(cal_penta(i, num))
        {
            // since the vec is not initialized
            // you can't use vec[i] semantic...
            vec.push_back(num);
        }
        else
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void display(const vector<T> &vec, const string &type_numeric, ostream &os)
{
    os << type_numeric << endl;

    int count = vec.size();
    for(int i = 0; i < count; i++)
    {
        os << vec[i] << ' ';
    }

    os << endl;
}

int main()
{
    vector<int> pent;
    const string title( "Pentagonal Numeric Series" );

    // test case 1
    if ( fill( pent, 0 ))
    {
        display( pent, title, cout);
    }

    // test case 2
    if ( fill( pent, 8 ))
    {
        display( pent, title, cout );
    }

    // test case 3
    if ( fill( pent, 14 ))
    {
        display( pent, title, cout );
    }

    // test case 4
    if ( fill( pent, 138 ))
    {
        display( pent, title, cout );
    }

    return 0;
}
