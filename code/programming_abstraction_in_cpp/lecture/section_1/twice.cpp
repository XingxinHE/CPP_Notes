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
#include "set.h"
#include "vector.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Twice (Code Write)
 * ----------------------------------
 * Write a function named twice that takes a vector of integers
 * and returns a set containing all the numbers in the vector
 * that appear exactly twice.
 */

Set<int> twice(Vector<int> nums){
    return {};
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("test case from handout"){
    Vector<int> v = {1, 3, 1, 4, 3, 7, -2, 0, 7, -2, -2, 1};
    Set<int> soln = {3, 7};
    EXPECT_EQUAL(twice(v), soln);
}
