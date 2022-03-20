#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

int main()
{
        Stack sta;
        sta.push("Hello");
        sta.push("World!");

        string peek_value;
        string pop_value_1;
        string pop_value_2;

        cout << "Is stack full? " << sta.full() << endl;
        cout << "Is stack empty? " << sta.empty() << endl;
        cout << "Current size of stack? " << sta.size() << endl;

        sta.peek(peek_value);
        cout << "Peek once? " << peek_value << endl;

        sta.pop(pop_value_1);
        cout << "Pop once? " << pop_value_1 << endl;

        sta.pop(pop_value_2);
        cout << "Pop twice? " << pop_value_2 << endl;

        return 0;
}