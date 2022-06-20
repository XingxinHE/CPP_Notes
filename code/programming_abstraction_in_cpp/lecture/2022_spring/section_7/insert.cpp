/*
 * CS106B Section Handout Test Harness: Section 6
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
#include <string>
#include "testing/SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "error.h"
using namespace std;

/*
 * Inserting into a Linked List (Code Writing)
 * --------------------------------------------------------
 * Write a function named insert that accepts a reference to a
 * StringNode pointer representing the front of a linked list,
 * along with an index and a string value. Your function should
 * insert the given value into a new node at the specified
 * position of the list.
 *
 * The other values in the list should retain
 * the same order as in the original list. You may assume that the
 * index passed is between 0 and the existing size of the list,
 * inclusive.
 *
 * Constraints: Do not modify the data field of existing nodes;
 * change the list by changing pointers only. Do not use any
 * auxiliary data structures to solve this problem (no array,
 * Vector, Stack, Queue, string, etc).
 */

void insert(StringNode*& front, int index, string value) {
    if(index < 0)
    {
        error("The index is negative.");
    }
    if(index == 0)
    {
        StringNode *node = new StringNode;
        node->data = value;
        node->next = front;
        front = node;
    }
    else
    {
        StringNode *temp = front;
        for(int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        StringNode *node = new StringNode;
        node->data = value;
        node->next = temp->next;
        temp->next = node;
    }
}

/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("Example from handout") {
    StringNode *originalList = createStringListFromVector({ "Katherine", "Julie", "Kate" });
    StringNode *solnList = createStringListFromVector({ "Katherine", "Julie", "Mehran", "Kate" });

    insert(originalList, 2, "Mehran");
    EXPECT(stringListEqual(solnList, originalList));
}
