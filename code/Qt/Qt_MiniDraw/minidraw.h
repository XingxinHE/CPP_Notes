#ifndef MINIDRAW_H
#define MINIDRAW_H

#include <QMainWindow>
#include "viewwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MiniDraw; }
QT_END_NAMESPACE

class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    MiniDraw(QWidget *parent = nullptr);
    ~MiniDraw();



private:
    Ui::MiniDraw *ui;

    QMenu *mp_menu; 			// 👈declare the menu pointer
    QToolBar *mp_toolbar;    // 👈declare the toolbar pointer

    QAction *mp_action_about;
    QAction *mp_action_line;
    QAction *mp_action_rectangle;



    ViewWidget *mp_viewwidget;

    void createMenu();
    void createToolBar();
    void createActions();

    void createAboutBox();
};
#endif // MINIDRAW_H
