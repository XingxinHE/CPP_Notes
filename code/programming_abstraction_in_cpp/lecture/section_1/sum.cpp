/*
 * CS106B Section Handout Test Harness: Section 1
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */
#include <iostream>
#include <string>
#include <fstream>
#include "vector.h"
#include "filelib.h"
#include "grid.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Sum Numbers (Code Write)
 * ----------------------------------
 * Write a program to read through a given file and sum
 * all of the numbers in the file. You can assume that numbers
 * will be composed entirely of numerical digits, optionally
 * preceded by a single negative sign.
 */
int sumNumbers(string filename){
    // declare ifstream
    ifstream inFile(filename);

    // handle file cann't open
    if(!inFile)
    {
        cerr << filename << " failed to open." << endl;
        return 0;
    }

    // each lines as Vector<string>
    Vector<string> lines;
    readEntireFile(inFile, lines);

    int sum = 0;

    // loop each line
    for(string s : lines)
    {
        // loop each word
        Vector<string> words = stringSplit(s, " ");
        for(string str : words)
        {
            if (stringIsInteger(str))
            {
                // cast to int if string is int
                int num = stringToInteger(str);
                sum += num;
            }
        }
    }
    return sum;
}


/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("given file in handout"){
    EXPECT_EQUAL(sumNumbers("res/numbers.txt"), 42);
}

PROVIDED_TEST("Nonexistent file should sum to zero") {
    EXPECT_EQUAL(sumNumbers("nonexistent_filename"), 0);
}

