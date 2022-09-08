#include "minidraw.h"
#include "./ui_minidraw.h"
#include <QToolBar>

MiniDraw::MiniDraw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiniDraw)
{
    ui->setupUi(this);
    createActions();
    createToolBar();
    createMenu();

    mp_viewwidget = new ViewWidget();


    setCentralWidget(mp_viewwidget);
}

void MiniDraw::createActions()
{
    mp_action_about = new QAction(tr("&About"), this);
    mp_action_line = new QAction(tr("&Line"), this);
    mp_action_rectangle = new QAction(tr("&Rectangle"), this);
}

void MiniDraw::createToolBar()
{
    mp_toolbar = addToolBar(tr("&Tool Bar"));
    mp_toolbar->addAction(mp_action_about);
    mp_toolbar->addAction(mp_action_line);
    mp_toolbar->addAction(mp_action_rectangle);
}

void MiniDraw::createMenu()
{
    mp_menu = menuBar()->addMenu(tr("&Menu"));
    mp_menu->addAction(mp_action_about);
    mp_menu->addAction(mp_action_line);
    mp_menu->addAction(mp_action_rectangle);
}



MiniDraw::~MiniDraw()
{
    delete ui;
}

