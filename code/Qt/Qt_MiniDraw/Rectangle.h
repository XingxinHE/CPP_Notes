#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QtGui>
#include "Shape.h"

class Rectangle : public Shape
{
public:
    void draw(QPainter& paint) override;
protected:
private:
};


#endif
