#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->hide();
    timer = new QTimer(this);
    timer->setInterval(1000);
    number = 99;
    connect(timer ,&QTimer::timeout,this,&MainWindow::timerfix);
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::timerfix()
{
    number--;
    if(number== 0)
    {
        timer->stop();
        ui->lcdNumber->hide();
        ui->textEdit->show();
    }
    ui->lcdNumber->display(number);
}
