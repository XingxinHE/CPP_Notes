#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

/*
 *  Implement display function with iterator
 *
 */
//template <typename T>
//void display(const vector<T> &vec, ostream &os)
//{
//    vector<T>::const_iterator iter = vec.begin();
//    vector<T>::const_iterator end_it = vec.end();

//    for(; iter!=end_it; iter++)
//    {
//        os << *iter << ' ';
//    }
//    os << endl;
//}

template <typename T, typename S>
T find(T first, T last, const S &value)
{
    for(; first!=last; first++)
    {
        if(*first==value)
        {
            return first;
        }
    }
    return last;
}


int main()
{
    /*
     *  Declare an iterator and const iterator
     *
     */
    vector<int> ivec;
    vector<string> svec;
    vector<int>::iterator iter = ivec.begin();
    vector<int>::const_iterator cst_iter = ivec.begin();
    vector<string>::iterator s_iter = svec.begin();
    vector<string>::const_iterator s_cst_iter = svec.begin();

    const int asize = 8;
    int ia[asize] {1,1,2,3,5,8,13,21};

    // init vector and link list
    vector<int> i_vec (ia, ia+asize);
    list<int> i_list(ia, ia+asize);

    int* pia = find(ia, ia+asize, 1024);
    if(pia != ia+asize)
    {
        cout << "1024 found in ia..." << endl;
    }

    vector<int>::iterator it;
    it = find(i_vec.begin(), ivec.end(), 1024);
    if(it != ivec.end())
    {
        cout << "1024 found in ivec..." << endl;
    }

    list<int>::iterator it_list;
    it_list = find(i_list.begin(), i_list.end(), 1024);
    if(it_list!=i_list.end())
    {
        cout << "1024 found in ilist..." << endl;
    }



}
