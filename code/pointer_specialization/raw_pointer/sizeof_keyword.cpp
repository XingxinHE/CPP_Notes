#include <iostream>

using namespace std;

int main()
{
    int arr[5]{ 1,2,3,4,5 };
    // sizeof(i) = total bytes
    // int j = sizeof(i) / sizeof(i[0]);
    // func(i,j);
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;

    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}