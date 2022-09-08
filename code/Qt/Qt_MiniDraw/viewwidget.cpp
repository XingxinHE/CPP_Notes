#include "viewwidget.h"
#include "./ui_viewwidget.h"
#include <QMouseEvent>
#include <QPainter>
#include "Line.h"
#include "Rectangle.h"

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewWidget)
    , m_type{Shape::kDefault}
    , mp_shape{nullptr}
{
    ui->setupUi(this);
    setDrawStatus(false);
}

ViewWidget::~ViewWidget()
{
    delete ui;
}

void ViewWidget::setLine()
{
    m_type = Shape::kLine;
}

void ViewWidget::setRect()
{
    m_type = Shape::kRect;
}

void ViewWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (getDrawStatus())
    {
        setEndPoint(event->pos());
    }
}

void ViewWidget::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton != event->button()) return;

    switch (m_type)
    {
    case Shape::kLine:
                mp_shape = new Line();
                break;
            case Shape::kDefault:
                break;

            case Shape::kRect:
                mp_shape = new Rectangle();
                break;
    }

    if (nullptr != mp_shape)
    {
        setDrawStatus(true);
        setStartPoint(event->pos());
        setEndPoint(event->pos());
        mp_shape->setStartPoint(event->pos());
        mp_shape->setEndPoint(event->pos());
    }

    update();
}

void ViewWidget::mouseReleaseEvent(QMouseEvent *event)
{
    setDrawStatus(false);
}

void ViewWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(getStartPoint(), getEndPoint());
    painter.end();
    update();
}





