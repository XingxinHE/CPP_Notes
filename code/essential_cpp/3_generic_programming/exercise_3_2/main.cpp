#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include "console.h"
#include <algorithm>

using namespace std;

inline bool is_shorter(const string &str1, const string &str2)
{
    return str1.length() < str2.length()? true : false;
}

int main()
{
    // declare an infile
    ifstream infile;
    infile.open("serenity_prayer.txt");

    // map and set
    vector<string> words;
    set<string> word_exclusion{"a", "an", "or", "the", "and", "but"};

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

        words.push_back(tword);
    }

    // sorting the vector here
    // the last argument is the Comp
    sort(words.begin(), words.end(),is_shorter);


    // loop it
    vector<string>::iterator it;
    for(it = words.begin(); it!=words.end(); it++)
    {
        cout << *it << endl;
    }

    // close it beofore ending
    infile.close();

    return 0;
}
