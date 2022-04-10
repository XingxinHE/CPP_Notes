/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include "strlib.h"
using namespace std;


static const string alphabet = "abcdefghijklmnopqrstuvwxyz";
static const string vowel = "aeiouy";

bool isVowel(char c)
{
    if((vowel.find(c) != string::npos) || (toUpperCase(vowel).find(c)!=string::npos))
    {
       return true;
    }
    else
    {
        return false;
    }
}

bool isAlphabet(char c)
{
    if((alphabet.find(c) != string::npos) || (toUpperCase(alphabet).find(c)!=string::npos))
    {
       return true;
    }
    else
    {
        return false;
    }
}

string onlyConnectize(string phrase) {

    int length = phrase.length();
    for(int i = length - 1; i >= 0; i--)
    {
        char c = phrase[i];
        if(isAlphabet(c) && !isVowel(c))
        {

        }
        else
        {
            phrase.erase(i, 1);
        }
    }

    return toUpperCase(phrase);
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Serenity Prayer") {
    EXPECT_EQUAL(onlyConnectize("God, grant me the serenity."), "GDGRNTMTHSRNT");
    EXPECT_EQUAL(onlyConnectize("Serenity Prayer"), "SRNTPRR");
    EXPECT_EQUAL(onlyConnectize(" Reinhold Niebuhr"), "RNHLDNBHR");
}

PROVIDED_TEST("Chinese Character") {
    EXPECT_EQUAL(onlyConnectize("记者提问：领导真的有走访过基层么？"), "");
    EXPECT_EQUAL(onlyConnectize("记者提问：因疫情身患重病不能及时医治的病人还有失业还不上贷款自杀的人加起来比因omicron病死的人多吗？"), "MCRN");
    EXPECT_EQUAL(onlyConnectize("记者提问：拉高gdp数字，继续吸纳二三线的青壮年来打工。"), "GDP");
}







