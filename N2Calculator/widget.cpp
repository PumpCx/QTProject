#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout *vlayout = new QHBoxLayout (this);

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
    vlayout->addWidget(button);

}
void Widget::OnClickbutton()
{

}

Widget::~Widget()
{
    delete ui;
}
