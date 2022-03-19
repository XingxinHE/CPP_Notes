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


void populate_map( ifstream&, map<string,vstring> &families);
void display_map( const map<string,vstring> &families, ostream &os = cout );
void query_map( const string &family, const map<string,vstring> &families );

void populate_map( ifstream& infile, map<string,vstring> &families)
{
    string one_line;
    while(getline(infile, one_line, '\n'))
    {
        string family_name;
        vector<string> children_names;

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
