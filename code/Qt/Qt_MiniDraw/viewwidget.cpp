#include "viewwidget.h"
#include "./ui_viewwidget.h"
#include <QMouseEvent>
#include <QPainter>

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewWidget)
{
    ui->setupUi(this);
    setDrawStatus(false);
}

ViewWidget::~ViewWidget()
{
    delete ui;
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
    if (Qt::LeftButton == event->button())
    {
        setDrawStatus(true);
        setStartPoint(event->pos());
        setEndPoint(event->pos());
    }
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





