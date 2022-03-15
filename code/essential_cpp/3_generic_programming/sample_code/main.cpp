#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

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

void compare(vector<int> &vec1, vector<int> &vec2)
{
    // equality
    if(vec1 == vec2) return;

    // isEmpty?
    if(vec1.empty() || vec2.empty()) return;

    // the size
    if(vec1.size() != vec2.size()) return;

    // clear all the data
    vec1.clear();

    // begin and end
    for(auto iter = vec1.begin(); iter!= vec2.end(); iter++)
    {
        cout << "+";
    }

    // insert and erase
    vec1.insert(vec1.begin()+1, 2);
    vec2.erase(vec2.end()-3);

}



void prog_1()
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


    // Create an empty container
    list<string> slist;
    deque<int> ideque;


    // Create a container of some size
    list<int> ilist(1024);
    vector<double> dvec(32);

    // Create a container of a given size specified with initial value
    vector<char> chvec(10, 'X');
    list<string> slist1(16, "unassigned");
    deque<double> dd(10, 3.2);

    // Create a container with iterator
    bool barr[3] = {true, false, true};
    vector<bool> bvec(barr, barr+3);

    // Create a container by full copy another
    list<string> slist2(slist);

}

void prog_2()
{
    int ival = 6;
    int ia[3] = {1, 2, 9};
    list<int> ilist(ia, ia+3);
    list<int>::iterator it = ilist.begin();

    while(it != ilist.end())
    {
        if(*it >= ival)
        {
            ilist.insert(it, ival);
            break;
        }
        it++;
    }
    if(it == ilist.end())
    {
        ilist.push_back(ival);
    }

    for(int ix:ilist )
    {
        cout << ix;
    }

}

void prog_3()
{
    // arrage
    list<string> slist(3, string("Hello"));
    list<string>::iterator it = slist.begin();
    // iterator as the 2nd position
    it++;
    // insert after that position
    slist.insert(it, 5, string("dummy"));
    // display
    for(auto val : slist)
    {
        cout << val << "  ";
    }

}

void prog_4()
{
    // arrage
    list<string> slist(6, string("Hello"));
    list<string>::iterator it = slist.begin();
    // iterator as the 2nd position
    it++;
    list<string>::iterator first = slist.begin();
    list<string>::iterator last = slist.end();
    last--;

    // before erase
    for(auto v : slist)
    {
        cout << v << "  ";
    }
    cout << endl;

    // after erase
    slist.erase(first, last);
    for(auto v : slist)
    {
        cout << v << "  ";
    }
}

int main()
{

    prog_4();


}
