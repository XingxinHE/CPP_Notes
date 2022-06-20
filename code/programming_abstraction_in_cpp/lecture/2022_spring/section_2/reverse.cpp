/*
 * CS106B Section Handout Test Harness: Section 8
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
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "lexicon.h"
#include "error.h"
using namespace std;

/*
 * Container Classes Review (Code Writing)
 * --------------------------------------------------------
 * Write a function that is given a Map<string, int> that associates
 * string values with integers and produces a Map<int, Set<string>>
 * that’s essentially the reverse mapping, associating each integer
 * value with the set of strings that map to it. (This is an old job
 * interview question from 2010.)
 */

Map<int, Set<string>> reverseMap(Map<string, int>& map) {
    Map<int, Set<string>> result;
    for(const string &key : map)
    {
        int num = map[key];
        result[num].add(key);
    }
    return result;
}

PROVIDED_TEST("Simple Tests for Reversing Map"){
    Map<string, int> map = {{"foo", 4}, {"bar", 4}, {"baz", 3}};
    Map<int, Set<string>> reversed = reverseMap(map);
    Map<int, Set<string>> soln = {{4, {"bar", "foo"}}, {3, {"baz"}}};

    EXPECT_EQUAL(reversed, soln);

    map = {};
    reversed = reverseMap(map);
    soln = {};
    EXPECT_EQUAL(reversed, soln);
}
