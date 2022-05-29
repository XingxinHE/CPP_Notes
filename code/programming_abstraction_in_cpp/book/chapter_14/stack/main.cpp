#include <iostream>
#include "stack.h"

using namespace std;

extern void printLine();

int main()
{
    Stack<char> stack;
    
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

    cout << "Declare a stack push S-E-X..." << endl;
    Stack<char> stack1;
    stack1.push('S');
    stack1.push('E');
    stack1.push('X');
    printLine();

    cout << "Start testing copy constructor..." << endl;
    Stack<char> copyStack(stack1);
    cout << "Popping the element..." << endl;
    while(!copyStack.isEmpty())
    {
        cout << copyStack.pop() << endl;;
    }
    printLine();

    cout << "Start testing equal operator..." << endl;
    Stack<char> equalStack = stack1;
    cout << "Popping the element..." << endl;
    while(!equalStack.isEmpty())
    {
        cout << equalStack.pop() << endl;;
    }
    printLine();

    cout << "Start testing stack with int..." << endl;
    Stack<int> intStack;
    intStack.push(1994);
    intStack.push(10);
    intStack.push(28);
    cout << "Popping the element..." << endl;
    while(!intStack.isEmpty())
    {
        cout << intStack.pop() << endl;;
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