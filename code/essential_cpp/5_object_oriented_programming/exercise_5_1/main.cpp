#include <iostream>
#include <vector>


#include "Stack.h"
#include "LIFO_Stack.h"
#include "Peekback_Stack.h"


using namespace std;

int main()
{
        /*
         *  LIFO_Stack Test Case
         */

        /************Init************/
        LIFO_Stack ls(10);

        /************Fill************/
        ls.push(10);
        ls.push(20);
        ls.push(30);

        /******Check if it is empty******/
        cout << ls.empty() << endl;

        /******Check if it is full******/
        cout << ls.full() << endl;

        /************Peek************/
        cout << ls.peek() << endl;

        /************Size************/
        cout << ls.size() << endl;

        /************Size after pop************/
        ls.pop();
        cout << ls.size() << endl;

        /************Print************/
        ls.print(cout);
        cout << ls << endl;

        /*
         *  Peekback_Stack Test Case
         */
        /************Init************/
        Peekback_Stack ps(10);

        /************Fill************/
        ps.push(10);
        ps.push(20);
        ps.push(30);

        /******Check if it is empty******/
        cout << ps.empty() << endl;

        /******Check if it is full******/
        cout << ps.full() << endl;

        /************Peek************/
        cout << ps.peek() << endl;

        /************Size************/
        cout << ps.size() << endl;

        /************Size after pop************/
        ps.pop();
        cout << ps.size() << endl;

        /************Print************/
        ps.print(cout);
        cout << ps << endl;

        /************Peek Out of Range************/
        cout << ps.peek(1024) << endl;

        return 0;
}