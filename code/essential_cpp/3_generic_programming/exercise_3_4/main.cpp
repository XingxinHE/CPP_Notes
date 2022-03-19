#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

inline bool is_even(const int &num)
{
    return num % 2 == 0? true : false;
}
inline bool is_odd(const int &num)
{
    return num % 2 != 0? true : false;
}

int main()
{
    // random numbers as infile
    ifstream infile("random_numbers.txt");
    // even numbers as outfile
    ofstream outfile_even("even_numbers_sorted.txt");
    // odd numbers as outfile
    ofstream outfile_odd("odd_numbers_sorted.txt");

    // error
    if(!infile || !outfile_even || !outfile_odd)
    {
        cerr << "Can't open such files..." << endl;
        return -1;
    }

    // vector to store numbers
    vector<int> numbers;

    // infile iterator
    istream_iterator<int> start(infile);
    istream_iterator<int> end;

    // even & odd outfile iterator
    ostream_iterator<int> os_even(outfile_even, "\n");
    ostream_iterator<int> os_odd(outfile_odd, "\n");

    // read the random numbers in
    copy(start, end, back_inserter(numbers));

    // sort it
    sort(numbers.begin(), numbers.end());

    // out even
    copy_if(numbers.begin(), numbers.end(), os_even, is_even);
    //out odd
    copy_if(numbers.begin(), numbers.end(), os_odd, is_odd);

    return 0;
}
