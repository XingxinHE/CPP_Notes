#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include "console.h"



using namespace std;

typedef vector<string> vstring;

void populate_map( ifstream& infile, map<string,vstring> &families)
{
    string one_line;
    // read the infile line by line
    while(getline(infile, one_line, '\n'))
    {
        string family_name;
        vector<string> children_names;
        cout << "Reading one line: " << one_line << endl;

        // process one line
        string::size_type pos = 0, prev_pos = 0, text_size = one_line.size();
        if(!text_size)
        {
            continue;
        }

        // use ` ` as separator
        while( (pos = one_line.find_first_of(' ', pos)) != string::npos)
        {
            string::size_type end_pos = pos - prev_pos;
            // the 1st must be family name
            if(!prev_pos)
            {
                family_name = one_line.substr(prev_pos, end_pos);
            }
            // rest are chilrden names
            else
            {
                children_names.push_back(one_line.substr(prev_pos, end_pos));
            }
            prev_pos = ++pos;
        }

        // take care the last word
        if( prev_pos < text_size)
        {
            children_names.push_back(one_line.substr(prev_pos,pos-prev_pos));
        }

        cout << "Family Name: " << family_name
             << " Children: " << children_names.size() << endl;

        // add the children in familes
        if(!families.count(family_name))
        {
            families[family_name] = children_names;
        }
        else
        {
            cerr << "Already have a " << family_name << " family in our map" << endl;
        }
    }
}

void query_map( const string &family, const map<string,vstring> &families )
{
    map<string, vstring>::const_iterator it = families.find(family);

    // cannot find
    if( it == families.end())
    {
        cout << "Sorry. The " << family <<
                " family is not current entered." << endl;
        return;
    }

    cout << "The " << family << " family ";
    if(!it->second.size())
    {
        cout << "has no children." << endl;
    }
    else
    {
        cout << "has " << it->second.size() << " children: ";
        vector<string>::const_iterator iter;
        vector<string>::const_iterator end_iter;
        iter = it->second.begin();
        end_iter = it->second.end();

        while(iter!=end_iter)
        {
            cout << *iter << " ";
            iter++;
        }
        cout << endl;
    }
}

void display_map( const map<string,vstring> &families, ostream &os = cout )
{
    map<string, vstring>::const_iterator
            it = families.begin(),
            end_it = families.end();

    while(it!=end_it)
    {
        os << "The " << it->first << " family ";
        if(it->second.empty())
        {
            os << "has no children." << endl;
        }
        else
        {
            os << "has " << it->second.size() << " children: ";
            vector<string>::const_iterator
                    iter = it->second.begin(),
                    end_iter = it->second.end();

            while(iter != end_iter)
            {
                os << *iter << " ";
                iter++;
            }
            os << endl;
        }
        it++;
    }
}


void ex3_3()
{
    map< string, vstring > families;

    ifstream nameFile( "families.txt" );
    if ( !  nameFile ) {
            cerr << "Unable to find families.txt file. Bailing Out!\n";
            return;
    }

    populate_map( nameFile, families );

    string family_name;
    while ( true )
    {
        cout << "Please enter a family name or q to quit ";
        cin >> family_name;
        if ( family_name == "q" || family_name == "Q")
             break;
        query_map( family_name, families );
    }
    display_map( families );
}




int main()
{
    ex3_3();
    return 0;
}
