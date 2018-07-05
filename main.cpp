#include "mainwindow.h"
#include <QApplication>
#include <fstream>
fstream error;
fstream write;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
