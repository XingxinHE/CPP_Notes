#include <iostream>
#include <string>

using namespace std;

/* Function Prototype */
void generateBinaryCode(int nBits);
void generateBinaryCodeRec(int nBits, string input);

int main()
{
    int nBits = 0;
    cout << "Please enter a digit:";
    cin >> nBits;
    cout << "Generating the binary code..." << endl;
    generateBinaryCode(nBits);

    return 0;
}

/*
 * Function: generateBinaryCode
 * Usage: generateBinaryCode(3);
 * -----------------------------
 * Description: This function cout all the binary code of 'n' bits.
 */
void generateBinaryCode(int nBits)
{
    generateBinaryCodeRec(nBits, "");
}

/*
 * Function: generateBinaryCodeRec
 * Usage: generateBinaryCodeRec(nBits, "");
 * -----------------------------
 * Description: This is the helper function of generateBinaryCode.
 */
void generateBinaryCodeRec(int nBits, string input)
{
    if(nBits == 0)
    {
        cout << input << endl;
        return;
    }
    else
    {
        generateBinaryCodeRec(nBits - 1, input+"0");
        generateBinaryCodeRec(nBits - 1, input+"1");
    }
}