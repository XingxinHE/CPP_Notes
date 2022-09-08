#ifndef SHAPE_H
#define SHAPE_H

#include <QtGui>

class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual void draw(QPainter& paint) = 0;

    QPoint getStartPoint() const { return m_startPoint; }
    void setStartPoint(QPoint pt) { m_startPoint = pt; }

    QPoint getEndPoint() const { return m_endPoint; }
    void setEndPoint(QPoint pt) { m_endPoint = pt; }

    enum Type
    {
        kDefault = 0,
        kLine = 1,
        kRect = 2,
    };

protected:


private:
    QPoint m_startPoint;
    QPoint m_endPoint;
};

#endif // SHAPE_H
