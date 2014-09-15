#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QLCDNumber>
#include <QMainWindow>
#include <QMessageBox>
#include "fileio.h"
using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent(QCloseEvent *);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void showTime();
    void startTime();
    string checkUser();

private:
    Ui::MainWindow *ui;
    QLCDNumber *stopwa;
    QTime *time;
    QTimer *timer;
    bool punched_;
    fileio io_;

};

#endif // MAINWINDOW_H
