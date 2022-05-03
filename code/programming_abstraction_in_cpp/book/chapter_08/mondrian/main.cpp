#include "simpio.h"
#include "set.h"
#include "gwindow.h"
#include "random.h"
#include <string>
#include <iostream>


using namespace std;

/* Constant */
const double MIN_AREA = 10000;
const double MIN_EDGE = 20;

/* Functions Prototype */
void subdivideCanvas(GWindow &gw, double x,     double y,
                                  double width, double height);

/* Main Program */
int main()
{
    GWindow gw(1920, 1080);
    gw.setColor("black");  // set the stroke color
    subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());

    return 0;
}

/*
 * Function: subdivideCanvas
 * Usage: subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
 * ----------------------------------------------------------------
 * Decomposes the specified rectangular region on the canvas recursively
 * by splitting that rectangle randomly along its larger dimension. The
 * recursion continues until the area falls below the constant MIN_AREA
 */
void subdivideCanvas(GWindow &gw, double x,     double y,
                                  double width, double height)
{
    if(width * height >= MIN_AREA)
    {
        // horizontal rectangle
        if(width > height)
        {
            double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
            subdivideCanvas(gw, x,       y, mid,         height);
            subdivideCanvas(gw, x + mid, y, width - mid, height);
            gw.drawLine(x + mid, y, x + mid, y + height);
        }
        // vertical rectangle
        else
        {
            double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
            subdivideCanvas(gw, x, y,       width, mid);
            subdivideCanvas(gw, x, y + mid, width, height - mid);
            gw.drawLine(x, y + mid, x + width, y + mid);

        }
    }
}
