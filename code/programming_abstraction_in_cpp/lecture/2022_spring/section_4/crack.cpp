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
#include "error.h"
using namespace std;

/*
 * Cracking Passwords (Code Writing)
 * --------------------------------------------------------
 * Write a function crack that takes in the maximum length a
 * site allows for a user's password and tries to find the
 * password into an account by using recursive backtracking to
 * attempt all possible passwords up to that length (inclusive).
 */

bool login(string password) {
    return (password == "csizawesome");
}



string crackingPasswords(int n){
    // TODO: Your code here
    return "";
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Example from handout.") {
    EXPECT_EQUAL(crackingPasswords(11), "csizawesome");
}
