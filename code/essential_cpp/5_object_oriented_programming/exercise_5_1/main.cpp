#include <iostream>
#include <vector>


#include "Stack.h"
#include "LIFO_Stack.h"
#include "Peekback_Stack.h"


using namespace std;

int main()
{
        cout << "======================================================================" << endl;
        cout << "==========================Test on LIFO_Stack==========================" << endl;
        cout << "======================================================================" << endl;
        cout << "======================================================================" << endl;

        Stack *s_ptr = new LIFO_Stack(10);

        s_ptr->push(10);
        s_ptr->push(20);
        s_ptr->push(30);

        cout << "LIFO_Stack size: " << s_ptr->size() << endl;

        int peek1;
        if(s_ptr->peek(1, peek1))
        {
                cout << "LIFO_Stack peeks success!" << endl;
        }
        else
        {
                cout << "LIFO_Stack peeks failed!" << endl;
        }

        int pop1;
        if(s_ptr->pop(pop1))
        {
                cout << "LIFO_Stack pops success!" << endl;
                cout << "Value: " << pop1 << endl;
        }
        else
        {
                cout << "LIFO_Stack pops failed!" << endl;
        }

        cout << "Printing LIFO_Stack:  " << *s_ptr << endl;
        cout << "Is LIFO_Stack empty?:  " << s_ptr->empty() << endl;
        cout << "Is LIFO_Stack full?:  " << s_ptr->full() << endl;


        cout << "======================================================================" << endl;
        cout << "========================Test on Peekback_Stack========================" << endl;
        cout << "======================================================================" << endl;
        cout << "======================================================================" << endl;



        s_ptr = new Peekback_Stack(6);
        s_ptr->push(1);
        s_ptr->push(3);
        s_ptr->push(5);
        s_ptr->push(7);
        s_ptr->push(9);

        int peek2;
        if(s_ptr->peek(3, peek2))
        {
                cout << "Peekback_Stack peeks success!" << endl;
                cout << "Value is : " << peek2 << endl;
        }
        else
        {
                cout << "Peekback_Stack peeks failed!" << endl;
        }

        

        return 0;
}