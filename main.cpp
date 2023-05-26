#include "fmmainmenu.h"
#include <QApplication>

#include "common.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FmMainMenu w;
    w.show();

    return a.exec();
}
