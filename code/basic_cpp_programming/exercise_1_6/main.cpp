#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int const array_length = 5;

	cout << "==========Array Version:==========" << endl;

	int numbers[array_length];
	for (int i = 0; i < array_length; i++)
	{
		cout << "Please enter a number..." << i + 1 << "/" << array_length << endl;
		cin >> numbers[i];
	}
	int sum = 0;
	for (int num : numbers)
	{
		sum += num;
	}
	cout << "The sum is: " << sum << endl;
	cout << "The average is: " << sum / array_length << endl;

	cout << "==========Vector Version:==========" << endl;
	vector<int> numbers_vector(array_length);
	for (int i = 0; i < array_length; i++)
	{
		cout << "Please enter a number..." << i + 1 << "/" << array_length << endl;
		cin >> numbers_vector[i];
	}
	int sum_vector = 0;
	for (int num : numbers_vector)
	{
		sum_vector += num;
	}
	cout << "The sum is: " << sum_vector << endl;
	cout << "The average is: " << sum_vector / array_length << endl;

	return 0;
}
