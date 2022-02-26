#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
        ifstream in_file("./names.txt");
        ofstream out_file("./names_sorted.txt");



        /* Reading names... */
        if (!in_file)
        {
                cout << "Failed to read file..." << endl;
                return 0;
        }
        string name;
        vector<string> names;
        int count = 0;
        cout << "Start reading names..." << endl;
        while (in_file >> name)
        {
                names.push_back(name);
                count++;
        }
        cout << "Congrats! " << count << " names found." << endl;

        /* Sorting names... */
        cout << "Start sorting the names..." << endl;
        sort(names.begin(), names.end());
        cout << "Start saving to the new file..." << endl;

        /* Writing sorted names... */
        if (!out_file)
        {
                cout << "Failed to create output file..." << endl;
                return 0;
        }
        for (string n : names)
        {
                out_file << n << endl;
        }
        cout << "Sorting complete." << endl;

        return 0;
}
