#include "threeform.h"
#include "ui_threeform.h"

ThreeForm::ThreeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreeForm)
{
    ui->setupUi(this);
   /* oneform = new OneForm();
    connect(ui->pushButton,&QPushButton::clicked,this,&ThreeForm::onShowfirst);*/
    connect(ui->pushButton2,&QPushButton::clicked,this,&ThreeForm::onShowsecond);

}

ThreeForm::~ThreeForm()
{
    delete ui;
}

/*void ThreeForm::onShowfirst()
{
   oneform->show();
   this->hide();

}*/

void ThreeForm::onShowsecond()
{
    emit onshowoherwidget();
}
