#include "WhatAreYouDoing.h"
#include "strlib.h"
using namespace std;


/*
 * Function: emphasesHelper
 * Usage:  emphasesHelper(0, tokens, emphases);
 * --------------------------------------------
 * Modify the words and emphases as pass by reference
 */
extern void emphasesHelper(int round, Vector<string> &words, Set<string> &emphases);

/*
 * Function: allEmphasesOf
 * Usage: EXPECT_EQUAL(allEmphasesOf("Hello"), expected);
 * ------------------------------------------------------
 * Return all the emphases of a sentence.
 */
Set<string> allEmphasesOf(const string& sentence) {

    // check validity
    if(sentence.length()==0)
    {
        error("The sentence is empty");
    }

    // tokens
    Vector<string> tokens = tokenize(sentence);

    // define output
    Set<string> emphases;

    // run
    emphasesHelper(0, tokens, emphases);

    return emphases;
}

/*
 * Function: emphasesHelper
 * Usage:  emphasesHelper(0, tokens, emphases);
 * --------------------------------------------
 * Modify the words and emphases as pass by reference
 */
void emphasesHelper(int round, Vector<string> &words, Set<string> &emphases)
{
    // the last one, concat and add to the set
    if(round == words.size())
    {
        string onePattern = stringJoin(words, "");
        emphases.add(onePattern);
    }
    // token is not a word
    else if(!isalpha(words[round][0]))
    {
        emphasesHelper(round + 1, words, emphases);
    }
    // it is a word, recurse call to upper and lower
    else
    {
        // upper recursion
        words[round] = toUpperCase(words[round]);
        emphasesHelper(round+1, words, emphases);  // a upper branch here

        // lower recursion
        words[round] = toLowerCase(words[round]);
        emphasesHelper(round+1, words, emphases);  // a lower branch here
    }
}

/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Enumerates all options in a simple case.") {
    Set<string> expected = {
        "hello",
        "HELLO",
    };

    EXPECT_EQUAL(allEmphasesOf("Hello"), expected);
}

PROVIDED_TEST("Each option has the right length.") {
    string sentence = "Hello, world!";
    for (string option: allEmphasesOf(sentence)) {
        EXPECT_EQUAL(option.length(), sentence.length());
    }
}

PROVIDED_TEST("Enumerates all options in a more typical case.") {
    Set<string> expected = {
        "you are?",
        "you ARE?",
        "YOU are?",
        "YOU ARE?"
    };

    EXPECT_EQUAL(allEmphasesOf("You Are?"), expected);
}

PROVIDED_TEST("Stress Test: Recursion only branches on words (should take under a second)") {
    /* We're producing a string consisting of fifty copies of the * character. This tokenizes
     * into fifty separate stars. A star is the same whether or not you capitalize it - there
     * is no such thing as an "upper-case" or "lower-case" star. Therefore, your code should
     * not try to form two versions of the sentence, one with the star capitalized and one
     * without, because the two versions will end up being the same and the work to compute
     * both options will dramatically increase the runtime.
     *
     * For reference, if you do try branching the recursion and checking what happens both if
     * you capitalize the star and if you don't, you'll try exploring 2^50 different possible
     * capitalizations. That's 1,125,899,906,842,624 options, and even doing a billion of
     * these a second is going to take over two years to generate them all! And of course,
     * that's all wasted work, since there's only one way to capitalize this sentence, and
     * that's just to leave it as-is.
     *
     * If your code is hanging when this test is running, it likely means that your code is
     * trying to enumerate all of these options. See if you can edit your code so that, if
     * you're given a non-word token, you just leave it as-is and don't change anything.
     */
    string punctuation(50, '*'); // 50 copies of *

    /* The only emphasis is itself. */
    Set<string> expected = {
        punctuation
    };

    EXPECT_EQUAL(allEmphasesOf(punctuation), expected);
}

PROVIDED_TEST("Stress test: Generates each option once (should take at most a few seconds)") {
    /* This sentence has 13 words in it. There are therefore 2^13 = 8192 possible emphases for
     * the words there, which is a big number but not so large that the computer can't handle
     * it if generates each emphasis exactly once.
     *
     * On the other hand, if your code tries to generate the same emphases multiple times,
     * this test may take a very, very long time to complete, and might even appear to freeze
     * up.
     *
     * If your code gets stuck in this test, trace through your code and confirm that you can't
     * produce the same emphasis multiple times. Check to make sure you aren't, for example,
     * looping over every token in the input sentence and deciding which one to capitalize
     * next. The recursion here follows more of an include/exclude type pattern (more like
     * subsets and combinations) than it does a "which is next?" type pattern (more like
     * permutations).
     */
    string yeats = "Turing and turning in a widening gyre / the falcon cannot hear the falconer.";
    EXPECT_EQUAL(allEmphasesOf(yeats).size(), 8192);
}

STUDENT_TEST("Critique on Shanghai's policy on COVID-19")
{
    Set<string> expected = {
        "SHANGHAI COVID POLICY IS SHIT.",
        "SHANGHAI COVID POLICY IS shit.",
        "SHANGHAI COVID POLICY is SHIT.",
        "SHANGHAI COVID POLICY is shit.",
        "SHANGHAI COVID policy IS SHIT.",
        "SHANGHAI COVID policy IS shit.",
        "SHANGHAI COVID policy is SHIT.",
        "SHANGHAI COVID policy is shit.",
        "SHANGHAI covid POLICY IS SHIT.",
        "SHANGHAI covid POLICY IS shit.",
        "SHANGHAI covid POLICY is SHIT.",
        "SHANGHAI covid POLICY is shit.",
        "SHANGHAI covid policy IS SHIT.",
        "SHANGHAI covid policy IS shit.",
        "SHANGHAI covid policy is SHIT.",
        "SHANGHAI covid policy is shit.",
        "shanghai COVID POLICY IS SHIT.",
        "shanghai COVID POLICY IS shit.",
        "shanghai COVID POLICY is SHIT.",
        "shanghai COVID POLICY is shit.",
        "shanghai COVID policy IS SHIT.",
        "shanghai COVID policy IS shit.",
        "shanghai COVID policy is SHIT.",
        "shanghai COVID policy is shit.",
        "shanghai covid POLICY IS SHIT.",
        "shanghai covid POLICY IS shit.",
        "shanghai covid POLICY is SHIT.",
        "shanghai covid POLICY is shit.",
        "shanghai covid policy IS SHIT.",
        "shanghai covid policy IS shit.",
        "shanghai covid policy is SHIT.",
        "shanghai covid policy is shit."
    };

    EXPECT_EQUAL(allEmphasesOf("SHANGHAI COVID POLICY IS SHIT."), expected);
}
