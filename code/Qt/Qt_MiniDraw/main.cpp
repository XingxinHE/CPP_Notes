#include "minidraw.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MiniDraw w;
    w.show();
    return a.exec();
}
