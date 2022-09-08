#ifndef MINIDRAW_H
#define MINIDRAW_H

#include <QMainWindow>
#include "viewwidget.h"
#include <string>
#include <map>

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


    ViewWidget *mp_viewwidget;

    void createMenu();
    void createToolBar();
    void createActions();

    void createAboutBox();

    std::map<const char *, QAction*> actions;
    const char *ABOUT = "&About";
    const char *RECTANGLE = "&Rectangle";
    const char *LINE = "&Line";
};
#endif // MINIDRAW_H
