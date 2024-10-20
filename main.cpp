#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile style(":/style.qss");
    style.open(QFile::ReadOnly);
    a.setStyleSheet(style.readAll());
    MainWindow w;
    w.show();
    w.resize(800, 600);
    return a.exec();
}
