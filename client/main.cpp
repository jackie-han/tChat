// #include "mainwindow.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    Login l;
    l.show();
    return a.exec();
}
