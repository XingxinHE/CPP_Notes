#include "Simple_window.h"    // get access to our window library
#include "Graph.h"       // get access to our graphics library facilitiesint 

int main(){          
   using namespace Graph_lib;    // our graphics facilities are in Graph_lib          
   Point tl {100,100};     // to become top left corner of window          
   Simple_window win {tl,600,400,"Canvas"};     // make a simple window          
   Graph_lib::Polygon poly;       // make a shape (a polygon)          
   poly.add(Point{300,200});      // add a point          
   poly.add(Point{350,100});      // add another point          
   poly.add(Point{400,200});      // add a third point          
   poly.set_color(Color::red);      // adjust properties of poly          
   win.attach (poly);               // connect poly to the window      

   Axis xa{ Axis::x, Point{20,300}, 280, 10, "x axis" };
   Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };

   Function sine{ sin, 0, 100, Point{20, 150}, 1000, 50, 50 };
   win.attach(xa);
   win.attach(ya);
   win.attach(sine);
   win.wait_for_button();      // give control to the display engine
}