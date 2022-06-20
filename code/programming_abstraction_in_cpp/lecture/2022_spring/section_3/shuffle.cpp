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
#include <algorithm>
#include "random.h"
#include <string>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Random Shuffling (Code Writing)
 * --------------------------------------------------------
 * One simple algorithm for shuffling a deck of cards is based on the following idea:
 *      * Choose a random card from the deck and remove it.
 *      * Shuffle the rest of the deck.
 *      * Place the randomly-chosen card on top of the deck.
 *      * Assuming that we choose the card that we put on top uniformly at random
 *        from the deck, this ends up producing a random shuffle of the deck.
 *
 * Write a function that accepts as input a string, then returns a random
 * permutation of the elements of the string using the above algorithm.
 * Your algorithm should be recursive and not use any loops (for, while, etc.).
 *
 */

string randomShuffle(string input){
    int length = input.length();
    if(length == 0)
    {
        return "";
    }
    else
    {
        int index = randomInteger(0, length - 1);
        return input[index] +
               randomShuffle(input.substr(0, index) +
                             input.substr(index + 1));
    }
}



/* * * * * Provided Tests Below This Point * * * * */

// Since this algorithm is based on randomness, we cannot expect an exact output,
// but we can verify the validity of the solution.

PROVIDED_TEST("Provided Test: Verify that solution is at least valid permutation.") {
    string res = randomShuffle("23456789JQKA");
    sort(res.begin(), res.end());
    EXPECT_EQUAL(res, "23456789AJKQ");
}
