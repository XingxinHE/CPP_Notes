#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction* m_action; 		// 👈declare the action pointer
    QMenu* m_menu; 			// 👈declare the menu pointer
    QToolBar* m_toolbar;    // 👈declare the toolbar pointer

    void createButton();    // 👈declare function to create the ui button

private slots:
    void HelloWorld();      // 👈declare slot function
};
#endif // MAINWINDOW_H
