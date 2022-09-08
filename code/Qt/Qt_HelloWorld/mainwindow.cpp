#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QToolBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //👈UI initialization, the first most function to be invoked
    createButton();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createButton()
{
    // 👇create action which labeled with "Hello world"
    // the & here is to set the shortcut for the label, e.g. 'H'
    m_action = new QAction(tr("&Hello world"), this);

    // 👇connect the signal and the slot
    // connect(signal sender, type of signal, signal receiver, slot function)
    connect(m_action, &QAction::triggered, this, &MainWindow::HelloWorld);

    // 👇create menu with label "Menu"
    m_menu = menuBar()->addMenu(tr("&Menu"));
    // put action to the menu
    m_menu->addAction(m_action);

    // 👇create tool bar with label "Tool Bar"
    m_toolbar = addToolBar(tr("&Tool Bar"));
    // add action to the tool bar
    m_toolbar->addAction(m_action);
}

void MainWindow::HelloWorld()
{
    // 👇the slot function mererly pops up a message box
    QMessageBox::about(this, tr("Hello world"),
        tr("Well done! Go ahead."));
}
