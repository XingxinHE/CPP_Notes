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

static const int    PASSWORD_LENGTH   = 5;
static const string PASSWORD_TO_CRACK = "yanxi";

bool login(string password) {
    return (password == PASSWORD_TO_CRACK);
}


string crackingRec(string current, int maxLength)
{
    if(login(current)) return current;
    if(current.length() == maxLength) return "";
    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        string password = crackingRec(current + ch, maxLength);
        if(password != "") return password;

        char upperCh = toupper(ch);
        password = crackingRec(current + upperCh, maxLength);
        if(password != "") return password;
    }
    return "";
}


string crackingPasswords(int n){
    if(n < 0) error("The length cannot be negative.");
    return crackingRec("", n);
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Example from handout.") {
    EXPECT_EQUAL(crackingPasswords(PASSWORD_LENGTH), PASSWORD_TO_CRACK);
}
