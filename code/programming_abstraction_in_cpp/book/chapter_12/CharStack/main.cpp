#include <iostream>
#include "charstack.h"

using namespace std;

int main()
{
    CharStack stack;
    
    cout << "Is the stack empty? Answer: ";
    cout << stack.isEmpty() << endl;

    cout << "What is the size of the stack? Answer: ";
    cout << stack.size() << endl;

    cout << "Start pushing..." << endl;
    stack.push('L');
    stack.push('O');
    stack.push('V');
    stack.push('E');

    cout << "Peek once. Result: ";
    cout << stack.peek() << endl;
    cout << "Check the size after peek. Answer: ";
    cout << stack.size() << endl;

    cout << "Pop once. Result: ";
    cout << stack.pop() << endl;
    cout << "Check the size after pop. Answer: ";
    cout << stack.size() << endl;

    cout << "Clear the stack." << endl;
    stack.clear();
    cout << "Check the size after clear. Answer: ";
    cout << stack.size() << endl;

    int count = 0;
    cout << "Resize test..." << endl;
    for (int i = 0; i < 26; i++)
    {
        stack.push(char('A' + i));
    }
    cout << "The size of the stack is: ";
    cout << stack.size() << endl;

    cout << "Start poping..." << endl;
    while(!stack.isEmpty())
    {
        cout << stack.pop();
        if (count % 8 == 0)
        {
            cout << endl;
        }
        count++;
    }
    

    cout << "Stress test..." << endl;
    for (int i = 0; i < 1000; i++)
    {
        stack.push(char(i));
    }
    cout << "The size of the stack is: ";
    cout << stack.size() << endl;

    cout << "Start poping..." << endl;
    while(!stack.isEmpty())
    {
        cout << stack.pop();
        if (count % 8 == 0)
        {
            cout << endl;
        }
        count++;
    }

    return 0;
}