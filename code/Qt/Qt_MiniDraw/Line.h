#ifndef LINE_H
#define LINE_H

#include <QtGui>
#include "Shape.h"

class Line : public Shape
{
public:
    Line();
    ~Line() override;
    void draw(QPainter& paint) override;
protected:
private:
};


#endif
