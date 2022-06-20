/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "error.h"
using namespace std;

/*
 * isSubsequence (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function named isSubsequence that takes
 * two strings and returns true if the second string is a
 * subsequence of the first string. A string is a subsequence
 * of another if it contains the same letters in the same order,
 * but not necessarily consecutively. You can assume both
 * strings are already lower-cased.
 */

bool isSubsequence(string big, string small){
    if(small.empty()) return true;
    else if(big.empty()) return false;
    else
    {
        if(big[0]== small[0])
        {
            return isSubsequence(big.substr(1), small.substr(1));
        }
        else
        {
            return isSubsequence(big.substr(1), small);
        }
    }
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Examples from handout.") {
    EXPECT_EQUAL(isSubsequence("computer", "core"), false);
    EXPECT_EQUAL(isSubsequence("computer", "cope"), true);
    EXPECT_EQUAL(isSubsequence("computer", "computer"), true);
}


