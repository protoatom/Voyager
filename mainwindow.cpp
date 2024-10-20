#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    mainWidget = new QWidget();
    settingWidget = new QWidget();


    btn_search = new QPushButton();
    btn_search -> setObjectName("btn_search");
    btn_search -> setIcon(QIcon(":/search_icon.png"));

    context_menu = new QPushButton("");
    context_menu -> setIcon(QIcon(":/context_menu.png"));
    context_menu -> setObjectName("context_menu_btn");

    webView = new QWebEngineView();
    webView -> load(QUrl("https://www.google.com"));

    lineSearch = new QLineEdit();

    grd = new QGridLayout();


    grd -> addWidget(context_menu, 0, 2);
    grd -> addWidget(lineSearch, 0, 0);
    grd -> addWidget(btn_search, 0, 1);
    grd -> addWidget(webView, 1, 0, 1, 3);

    connect(btn_search, SIGNAL(clicked()), this, SLOT(btn_search_clicked()));
    connect(context_menu, SIGNAL(clicked()), this, SLOT(setting_clicked()));

    mainWidget -> setLayout(grd);
    setCentralWidget(mainWidget);



}

void MainWindow::btn_search_clicked()
{
    webView -> load(QUrl(lineSearch->text()));
}
void MainWindow::setting_clicked()
{
}

MainWindow::~MainWindow() {}
