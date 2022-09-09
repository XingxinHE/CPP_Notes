#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewWidget; }
QT_END_NAMESPACE

class ViewWidget : public QWidget
{
    Q_OBJECT

public:
    ViewWidget(QWidget *parent = nullptr);
    ~ViewWidget();

    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent *) override;

    bool getDrawStatus() const {return m_drawStatus;}
    void setDrawStatus(bool status) {m_drawStatus= status;}

    QPoint getStartPoint() const {return m_startPoint;}
    void setStartPoint(QPoint pt) {m_startPoint = pt;}

    QPoint getEndPoint() const {return m_endPoint;}
    void setEndPoint(QPoint pt) {m_endPoint = pt;}

private:
    Ui::ViewWidget *ui;

    bool m_drawStatus;
    QPoint m_startPoint;
    QPoint m_endPoint;

    Shape::Type m_type;
    Shape* mp_shape;
    std::vector<Shape *> m_vectorShape;

signals:
public slots:
    void setLine();
    void setRectangle();
};
#endif // VIEWWIDGET_H
