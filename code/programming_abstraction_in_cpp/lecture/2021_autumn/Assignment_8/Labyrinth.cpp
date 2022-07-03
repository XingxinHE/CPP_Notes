#include "Labyrinth.h"
#include "set.h"
#include "queue.h"
using namespace std;

MazeCell* direction(MazeCell* cell, char ch)
{
    switch(ch)
    {
    case 'E':
        return cell->east;
    case 'S':
        return cell->south;
    case 'W':
        return cell->west;
    case 'N':
        return cell->north;
    default:
        error("No such direction!");
    }
}

bool isPathToFreedomHelper(MazeCell* start, Queue<char>& steps, Set<Item> &items)
{
    // either the next step is empty or the wall towards wall
    if(start == nullptr)
    {
        return items.isEmpty();
    }
    // if all the items are collected, win!
    if(items.isEmpty())
    {
        return true;
    }

    // see what is in here
    Item item = start->whatsHere;
    if (item != Item::NOTHING)
    {
        items.remove(item);
        //start->whatsHere = Item::NOTHING;
    }

    // run out of step?
    if(steps.isEmpty())
    {
        return items.isEmpty();
    }

    // next iteration
    MazeCell* _direction = direction(start, steps.dequeue());
    return isPathToFreedomHelper(_direction, steps, items);
}

bool isPathToFreedom(MazeCell* start, const string& moves) {
    Set<Item> items{Item::POTION, Item::SPELLBOOK, Item::WAND};
    Queue<char> steps;
    for(char m : moves)
    {
        steps.enqueue(m);
    }
    return isPathToFreedomHelper(start, steps, items);
}


/* * * * * * Test Cases Below This Point * * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/MazeGenerator.h"

/* Optional: Add your own custom tests here! */














/* * * * * Provided Tests Below This Point * * * * */

/* Utility function to free all memory allocated for a maze. */
void deleteMaze(const Grid<MazeCell*>& maze) {
    for (auto* elem: maze) {
        delete elem;
    }
    /* Good question to ponder: why don't we write 'delete maze;'
     * rather than what's shown above?
     */
}

PROVIDED_TEST("Checks paths in the sample maze.") {
    auto maze = toMaze({"* *-W *",
                        "| |   |",
                        "*-* * *",
                        "  | | |",
                        "S *-*-*",
                        "|   | |",
                        "*-*-* P"});

    /* These paths are the ones in the handout. They all work. */
    EXPECT(isPathToFreedom(maze[2][2], "ESNWWNNEWSSESWWN"));   //FAILED
    EXPECT(isPathToFreedom(maze[2][2], "SWWNSEENWNNEWSSEES"));
    EXPECT(isPathToFreedom(maze[2][2], "WNNEWSSESWWNSEENES"));

    /* These paths don't work, since they don't pick up all items. */
    EXPECT(!isPathToFreedom(maze[2][2], "ESNW"));
    EXPECT(!isPathToFreedom(maze[2][2], "SWWN"));
    EXPECT(!isPathToFreedom(maze[2][2], "WNNE"));

    /* These paths don't work, since they aren't legal paths. */
    EXPECT(!isPathToFreedom(maze[2][2], "WW"));
    EXPECT(!isPathToFreedom(maze[2][2], "NN"));
    EXPECT(!isPathToFreedom(maze[2][2], "EE"));
    EXPECT(!isPathToFreedom(maze[2][2], "SS"));

    deleteMaze(maze);
}

PROVIDED_TEST("Can't walk through walls.") {
    auto maze = toMaze({"* S *",
                        "     ",
                        "W * P",
                        "     ",
                        "* * *"});

    EXPECT(!isPathToFreedom(maze[1][1], "WNEES"));
    EXPECT(!isPathToFreedom(maze[1][1], "NWSEE"));
    EXPECT(!isPathToFreedom(maze[1][1], "ENWWS"));
    EXPECT(!isPathToFreedom(maze[1][1], "SWNNEES"));

    deleteMaze(maze);
}

PROVIDED_TEST("Works when starting on an item.") {
    auto maze = toMaze({"P-S-W"});

    EXPECT(isPathToFreedom(maze[0][0], "EE"));  //failed
    EXPECT(isPathToFreedom(maze[0][1], "WEE"));
    EXPECT(isPathToFreedom(maze[0][2], "WW"));

    deleteMaze(maze);
}

