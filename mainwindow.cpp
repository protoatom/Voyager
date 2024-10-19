#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    btn_search = new QPushButton("&Search");
    webView = new QWebEngineView();
    line_edit = new QLineEdit();
    grid = new QGridLayout();

    mainWidget = new QWidget();


    grid -> addWidget(line_edit, 0, 0);
    grid -> addWidget(btn_search, 0, 9);

    grid -> addWidget(webView, 1, 0, 1, 10); //lol

    mainWidget->setLayout(grid);
    setCentralWidget(mainWidget);

    connect(btn_search, SIGNAL(clicked()), this, SLOT(press_btn_search()));

}

void MainWindow::press_btn_search()
{
    webView -> load(QUrl(line_edit->text()));
}

MainWindow::~MainWindow() {}
