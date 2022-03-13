#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool check_valid(int pos)
{
    if(pos < 1 || pos > 1024)
    {
        cerr << "Invalid number: n should be 1<=n<=1024!" << endl;
        return false;
    }
    return true;
}

// query a number from pentagonal sequence
bool cal_penta(int pos, int &val)
{
    if(check_valid(pos))
    {
        val = pos*(3*pos-1)/2;
        return true;
    }
    else
    {
        val = 0;
        return false;
    }
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
    for(int i = vec.size()+1; i <= size; i++)
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

const vector<int>* get_penta_pointer(int size)
{
    static vector<int> my_penta;
    if(check_valid((size)))
    {
        fill(my_penta, size);
        return &my_penta;
    }
    else
    {
        return &my_penta;
    }

}

int main()
{
    const vector<int>* pent_ptr;
    const string title( "Pentagonal Numeric Series" );

    // test case 1
    pent_ptr = get_penta_pointer(0);
    display( *pent_ptr, title, cout);


    // test case 2
    pent_ptr = get_penta_pointer(8);
    display( *pent_ptr, title, cout);

    // test case 3
    pent_ptr = get_penta_pointer(14);
    display( *pent_ptr, title, cout);

    // test case 4
    pent_ptr = get_penta_pointer(138);
    display( *pent_ptr, title, cout);

    return 0;
}
