#include "Circle.h"
using namespace std;
#include "testing/SimpleTest.h"
#include "gmath.h"
#include "strlib.h"


Circle::Circle(double r)
      :m_radius(r), m_diameter(r * 2)
{
}


/**
 * TODO: write a method comment
 */
double Circle::area() const {
   return PI * m_radius * m_radius;
}

/**
 * TODO: write a method comment
 */
double Circle::circumference() const{
    return PI * m_diameter;
}

/**
 * TODO: write a method comment
 */
double Circle::getRadius() const{
    return m_radius;
}

/**
 * TODO: write a method comment
 */
string Circle::toString() const{
    return "Circle{radius=" + realToString(m_radius) + "}";
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example"){
    Circle c(2.5);
    EXPECT_EQUAL(c.getRadius(), 2.5);
    EXPECT_EQUAL(c.circumference(), 2 * PI * 2.5);
    EXPECT_EQUAL(c.area(), PI * 2.5 * 2.5);
    EXPECT_EQUAL(c.toString(), "Circle{radius=2.5}");
}
