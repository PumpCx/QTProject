#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

    connect(ui->EndButton,&QPushButton::clicked,this,&MainWindow::onClickEndbutton);
    connect(ui->StartButton,&QPushButton::clicked,this,&MainWindow::onClickStartbutton);
    connect(timer,&QTimer::timeout,this,&MainWindow::processtar);

}

void MainWindow::onClickEndbutton(){
     timer->stop();
}

void MainWindow::onClickStartbutton()
{
     timer->start(200);
}

void MainWindow::processtar()
{
    num ++;
    if(num == 101)
    {
        num = 0;
    }
    ui->progressBar->setValue(num);

}
