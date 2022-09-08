#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ViewWidget; }
QT_END_NAMESPACE

class ViewWidget : public QWidget
{
    Q_OBJECT

public:
    ViewWidget(QWidget *parent = nullptr);
    ~ViewWidget();

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:
    Ui::ViewWidget *ui;

    bool m_drawStatus;
    QPoint m_startPoint;
    QPoint m_endPoint;
};
#endif // VIEWWIDGET_H
