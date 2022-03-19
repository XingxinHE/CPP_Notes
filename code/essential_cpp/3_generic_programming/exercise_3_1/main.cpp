#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include "console.h"
#include <algorithm>

using namespace std;

int main()
{
    // declare an infile
    ifstream infile;
    infile.open("serenity_prayer.txt");

    // map and set
    map<string, int> words;
    set<string> word_exclusion{"a", "an", "or", "the", "and", "but", ",", "."};

    // read the file(failed?)
    if(!infile)
    {
        cout << "unable to open this text file." << endl;
        exit(1);
    }

    // read the file
    string tword;
    while(infile >> tword)
    {

        transform(tword.begin(), tword.end(), tword.begin(), ::tolower);
        // TWO conditions
        // a.last char is not `,` and `.`
        // b.not in the word exclusion
        if(',' == tword.at(tword.length()-1))
        {
            tword.pop_back();
        }
        if('.' == tword.at(tword.length()-1))
        {
            tword.pop_back();
        }
        if(word_exclusion.count(tword))
        {
            continue;
        }

        words[tword]++;
    }

    // loop it
    map<string, int>::iterator it;
    for(it = words.begin(); it!=words.end(); it++)
    {
        cout << "Key: " << it->first << " "
             << "Value: " << it->second << " " << endl;
    }


    // close it beofore ending
    infile.close();

    return 0;
}
