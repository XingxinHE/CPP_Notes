#include <iostream>
#include "charstack.h"

using namespace std;

extern void printLine();

int main()
{
    CharStack stack;
    
    cout << "Is the stack empty? Answer: ";
    cout << stack.isEmpty() << endl;
    printLine();

    cout << "What is the size of the stack? Answer: ";
    cout << stack.size() << endl;
    printLine();

    cout << "Start pushing..." << endl;
    stack.push('L');
    stack.push('O');
    stack.push('V');
    stack.push('E');
    printLine();

    cout << "Peek once. Result: ";
    cout << stack.peek() << endl;
    cout << "Check the size after peek. Answer: ";
    cout << stack.size() << endl;
    printLine();

    cout << "Pop once. Result: ";
    cout << stack.pop() << endl;
    cout << "Check the size after pop. Answer: ";
    cout << stack.size() << endl;
    printLine();

    cout << "Clear the stack." << endl;
    stack.clear();
    cout << "Check the size after clear. Answer: ";
    cout << stack.size() << endl;
    printLine();

    int count = 0;
    cout << "Resize test..." << endl;
    for (int i = 0; i < 26; i++)
    {
        stack.push(char('A' + i));
    }
    cout << "The size of the stack is: ";
    cout << stack.size() << endl;
    printLine();

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
    printLine();

    cout << "Stress test..." << endl;
    for (int i = 0; i < 1000; i++)
    {
        stack.push(char(i));
    }
    cout << "The size of the stack is: ";
    cout << stack.size() << endl;
    printLine();

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
    printLine();

    return 0;
}

void printLine()
{
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;
}