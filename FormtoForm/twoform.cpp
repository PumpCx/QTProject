#include "twoform.h"
#include "ui_twoform.h"

TwoForm::TwoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoForm)
{
    ui->setupUi(this);
    threeform = new ThreeForm();
    connect(ui->pushButton,&QPushButton::clicked,this,&TwoForm::clickonewindow);
    connect(ui->pushButton2,&QPushButton::clicked,this
            ,&TwoForm::clickthreewindow);

    connect(threeform,&ThreeForm::onshowoherwidget,this,&TwoForm::onShowmyself);



}

TwoForm::~TwoForm()
{
    delete ui;
}

void TwoForm::clickonewindow()
{
    emit clicksignale();
}

void TwoForm::clickthreewindow()
{
    threeform->show();
    this->hide();

}

void TwoForm::onShowmyself()
{
    this->show();
    threeform->hide();
}
