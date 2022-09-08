#include "viewwidget.h"
#include "./ui_viewwidget.h"
#include <QMouseEvent>
#include <QPainter>

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewWidget)
{
    ui->setupUi(this);
    m_drawStatus = false;
}

ViewWidget::~ViewWidget()
{
    delete ui;
}

void ViewWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drawStatus)
    {
        m_endPoint = event->pos();
    }
}

void ViewWidget::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        m_drawStatus = true;
        m_startPoint = m_endPoint = event->pos();
    }
}

void ViewWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_drawStatus = false;
}

void ViewWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(m_startPoint, m_endPoint);
    painter.end();
    update();
}





