#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* Function Prototypes */
int fibon(int size);

int main()
{
        cout << isdigit(7) << endl;
        cout << isdigit('7') << endl;
        cout << isalnum(7) << endl;
        cout << toupper(7) << endl;
        cout << toupper('A') << endl;
        cout << tolower('A') << endl;
        cout << "Fibonacci 0: " << fibon(0) << endl;
        cout << "Fibonacci 1: " << fibon(1) << endl;
        cout << "Fibonacci 2: " << fibon(2) << endl;
        cout << "Fibonacci 3: " << fibon(3) << endl;
        cout << "Fibonacci 4: " << fibon(4) << endl;
        cout << "Fibonacci 5: " << fibon(5) << endl;
        return 0;
}

/*
 * Function: fibon
 * Usage: int result = fibon(5);
 * -----------------------------
 * Compute the fibonacci result at certain size.
 */
int fibon(int size)
{
        if (size == 0)
        {
                return 0;
        }
        if(size == 1)
        {
                return 1;
        }

        return fibon(size - 1) + fibon(size - 2);
}