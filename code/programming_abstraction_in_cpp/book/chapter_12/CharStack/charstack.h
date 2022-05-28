/*
 * File: charstack.h
 * -----------------
 * This interface defines the CharStack class, which implements
 * the stack abstraction for characters.
 */

#ifndef _charstack_h
#define _charstack_h

#include <iostream>

/*
 * Class: CharStack
 * ----------------
 * This class models a stack of characters. The fundamental operations
 * are the same as those for the Stack<char> class.
 */
class CharStack
{

public:
/*
 * Constructor: CharStack
 * Usage: CharStack cstk;
 * ----------------------
 * Initializes a new empty stack that can contain characters.
 */
    CharStack();

/*
 * Constructor: CharStack
 * Usage: CharStack cstk(src);
 * ----------------------
 * Initializes the current object to be a deep copy of the specified source.
 */
    CharStack(const CharStack &src);

/*
 * Destructor: ~CharStack
 * ----------------------
 * Free any heap storage associated with this character stack.
 */
    ~CharStack();

/*
 * Method: size
 * Usage: int nElems = cstk.size();
 * --------------------------------
 * Returns the number of characters in this stack.
 */
    int size() const;

/*
 * Method: isEmpty
 * Usage: if(cstk.isEmpty()) ...  ;
 * --------------------------------
 * Returns true if this stack contains no characters.
 */
    bool isEmpty() const;

/*
 * Method: clear
 * Usage: cstk.clear();
 * --------------------
 * Removes all characters from this stack.
 */
    void clear();

/*
 * Method: push
 * Usage: cstk.push('A');
 * --------------------
 * Pushes the character onto this stack.
 */
    void push(char input);

/*
 * Method: pop
 * Usage: char ch = cstk.pop();
 * ----------------------------
 * Removes the top character from the stack and returns it.
 */
    char pop();

/*
 * Method: peek
 * Usage: char ch = cstk.peek();
 * -----------------------------
 * Removes the value of the top character from this stack without
 * removing it.
 */
    char peek() const;

/*
 * Operator: =
 * Usage: dst = src;
 * -----------------
 * Assign src to dst so that the two stacks are independent copies.
 */
CharStack & operator=(const CharStack &src);

private:
/*  Private constants  */
    static const int INITIAL_CAPACITY = 10;
/*  Instance Variables  */
    int m_capacity;
    int m_count;
    char *m_pArray;
/*  Private function prototypes  */
    void resize(bool isIncrement);
    void deepCopy(const CharStack &src);
};


#endif
