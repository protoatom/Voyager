#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile dark_theme(":/styles/dark_theme.qss");
    dark_theme.open(QFile::ReadOnly);
    a.setStyleSheet(dark_theme.readAll());
    MainWindow w;
    w.show();
    w.resize(1000, 700);
    return a.exec();
}
