#include <iostream>
#include <string>

using namespace std;


int main()
{
	string user_first_name;
	string user_last_name;
	cout << "Please enter your first name: ";
	cin >> user_first_name;
	cout << endl;
	cout << "Please enter your last name: ";
	cin >> user_last_name;
	cout << '\n'
	     << "Hello, "
	     << user_first_name << " " << user_last_name
	     << "... and goodbye!\n";

	return 0;
}
