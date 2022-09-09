#include "minidraw.h"
#include "./ui_minidraw.h"
#include <QToolBar>
#include <QMessageBox>

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
    actions[ABOUT] = new QAction(tr(ABOUT), this);
    actions[LINE] = new QAction(tr(LINE), this);
    actions[RECTANGLE] = new QAction(tr(RECTANGLE), this);
    actions[FREEHAND] = new QAction(tr(FREEHAND), this);
    actions[CIRCLE] = new QAction(tr(CIRCLE), this);
    actions[CLEAN] = new QAction(tr(CLEAN), this);

    connect(actions[ABOUT], &QAction::triggered, this, &MiniDraw::createAboutBox);
    connect(actions[LINE], SIGNAL(triggered()), mp_viewwidget, SLOT(setLine()));
    connect(actions[RECTANGLE], &QAction::triggered, mp_viewwidget, &ViewWidget::setRectangle);
}

void MiniDraw::createToolBar()
{
    mp_toolbar = addToolBar(tr("&Tool Bar"));
    for(auto action : actions)
    {
        mp_toolbar->addAction(action.second);
    }
}

void MiniDraw::createMenu()
{
    mp_menu = menuBar()->addMenu(tr("&Menu"));
    for(auto action : actions)
    {
        mp_menu->addAction(action.second);
    }
}

void MiniDraw::createAboutBox()
{
    QMessageBox::about(this, tr("About"), tr("MiniDraw"));
}



MiniDraw::~MiniDraw()
{
    delete ui;
}

