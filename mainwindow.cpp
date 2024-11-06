#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* ---new objects--- */
    mainWidget = new QWidget();
    lineSearch = new QLineEdit();
    webView = new QWebEngineView();
    btn_back = new QPushButton();
    btn_reload= new QPushButton();
    btn_forward = new QPushButton();
    btn_search = new QPushButton();
    btn_menu = new QPushButton();
    grd = new QGridLayout();
    tabs = new QTabWidget();
    tabs -> setTabsClosable(true);

    /* ---placement--- */
    grd -> addWidget(btn_back, 0, 0);
    btn_back -> setIcon(QIcon(":/icons/back_icon.png"));

    grd -> addWidget(btn_reload, 0, 1);
    btn_reload -> setIcon(QIcon(":/icons/reload_icon.png"));

    grd -> addWidget(btn_forward, 0, 2);
    btn_forward -> setIcon(QIcon(":/icons/forward_icon.png"));

    grd -> addWidget(lineSearch, 0, 3);

    grd -> addWidget(btn_search, 0, 4);
    btn_search -> setIcon(QIcon(":/icons/search_icon.png"));
    btn_search -> setShortcut(Qt::Key_Return);

    grd -> addWidget(btn_menu, 0, 5);
    btn_menu -> setIcon(QIcon(":/icons/menu_icon.png"));

    grd ->addWidget(tabs, 1, 0, 1, 6);
    webView -> setUrl(QUrl("https://www.google.com/"));
    tabs -> addTab(webView, "New Tab");

    mainWidget -> setLayout(grd);
    setCentralWidget(mainWidget);

    /* ---logic--- */
    QObject::connect(btn_search, &QPushButton::clicked, this, &MainWindow::on_btn_search_clicked);
    QObject::connect(tabs, &QTabWidget::tabCloseRequested, this, &MainWindow::slots_close_tab);
    QObject::connect(btn_back, &QPushButton::clicked, this, &MainWindow::on_btn_back_clicked);
    QObject::connect(btn_reload, &QPushButton::clicked, this, &MainWindow::on_btn_reload_clicked);
    QObject::connect(btn_forward, &QPushButton::clicked, this, &MainWindow::on_btn_forward_clicked);
    QObject::connect(btn_menu, &QPushButton::clicked, this, &MainWindow::on_btn_menu_clicked);


}

MainWindow::~MainWindow() {}

void MainWindow::on_btn_search_clicked()
{
    if (lineSearch -> text() == "") {  }
    else {
        webView = new QWebEngineView(this);
        webView -> setUrl(QUrl("https://www.google.com/search?q=" + lineSearch -> text()));
        tabs -> addTab(webView, "Результаты поиска - " + lineSearch -> text());
    }
}

void MainWindow::slots_close_tab(int index)
{
    if ((tabs->count()-1) == 0) { this -> close(); }
    tabs -> removeTab(index);
}

void MainWindow::on_btn_back_clicked()
{
    webView -> page() -> triggerAction(QWebEnginePage::Back);
}

void MainWindow::on_btn_forward_clicked()
{
    webView -> page() -> triggerAction(QWebEnginePage::Forward);
}

void MainWindow::on_btn_reload_clicked()
{
    webView -> page() -> triggerAction(QWebEnginePage::Reload);
}

void MainWindow::on_btn_menu_clicked()
{

}

void MainWindow::click_on_link_new_tab(const QString &url)
{

}
