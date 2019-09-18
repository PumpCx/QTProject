#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置按钮图标；
    ui->toolButton->setIcon(QIcon());
   // ui->toolButton->setAutoRaise(true);
    ui->toolButton->setIconSize(QSize(100,100));

    QMenu *menu =new QMenu(this);
    menu->addAction("Open");
    menu->addAction("close");
    menu->addAction(QIcon(),"关闭",this,"");

    ui->toolButton->setMenu(menu);

}

MainWindow::~MainWindow()
{
    delete ui;
}
