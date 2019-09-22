#include "oneform.h"
#include "ui_oneform.h"


OneForm::OneForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OneForm)
{
    ui->setupUi(this);
    init ();
    twoform = new TwoForm();   
    connect(ui->pushButton,&QPushButton::clicked,this,&OneForm::onClickButton);
    connect(twoform,&TwoForm::clicksignale,this,&OneForm::onshowsecond);
}

OneForm::~OneForm()
{
    delete ui;
}

void OneForm::init()
{

}

void OneForm::onClickButton()
{
    twoform->show();
    this->hide();
}

void OneForm::onshowsecond()
{
    this->show();
    twoform->hide();
}
