#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
         qDebug()<<"left";
    }
    else if(event->button()==Qt::RightButton)
    {
         qDebug()<<"right";
    }
    else if(event->button()==Qt::MidButton)
    {
         qDebug()<<"Mid";
    }

    qDebug()<<"press";
    qDebug()<<event->globalPos();
    qDebug()<<event->windowPos();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"release";
    qDebug()<<event->globalPos();
    qDebug()<<event->windowPos();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"Double";
    qDebug()<<event->globalPos();
    qDebug()<<event->windowPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"move";
    qDebug()<<event->globalPos();
    qDebug()<<event->windowPos();
}
