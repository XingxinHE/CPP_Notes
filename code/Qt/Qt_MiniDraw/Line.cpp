#include "Line.h"

void Line::draw(QPainter& painter)
{
    painter.drawLine(getStartPoint(), getEndPoint());
}
