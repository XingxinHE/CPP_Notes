#include <string>
#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "random.h"

using namespace std;

/* Constant */
const double SIZE = 200;
const int ORDER = 4;

/* Function Prototypes */
GPoint drawFractalLine(GWindow &gw, GPoint pt, double r, double theta, int order);

/* Main Program */
int main()
{
    GWindow gw;
    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;
    GPoint pt(cx - SIZE/2, cy -sqrt(3.0) * SIZE/6);

    gw.setColor("black");  // set the stroke color
    drawFractalLine(gw, pt, SIZE, 0, ORDER);
    drawFractalLine(gw, pt, SIZE, 120, ORDER);
    drawFractalLine(gw, pt, SIZE, -120, ORDER);

    return 0;
}

/*
 * Function: drawFractalLine
 * Usage: GPoint end = drawFractalLine(gw, pt, SIZE, 0, ORDER);
 * ------------------------------------------------------------
 * Draw a fractal edge starting from pt and extending r units in direction
 * theta. If order > 0, the edge is divided into four fractal edges of the
 * next lower order. The function returns the endpoint of the line.
 */
GPoint drawFractalLine(GWindow &gw, GPoint pt, double r, double theta, int order)
{
    if(order == 0)
    {
        return gw.drawPolarLine(pt, r, theta);
    }
    else
    {
        pt = drawFractalLine(gw, pt, r / 3, theta, order - 1);
        pt = drawFractalLine(gw, pt, r / 3, theta + 60, order - 1);
        pt = drawFractalLine(gw, pt, r / 3, theta - 60, order - 1);
        return pt = drawFractalLine(gw, pt, r / 3, theta, order - 1);
    }

}
