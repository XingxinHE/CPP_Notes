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
#include "stack.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Balance (Code Write)
 * ----------------------------------
 * Write a function named checkBalance that accepts a string of
 * source code and uses a Stack to check whether the braces/parentheses
 * are balanced. Every ( or { must be closed by a } or ) in the opposite order.
 * Return the index at which an imbalance occurs, or -1 if the string is
 * balanced. If any ( or { are never closed, return the string’s length.
 */

int checkBalance(string code) {
    //Queue<int> q;

    return 0;
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("test cases from handout"){
    EXPECT_EQUAL(checkBalance("if (a(4) > 9) { foo(a(2)); }"), -1);
    EXPECT_EQUAL(checkBalance("for (i=0;i<a;(3};i++) { foo{); )"), 15);
    EXPECT_EQUAL(checkBalance("while (true) foo(); }{ ()"), 20);
    EXPECT_EQUAL(checkBalance("if (x) {"), 8);
}
