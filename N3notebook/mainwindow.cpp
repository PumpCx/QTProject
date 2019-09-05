#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("notepad");
    QObject::connect(ui->action_N,&QAction::triggered,this,&MainWindow::newFileSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFileSlot()
{
    if(ui->textEdit->document()->isModified())
    {
        qDebug()<<"current file modified";
    }
    else
    {
        qDebug()<<"not modified";
    }
}
