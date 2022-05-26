#include <iostream>
#include "point.h"

int main()
{
    Point pt1;
    Point pt2(1, -1);
    std::cout << "pt1: " << pt1.toString() << std::endl;
    std::cout << "pt2: " << pt2.toString() << std::endl;

    return 0;
}