#include "mainwindow.h"
#include "variaveis.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w ;
    w.show();
    return a.exec();
}
