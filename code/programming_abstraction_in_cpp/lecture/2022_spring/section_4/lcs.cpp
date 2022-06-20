/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Chase Davis for CS106B
 * Fall 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
using namespace std;

/*
 * Longest Common Subsequence(Code Writing)
 * --------------------------------------------------------
 * Your task is to write a function that takes as input two strings
 * and return the longest common substring.
 */

string longestCommonSubsequence(string s1, string s2){
    // TODO: Your code here
    return "";
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: 1 char unmatched.") {
    EXPECT_EQUAL(longestCommonSubsequence("cs106a", "cs106b"), "cs106" );
}

PROVIDED_TEST("Provided Test: 1 char matched.") {
    EXPECT_EQUAL(longestCommonSubsequence("nick", "julie"), "i");
}

PROVIDED_TEST("Provided Test: No char matching.") {
    EXPECT_EQUAL(longestCommonSubsequence("karel", "c++"), "");
}

PROVIDED_TEST("Provided Test: Sea Shells") {
    EXPECT_EQUAL(longestCommonSubsequence("she sells", "seashells"), "sesells");
}

