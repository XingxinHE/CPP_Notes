#include <iostream>
#include <string>
#include <cassert>
#include "hashmap.h"


using namespace std;

int main()
{
    HashMap openWith;

    openWith.put(string("txt"), string("notepad.exe"));
    openWith.put("bmp", "paint.exe");
    openWith.put("dib", "paint.exe");
    openWith["rtf"] = "wordpad.exe";


    // The Item property is the default property, so you
    // can omit its name when accessing elements.
    cout << "For key = \"rtf\"" << " value = " << openWith["rtf"] << endl;

    // The default Item property can be used to change the value
    // associated with a key.
    openWith["rtf"] = "winword.exe";
    cout << "For key = \"rtf\"" << " value = " << openWith.get("rtf") << endl;

    // If a key does not exist, setting the default Item property
    // for that key puts a new key/value pair.
    openWith["doc"] = "winword.exe";

    // containsKey can be used to test keys before inserting
    // them.
    if (!openWith.containsKey("ht"))
    {
        openWith.put("ht", "hypertrm.exe");
        cout << "Value puted for key = \"ht\" " << openWith["ht"] << endl;
    }

    // Use the Remove method to remove a key/value pair.
    cout << "\nRemove(\"doc\")" << endl;
    openWith.remove("doc");

    if (!openWith.containsKey("doc"))
    {
        cout << "Key \"doc\" is not found." << endl;
    }

    return 0;
}