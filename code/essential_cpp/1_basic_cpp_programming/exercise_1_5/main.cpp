#include <iostream>
#include <string>

using namespace std;


int main()
{
	string user_name;
	cout << "Please enter your first name: " << endl;
	cin >> user_name;
	while(user_name.length() < 2)
	{
		cout << "Oops... Please enter your first name at least 2 character long..." << endl;
		cin >> user_name;
	}
	cout << "Hello! " << user_name << endl;

	char user_last_name[10];
	cout << user_name << ", what is your last name?" << endl;
	cin >> user_last_name;
	cout << "Oh! Your last name is: " << user_last_name << endl;	



	return 0;
}
