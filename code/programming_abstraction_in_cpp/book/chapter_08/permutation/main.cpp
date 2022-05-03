#include "console.h"
#include "simpio.h"
#include "set.h"
#include <string>
#include <iostream>


using namespace std;

/* Functions Prototype */
Set<string> generatePermutation(string str);

/* Main Program */
int main()
{
    string str = getLine("Enter a string: ");
    cout << "The permutation of \"" << str << "\" are: " << endl;
    for(string s : generatePermutation(str))
    {
        cout << "  \"" << s << "\"" << endl;
    }

    return 0;
}

/*
 * Function: generatePermutation
 * Usage: Set<string> permutation = generatePermutation(str);
 * ----------------------------------------------------------
 * Generate the permutation of a string.
 */
Set<string> generatePermutation(string str)
{
    // the idea is that, each recurse has sole set
    Set<string> result;
    if(str == "")
    {
        result += "";
    }
    else
    {
        // the length of the string is THE thing minimize
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            string rest = str.substr(0, i) + str.substr(i + 1);
            // iterate each combination and
            // don't over think here, trust the recursive leap of faith
            for(const string &s : generatePermutation(rest))
            {
                result += (ch + s);
            }
        }
    }
    return result;
}
