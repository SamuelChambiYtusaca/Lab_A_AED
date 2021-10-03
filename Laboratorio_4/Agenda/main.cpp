#include "mainwindow.h"
#include "agenda.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Agenda *agenda1 = new Agenda();
    MainWindow w(nullptr,agenda1);
    a.setStyle("fusion");
    w.show();
    return a.exec();
}
