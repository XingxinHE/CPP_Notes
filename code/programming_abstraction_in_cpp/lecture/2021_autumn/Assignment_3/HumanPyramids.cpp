#include "error.h"
#include "HumanPyramids.h"
#include "grid.h"
#include "map.h"
using namespace std;



double weightOnBackOfTable(GridLocation& gridLocation, Map<GridLocation, double>& table);

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */
double weightOnBackOf(int row, int col, int pyramidHeight) {
    Map<GridLocation, double> table;

    // check validity
    if(row < 0 || col < 0)
    {

        error("Row and Column can't be less than 0.");
    }
    if(row >= pyramidHeight)
    {
        error("Row is out of bound");
    }

    //recursion
    GridLocation current(row, col);
    return weightOnBackOfTable(current, table);
}

double weightOnBackOfTable(GridLocation& gridLocation, Map<GridLocation, double>& table)
{
    //base case
    if(gridLocation == GridLocation(0,0))
    {
        return 0;
    }
    else if(table.containsKey(gridLocation))
    {
        return table[gridLocation];
    }
    else
    {
        int next_row = gridLocation.row - 1;
        int next_col_left = gridLocation.col - 1;
        int next_col_right = gridLocation.col;
        if(next_col_left < 0)
        {
            GridLocation cellUpRight(next_row, next_col_right);
            table[gridLocation] =
                    0.5*(160 + weightOnBackOfTable(cellUpRight, table));
            return 0.5*(160 + weightOnBackOfTable(cellUpRight, table));
        }
        else if(next_col_right > next_row)
        {
            GridLocation cellUpLeft(next_row, next_col_left);
            table[gridLocation] =
                    0.5*(160 + weightOnBackOfTable(cellUpLeft, table));
            return 0.5*(160 + weightOnBackOfTable(cellUpLeft, table));
        }
        else
        {
            GridLocation cellUpLeft(next_row, next_col_left);
            GridLocation cellUpRight(next_row, next_col_right);

            table[gridLocation] = 0.5*(160 + weightOnBackOfTable(cellUpLeft, table)) +
                                  0.5*(160 + weightOnBackOfTable(cellUpRight, table));

            return 0.5*(160 + weightOnBackOfTable(cellUpLeft, table)) +
                    0.5*(160 + weightOnBackOfTable(cellUpRight, table));
        }
    }
}




/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */

    //SHOW_ERROR("This test is configured to always fail until you delete this line from\n         HumanPyramids.cpp. Once you have implemented memoization and want\n         to check whether it works correctly, remove the indicated line.");

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
