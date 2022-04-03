#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

int main()
{
    // test 1
    cout << "Test 1:" << endl;
    Matrix m;
    cout << m << endl;

    // test 2
    cout << "Test 2:" << endl;
    elemType ar[16]={
        1., 0., 0., 0., 0., 1., 0., 0.,
        0., 0., 1., 0., 0., 0., 0., 1. };
    Matrix identity( ar );
    cout << identity << endl;

    // test 3&4
    cout << "Test 3:" << endl;
    Matrix m2( identity );
    m = identity;
    cout << m2 << endl; 
    cout << "Test 4:" << endl;
    cout << m  << endl;

    // test 5
    cout << "Test 5:" << endl;
    elemType ar2[16]={
        1.3f, 0.4f, 2.6f, 8.2f, 6.2f, 1.7f, 1.3f, 8.3f,
        4.2f, 7.4f, 2.7f, 1.9f, 6.3f, 8.1f, 5.6f, 6.6f };
    Matrix m3( ar2 );
    cout << m3 << endl;

    // test 6
    cout << "Test 6:" << endl;
    Matrix m4 = m3 * identity;
    cout << m4 << endl;

    // test 7
    cout << "Test 7:" << endl;
    Matrix m5 = m3 + m4;
    cout << m5 << endl;
    
    // test 8
    cout << "Test 8:" << endl;
    m3 += m4;
    cout << m3 << endl;
}

// expected output
// test 1
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// test 2
// 1 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 1
// test 3
// 1 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 1
// test 4
// 1 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 1
// test 5
// 1.3 0.4 2.6 8.2 6.2 1.7 1.3 8.3
// 4.2 7.4 2.7 1.9 6.3 8.1 5.6 6.6
// test 6
// 1.3 0.4 2.6 8.2 6.2 1.7 1.3 8.3
// 4.2 7.4 2.7 1.9 6.3 8.1 5.6 6.6
// test 7
// 2.6 0.8 5.2 16.4 12.4 3.4 2.6 16.6
// 8.4 14.8 5.4 3.8 12.6 16.2 11.2 13.2
// test 8
// 2.6 0.8 5.2 16.4 12.4 3.4 2.6 16.6
// 8.4 14.8 5.4 3.8 12.6 16.2 11.2 13.2
