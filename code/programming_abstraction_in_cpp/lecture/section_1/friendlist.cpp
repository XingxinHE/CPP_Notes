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
#include "map.h"
#include "vector.h"
#include "filelib.h"
#include "strlib.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Friend List (Code Write)
 * ----------------------------------
 * Write a function named friendList that takes in a file name and reads
 * friend relationships from a file and writes them to a Map.
 * friendList should return the populated Map. Friendships are bi-directional.
 * The file contains one friend relationship per line, with names separated
 * by a single space. You do not have to worry about malformed entries.
 */

Map<string, Vector<string>> friendList(string filename){
    return {};
}


///* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("provided test case from handout"){
    Map<string, Vector<string>> soln;
    soln["Abby"] = {"Barney", "Clyde"};
    soln["Barney"] = {"Abby"};
    soln["Clyde"] = {"Abby"};
    EXPECT_EQUAL(soln, friendList("res/buddies.txt"));
}
