#include <iostream>
#include <vector>

using namespace std;

bool fibon_elem(int pos, int &elem)
{
        if (pos <=0 || pos > 1024)
        {
                cerr << "Invalid position: " << pos
                     << " -- cannot handle request!" << endl;
                
                elem = 0;
                return false;
        }

        elem = 1;
        int n_2 = 1, n_1 = 1;
        for (int ix = 3; ix <= pos; ix++)
        {
                elem = n_2 + n_1;
                n_2 = n_1; n_1 = elem;
        }
        
        return true;
}

bool print_sequence(int pos)
{
        if (pos <=0 || pos > 1024)
        {
                cerr << "Invalid position: " << pos
                     << " -- cannot handle request!" << endl;
                return false;
        }
        
        cout << "The Fibonacci Sequence for " << pos
             << " positions: \n\t";
        
        switch (pos)
        {
        case 2:
                cout << "1 ";
        case 1:
                cout << "1 ";
                break;
        }

        int elem;
        int n_2 = 1, n_1 = 1;
        for (int ix = 0; ix < pos; ++ix)
        {
                elem = n_2 + n_1;
                n_2 = n_1; n_1 = elem;

                cout << elem
                     << (!(ix%10)? "\n\t":" ");
        }
        cout << endl;
        return true;
}

#include <vector>

//slow version display, because it is passed by value
void display(vector<int> vec)
{
        for (int ix = 0; ix < vec.size(); ix++)
        {
                cout << vec[ix] << ' ';
        }
        cout << endl;        
}

//invalid swap, because it is passed by value
void swap(int val1, int val2)
{
        int temp = val1;
        val1 = val2;
        val2 = temp;
}

//invalid sort, because it is passed by value
void bubble_sort(vector<int> vec)
{
        for (int ix = 0; ix < vec.size(); ++ix)
        {
                for (int jx = ix + 1; jx < vec.size(); ++jx)
                {
                        if (vec[ix]>vec[jx])
                        {
                                swap(vec[ix], vec[jx]);
                        }
                }
        }
}

//valid swap, because it is passed by reference
void swap3(int &val1, int &val2)
{
        int temp = val1;
        val1 = val2;
        val2 = temp;
}


const vector<int>* fibon_seq2(int size)
{
        const int max_size = 1024;
        static vector<int> elems;

        if (size<=0 || size>max_size)
        {
                return 0;
        }

        for (int ix = elems.size(); ix < size; ix++)
        {
                if (ix==0 || ix ==1)
                {
                        elems.push_back(1);
                }
                else
                {
                        elems.push_back(elems[ix-1]+elems[ix-2]);
                }
        }
        return &elems;
}

