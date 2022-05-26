/*
 * File: point.cpp
 * ---------------
 * This file implements the point.h interface.
 */

#include "point.h"

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variables x and y. In the
 * second form of the constructor, the parameter names are xc and yc
 * to avoid the problem of shadowing the instance variable.
 */

Point::Point()
      :x(0), y(0)
{
}

Point::Point(int xc, int yc)
      :x(xc), y(yc)
{
}

Point::~Point(){}


/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 * No setters are provided to ensure that Point objects are immutable.
 */

int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}


/*
 * Implementation notes: toString
 * -----------------------------
 * The implementation of toString uses the std::to_string function from STL.
 */

std::string Point::toString()
{
    std::string output = 
                        "(" + 
                        std::to_string(this->x) + 
                        ", " + 
                        std::to_string(this->y) + 
                        ")";

    return output;
}
