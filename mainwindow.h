#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QGridLayout>
#include <QPushButton>
#include <QWebEngineView>
#include <QLineEdit>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QGridLayout *grid;
    QWebEngineView *webView;
    QPushButton *btn_search;
    QLineEdit *line_edit;
public slots:
    void press_btn_search();

};
#endif // MAINWINDOW_H
