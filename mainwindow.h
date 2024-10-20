#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QUrl>
#include <QWidget>
#include <QGridLayout>
#include <QWebEngineView>
#include <QLineEdit>
#include <QFile>
#include <QString>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *btn_search;
    QPushButton *setting;
    QWidget *mainWidget;
    QWidget *settingWidget;
    QGridLayout *grd;
    QWebEngineView *webView;
    QLineEdit *lineSearch;

public slots:
    void btn_search_clicked();
    //void setting_clicked();
};
#endif // MAINWINDOW_H
