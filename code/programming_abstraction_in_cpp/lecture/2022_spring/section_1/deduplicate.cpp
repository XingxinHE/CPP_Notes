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
#include "vector.h"
#include "strlib.h"
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
using namespace std;

/*
 * Remove Consecutive Duplicates (Debugging)
 * --------------------------------------------------------
 * Below is a buggy implementation of a function that is supposed to remove
 * consecutive duplicates from a vector. Unfortunately there are 3 bugs. Can you find
 * them and fix the code so that it passes all of the tests?
 */

// My Solution
void deduplicate(Vector<string> &vec) {
    if (vec.isEmpty())
    {
        return;
    }

    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        // prevent the index out of range
        while ( (i + 1 < size) && (vec[i] == vec[i + 1]))
        {
            vec.remove(i + 1);
            size = vec.size();  // update the size, so the for loop shrink
        }
    }
}

// smart increment
void deduplicate1(Vector<string> &vec)
{
    for(int i = 0; i < vec.size();)
    {
        if( (i+1<vec.size()) && (vec[i]==vec[i+1]))
        {
            vec.remove(i+1);
        }
        else
        {
            i++;
        }
    }
}

// smart decrement
void deduplicate2(Vector<string> &vec)
{
    for(int i = vec.size()-1; i>0; i--)
    {
        if(vec[i] == vec[i-1])
        {
            vec.remove(i);
        }
    }
}


/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Provided Test: Verifies our solution works on the empty vector.") {
    Vector<string> v = {};
    Vector<string> empty = {};
    deduplicate(v);
    EXPECT_EQUAL(v, empty);
}

PROVIDED_TEST("Provided Test: Verifies removeDuplicates works on a simple vector.") {
    Vector<string> v = {"Katherine Johnson",
                        "Katherine Johnson",
                        "Katherine Johnson",
                        "Mary Jackson",
                        "Dorothy Vaughan",
                        "Dorothy Vaughan"};
    Vector<string> vNoDup = {"Katherine Johnson", "Mary Jackson", "Dorothy Vaughan"};
    deduplicate(v);
    EXPECT_EQUAL(v, vNoDup);
}

#include "random.h"
PROVIDED_TEST("Provided Test: STRESS TEST - Verifies removeDuplicates works on a large vector") {
    const int K_NUM_MAX = 10000;
    Vector<string> largeVec;
    for (size_t i = 0; i < K_NUM_MAX; i++) {
        int numRepeats = randomInteger(1, 5);
        for (int j = 0; j < numRepeats; j++) {
            largeVec += integerToString(i);
        }
    }
    deduplicate(largeVec);
    for (size_t i = 0; i < K_NUM_MAX; i++) {
        EXPECT_EQUAL(largeVec[i], integerToString(i));
    }
}


