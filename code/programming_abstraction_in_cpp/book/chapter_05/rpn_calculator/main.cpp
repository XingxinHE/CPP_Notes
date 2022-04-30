/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */
#include <iostream>
#include <cctype>
#include <cmath>
#include "console.h"
#include "simpio.h"
#include "stack.h"
#include "strlib.h"
using namespace std;

/*
 * Function: welcomeMessage
 * Usage: welcomeMessage();
 * ------------------------
 * The welcome message of this program.
 */
void welcomeMessage();

/*
 * Function: promptHelp
 * Usage: promptHelp();
 * --------------------
 * Prompt the help message when you press H/h.
 */
void promptHelp();

/*
 * Constant: operators
 * -------------------
 * Define the supported operators in this program.
 */
const string operators = "+-*/";

/*
 * Function: isOperator
 * Usage: bool flag = isOperator("+");
 * -----------------------------------
 * Determine whether a string is a operator.
 */
bool isOperator(string input);

/*
 * Function: applyOperator
 * Usage: double result = applyOperator("+", 10, 20);
 * --------------------------------------------------
 * Mimic the behavior of RPN calculator once you press the operator key.
 */
double applyOperator(string input, double lhs, double rhs);

int main()
{

    welcomeMessage();
    Stack<double> numbers;

    while (true)
    {
        string line = getLine("> ");
        if(line == "Q" || line == "q")
        {
            break;
        }
        else if(line == "H" || line == "h")
        {
            promptHelp();
        }
        else if(line == "C" || line == "c")
        {
            numbers.clear();
        }
        else if(stringIsReal(line))             //⭐ when it is a double, push
        {
            numbers.push(stringToReal(line));
        }
        else if(isOperator(line))               //⭐ takes out 2 number, apply
        {
            double rhs = numbers.pop();
            double lhs = numbers.pop();

            double result = applyOperator(line, lhs, rhs);
            cout << "> " << result << endl;

            numbers.push(result);
        }
        else
        {
            error("Invalid input!!");
        }
    }

    return 0;
}




void welcomeMessage()
{
    cout << "Welcome to RPN Calculator Simulation (type H for help)"
         << endl;
}

void promptHelp()
{
    cout << "Enter expression in Reverse Polish Notation," << endl;
    cout << "in which operators follow the operands to which" << endl;
    cout << "that apply. Each line consists of a number, an" << endl;
    cout << "operator, or one of the following command:" << endl;
    cout << "    Q -- Quit the program" << endl;
    cout << "    H -- Display this help message" << endl;
    cout << "    C -- Clear the calculator stack" << endl;
}

bool isOperator(string input)
{
    if(operators.find(input) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double applyOperator(string input, double lhs, double rhs)
{
    char o = stringToChar(input);

    switch(o)
    {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/': return lhs / rhs;
    }

    error("The operator is invalid!");
    return __DBL_EPSILON__;
}
