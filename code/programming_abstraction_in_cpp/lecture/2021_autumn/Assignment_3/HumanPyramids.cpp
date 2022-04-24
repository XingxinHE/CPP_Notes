#include "error.h"
#include "HumanPyramids.h"
#include "grid.h"
#include "map.h"
using namespace std;


// recursion helper function
double weightOnBackOfTable(GridLocation& gridLocation, Map<GridLocation, double>& table);

// recursion main function
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
    // value already recorded in the table
    else if(table.containsKey(gridLocation))
    {
        return table[gridLocation];
    }
    // value not recorded
    else
    {
        int next_row = gridLocation.row - 1;
        int next_col_left = gridLocation.col - 1;
        int next_col_right = gridLocation.col;
        // coord on the left edge
        if(next_col_left < 0)
        {
            GridLocation cellUpRight(next_row, next_col_right);
            table[gridLocation] =
                    0.5*(160 + weightOnBackOfTable(cellUpRight, table));
        }
        // coord on the right edge
        else if(next_col_right > next_row)
        {
            GridLocation cellUpLeft(next_row, next_col_left);
            table[gridLocation] =
                    0.5*(160 + weightOnBackOfTable(cellUpLeft, table));
        }
        // coord in between
        else
        {
            GridLocation cellUpLeft(next_row, next_col_left);
            GridLocation cellUpRight(next_row, next_col_right);

            table[gridLocation] = 0.5*(160 + weightOnBackOfTable(cellUpLeft, table)) +
                                  0.5*(160 + weightOnBackOfTable(cellUpRight, table));
        }

        // no matter which case, the gridLocation now has value
        // return it
        return table[gridLocation];
    }
}




/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

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

    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}
