#include "mainwindow.h"
#include <QtDebug>

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
    browser_menu = new QMenu("", this);
    OSINT = new QAction("Osint", browser_menu);
    Trafic = new QAction("Анализатор трафика", browser_menu);
    Page = new QAction("Эта страница", browser_menu);
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



    /* -- Start Page -- */

    webView -> load(QUrl("qrc:/main_page/main_page.html"));
    tabs -> addTab(webView, "Wellcome");
    /*  --Main Widget-- */

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
    if (lineSearch -> text().isEmpty()) {  }
    else if (lineSearch -> text().startsWith("https://") || lineSearch -> text().startsWith("http://"))
    {
        webView = new QWebEngineView(this);
        webView -> setUrl(QUrl(lineSearch -> text()));
        tabs -> addTab(webView, lineSearch -> text());

    }
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
    QWebEngineView *current = qobject_cast<QWebEngineView *>(tabs->currentWidget());
    if (current) {
        current->reload();
    }
}

void MainWindow::on_btn_menu_clicked()
{
    browser_menu -> exec(btn_menu->mapToGlobal(QPoint(0, btn_menu->height())));
    browser_menu -> addAction(OSINT);
    browser_menu -> addAction(Trafic);
    browser_menu -> addAction(Page);
}

