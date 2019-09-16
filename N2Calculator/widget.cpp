#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

   /* QHBoxLayout *vlayout = new QHBoxLayout (this);

    QPushButton *button  = new QPushButton ();
    button->setText("计算");

    QLabel * label1 = new QLabel ();
    label1->setText("+");
    QLabel * label2 = new QLabel ();
    label2->setText("=");

    QLineEdit *firstnum = new QLineEdit ();
    QLineEdit *result = new QLineEdit();
    vlayout->addWidget(firstnum);
    vlayout->addWidget(label1);
    QLineEdit *secondnum = new QLineEdit();
    vlayout->addWidget(secondnum);
    vlayout->addWidget(label2);
    vlayout->addWidget(result);
    vlayout->addWidget(button);*/

}
void Widget::OnClickbutton()
{

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->close();
}

void Widget::on_pushButton_2_clicked()
{
    QString userid = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if(userid=="522169305"&&password=="123456789")
    {
        QMessageBox::information(this,"Info","登陆成功");
        this->close();
    }
    else
        {
            QMessageBox::information(this,"Info","登陆失败！");
            this->close();
        }

}
