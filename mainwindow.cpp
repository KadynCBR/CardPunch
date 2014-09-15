#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Grab the ui's LCDNumber as a variable.
    punched_ = false;
    stopwa = ui->lcdNumber;
    // Call start time, which will zero out.
    startTime();
    stopwa->setDigitCount(9);
    // Start the timer and connect it to show time so it updates ever 1000ms(1s).
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
}

void MainWindow::showTime() {
    // If punched is true, add one second everytime showTime is called.
    if (punched_ == true) {
        *time = time->addSecs(1);
    }
    // Convert time to string.
    QString time_text=time->toString("hh:mm:ss");
    // Display string in UI's LCDNumber
    stopwa->display(time_text);
    stopwa->setSegmentStyle(QLCDNumber::Flat);
}

void MainWindow::startTime() {
    // Start Time, zero out.
    time = new QTime();
    time->setHMS(0,0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (checkUser() == "") {
        // Error: Must Select User.
        QMessageBox::information(NULL, "User Error", "Please Select a User.");
    } else {
        // Start punch toggle.
        if (punched_ == true) {
            punched_ = false;
            ui->pushButton->setText("CLOCK IN");
        } else {
            punched_ = true;
            ui->pushButton->setText("CLOCK OUT");
        }
    }
}

string MainWindow::checkUser() {
    if (ui->comboBox->currentText() == "Kadyn") {
        return "Kadyn";
    }
    else if (ui->comboBox->currentText() == "Sebastian") {
        return "Sebastian";
    } else {
        return "";
    }
}

void MainWindow::closeEvent(QCloseEvent * e) {
    io_.OutputToFile(time, checkUser());
}
