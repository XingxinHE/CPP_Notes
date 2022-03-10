#include <iostream>

using namespace std;

int main()
{
        bool user_choice = true;
        while (user_choice)
        {
                cout << "Would you like to continue? Y/N" << endl;
                char input;
                cin >> input;
                if (input == 'N' || input == 'n')
                {
                        user_choice = false;
                }
        }

        cout << "The application is terminated." << endl;
        
        return 0;
}