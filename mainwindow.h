#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QWebEngineView>
#include <QPushButton>
#include <QTabWidget>
#include <QGridLayout>
#include <QIcon>
#include <QFile>
#include <QUrl>
#include <QString>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* ---variables--- */
    int tab_start = 1;
    /* ---widgets--- */
    QWidget *mainWidget;
    QTabWidget *tabs;
    /* ---line edits--- */
    QLineEdit *lineSearch;
    /* ---web view--- */
    QWebEngineView *webView;
    /* ---buttons--- */
    QPushButton *btn_back;
    QPushButton *btn_reload;
    QPushButton *btn_forward;
    QPushButton *btn_search;
    QPushButton *btn_menu;
    /* ---layouts--- */
    QGridLayout *grd;

public slots:
    void on_btn_search_clicked();
    void slots_close_tab(int index);
    void on_btn_back_clicked();
    void on_btn_forward_clicked();
    void on_btn_reload_clicked();
    void on_btn_menu_clicked();
    void click_on_link_new_tab(const QString &url);
};
#endif // MAINWINDOW_H
