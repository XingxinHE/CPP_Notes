#include "viewwidget.h"
#include "./ui_viewwidget.h"
#include <QMouseEvent>
#include <QPainter>

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

void ViewWidget::setRectangle()
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
                mp_shape = new class Rectangle();
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

    for (int i = 0; i < m_vectorShape.size(); i++)
    {
        m_vectorShape[i]->draw(painter);
    }

    if (mp_shape != nullptr) {
        mp_shape->draw(painter);
    }

    update();
}





