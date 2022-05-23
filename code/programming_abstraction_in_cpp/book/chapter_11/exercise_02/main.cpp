#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* Function Prototype*/
extern void generateGrayCode(int nBits);
extern void generateGrayCodeRec(int &times, string &input, const int nBits);

int main()
{
    int nBits = 0;
    cout << "Please enter a number: ";
    cin >> nBits;
    cout << endl;
    cout << "Generating gray code..." << endl;

    generateGrayCode(nBits);


    return 0;
}

void generateGrayCodeRec(int &times, string &input, const int nBits)
{

}

void generateGrayCode(int nBits)
{
    int num = int(pow(2, nBits));
    string input = "";
    generateGrayCodeRec(num, input, nBits);
}