#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix m;
    cout << m << endl;

	elemType ar[16]={
		1., 0., 0., 0., 0., 1., 0., 0.,
		0., 0., 1., 0., 0., 0., 0., 1. };

	Matrix identity( ar );
	cout << identity << endl;

	// guarantee default memberwise copy works correctly
	Matrix m2( identity );
	m = identity;

	cout << m2 << endl; cout << m  << endl;

	elemType ar2[16]={
		1.3f, 0.4f, 2.6f, 8.2f, 6.2f, 1.7f, 1.3f, 8.3f,
		4.2f, 7.4f, 2.7f, 1.9f, 6.3f, 8.1f, 5.6f, 6.6f };

	Matrix m3( ar2 );
	cout << m3 << endl;

	Matrix m4 = m3 * identity;
	cout << m4 << endl;

	Matrix m5 = m3 + m4;
	cout << m5 << endl;

	m3 += m4;
	cout << m3 << endl;
}