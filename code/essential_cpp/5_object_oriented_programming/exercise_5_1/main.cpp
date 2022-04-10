#include <iostream>
#include <vector>


#include "Stack.h"
#include "LIFO_Stack.h"
#include "Peekback_Stack.h"


using namespace std;

int main()
{
        LIFO_Stack ls(10);

        ls.push(10);
        ls.push(20);
        ls.push(30);

        cout << ls.empty() << endl;
        cout << ls.full() << endl;
        cout << ls.peek() << endl;
        cout << ls.size() << endl;
        ls.pop();
        cout << ls.size() << endl;
        ls.print(cout);
        cout << ls << endl;


        return 0;
}