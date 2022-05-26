/*
 * File: point.h
 * -------------
 * This interface exports the Point class, which represents a point on
 * a two-dimensional integer grid.
 */

#ifndef _point_h
#define _point_h

#include <string>

class Point
{

public:

/*
 * Constructor: Point
 * Usage: Point origin;
 *        Point pt(xc, yc);
 * ------------------------
 * Creates a Point object. The default constructor sets the coordinates to 0;
 * the second form sets the coordinates to xc and yc.
 */
    Point();
    Point(int xc, int yc);
    ~Point();

/*
 * Methods: getX, getY
 * Usage: int x = pt.getX();
 *        int y = pt.getY();
 * -------------------------
 * Return the x and y coordinates of the point, respectively.
 */
    int getX();
    int getY();

/*
 * Methods: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Return a string representation of the Point in the form "(x,y)".
 */
    std::string toString();

private:
    int x;                  /* The x-coordinate */
    int y;                  /* The y-coordinate */
};

#endif