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

#include <algorithm>
extern bool grow_vec(vector<int> &vec, int elem);

//bool is_elem(vector<int> &vec, int elem)
//{
//    int max_value = max_element(vec.begin(), vec.end());
//    if(max_value < elem)
//    {
//        return grow_vec(vec, elem);
//    }
//    if(max_value == elem)
//    {
//        return true;
//    }

//    return binary_search(vec.begin(), vec.end(), elem);
//}

void prog_5()
{
    // unsure vector
    vector<int> vec;
    // duplicate vector with same size
    vector<int> vec_copy(vec.size());
    // copy from start to end
    copy(vec.begin(), vec.end(), vec_copy.begin());
    // sort that copy vector
    sort(vec_copy.begin(), vec_copy.end());

    // query...
    int query_num = 13;
    bool is_found = binary_search(
                vec_copy.begin(),
                vec_copy.end(),
                query_num);
}

vector<int> less_than_10(const vector<int> &vec)
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ix++)
    {
        if(vec[ix] < 10)
        {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}

bool is_bigger(int lhs, int rhs)
{
    return lhs > rhs? true : false;
}

bool is_smaller(int lhs, int rhs)
{
    return lhs < rhs? true : false;
}

vector<int> filter_with_value(vector<int> &vec, int value, bool (*flag)(int, int))
{
    vector<int> nvec;
    for(int ix = 0; ix < vec.size(); ix++)
    {
        if(flag(vec[ix], value))
        {
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}

void prog_6()
{
    int arr[5] = {12,13,20,100, 5};
    vector<int> ivec(arr, arr+5);
    vector<int> vec_bigger_10 = filter_with_value(ivec, 13, is_bigger);

    for(auto v : vec_bigger_10)
    {
        cout << v << "  ";
    }
}

#include <functional>
void prog_7()
{
    int s1[5] = {1, 2, 3, 6, 9};
    int s2[5] = {2, 3, 5, 6, 9};
    vector<int> vec_s1(s1, s1+5);
    vector<int> vec_s2(s2, s2+5);
    vector<int> vec_sf(5);

    transform(vec_s1.begin(),
              vec_s1.end(),
              vec_s1.begin(),
              vec_s1.begin(),
              plus<int>());

    transform(vec_s1.begin(),
              vec_s1.end(),
              vec_s1.begin(),
              vec_s1.begin(),
              multiplies<int>());

    transform(vec_s1.begin(),
              vec_s1.end(),
              vec_s2.begin(),
              vec_s1.begin(),
              plus<int>());

}

vector<int> filter(const vector<int> &vec, int val, less<int> &lt)
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    // bind2nd(less<int>, val) binds val to the second value of less<int>
    // less<int> now compares each value against val
    while( (iter =
            find_if(iter,
                    vec.end(),
                    bind2nd(lt, val))
            ) != vec.end())
    {
        // each time iter != vec.end(),
        // iter addresses an element less than val
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

template <typename InputIterator,
          typename OutputIterator,
          typename ElemType,
          typename Comp>
OutputIterator filter (InputIterator first,
                       InputIterator last,
                       OutputIterator at,
                       const ElemType &val,
                       Comp pred)
{
    while( (first = find_if(first, last, bind2nd(pred, val)))
           != last)
    {
        // just to see what is going on ...
        cout << "found value: " << *first << endl;
        // assign value, then advance both iterators
        *at = *first;
        at++;
        first++;
    }
    return at;
}

vector<int> sub_vec(vector<int> &vec, int val)
{
    // clone a vector
    vector<int> nvec(vec);
    // sort it first
    sort(nvec.begin(), nvec.end());

    vector<int>::iterator iter;
    // find the pos marked > val
    iter =  find_if(nvec.begin(), nvec.end(), bind2nd(greater<int>(), val));

    // delete the part
    nvec.erase(iter, nvec.end());

    return nvec;
}

void prog_8()
{
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    // contaienrs to hold the results of out filter()
    int ia2[elem_size];
    vector<int> ivec2(elem_size);

    cout << "filtering integer array for values less than 8" << endl;
    int* x= filter(ia, ia+elem_size, ia2, elem_size, less<int>());
cout << x << endl;
cout << *x << endl;
    cout << "filtering integer vector for values greater than 8" << endl;
    vector<int>::iterator y = filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());
    //cout << y << endl;
    cout << *y << endl;
}



int main()
{

    prog_8();


}
