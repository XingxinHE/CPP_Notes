#include "Rectangle.h"

void Rectangle::draw(QPainter& painter)
{
    painter.drawRect(getStartPoint().x(), getStartPoint().y(),
        getEndPoint().x() - getStartPoint().x(), getEndPoint().y() - getStartPoint().y());
}
