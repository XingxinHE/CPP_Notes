#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{

        vector<string> pockets = 
        {
                "FIRE",
                "WATER",
                "ELECTRIC",
                "GRASS",
                "ICE",
        };
        vector<string>* pockets_pointer = &pockets;
        string player_selection;

        int num;
        cout << "Please select a number from 1 to 5..." << endl;
        cin >> num;
        switch (num)
        {
        case 1:
                player_selection = (*pockets_pointer)[0];
                break;

        case 2:
                player_selection = (*pockets_pointer)[1];
                break;
        case 3:
                player_selection = (*pockets_pointer)[2];
                break;
        case 4:
                player_selection = (*pockets_pointer)[3];
                break;
        case 5:
                player_selection = (*pockets_pointer)[4];
                break;
        default:
                break;
        }

        cout << "You have selected " << player_selection << " type Pokémon." << endl;

        return 0;
}
