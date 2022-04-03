#include <iostream>
#include <string>
#include <map>
#include "UserProfile.h"

using namespace std;

int main()
{
    UserProfile anon;
	cout << anon;


	UserProfile anon_too;
	cout << anon_too;

	UserProfile anna( "AnnaL", UserProfile::Guru );
	cout << anna;

	anna.bump_guess_count( 27 );
	anna.bump_guess_correct( 25 );
	anna.bump_login_count();

	cout << anna;

	cout << "OK: enter user profile data by hand to see if we can read it\n";
	cin >> anon;
	cout << anon;

    return 0;
}

// Exptected output is the following
// guest0 Beginner 1 0 0 0
// guest1 Beginner 1 0 0 0
// AnnaL Guru 1 0 0 0
// AnnaL Guru 2 27 25 92.5926
// OK: enter user profile data by hand to see if we can read it
// Susan Beginner 12 32 12 44
// Susan Beginner 12 32 12 37.5
