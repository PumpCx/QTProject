#include "widget.h"
#include "ui_widget.h"
#include <QProcess>
#include <QObject>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
  //  connect(ui->lineEdit,SIGNAL(returnPressed()),
                    // this,on_pushButton_clicked());
    connect(ui->lineEdit,&QLineEdit::returnPressed,
            this,&Widget::on_pushButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    /*
     *  QProcess *myProcess = new QProcess(parent);
      myProcess->start(program, arguments);
      */

    QProcess *myprocess = new QProcess(this);
    QString  myprograme = ui->lineEdit->text();
    myprocess->start(myprograme.trimmed());
    //ui->lineEdit->clear();
    //this->close();
}
