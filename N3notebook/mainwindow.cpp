#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("notepad");
    QObject::connect(ui->action_N,&QAction::triggered,this,&MainWindow::newFileSlot);
    QObject::connect(ui->action_O,&QAction::triggered,this,&MainWindow::openFileSlot);
    QObject::connect(ui->action_S,&QAction::triggered,this,&MainWindow::saveFileSlot);
    QObject::connect(ui->action_2,&QAction::triggered,this,&MainWindow::close);
    QObject::connect(ui->color,&QAction::triggered,this,&MainWindow::setColorSlot);
    QObject::connect(ui->font,&QAction::triggered,this,&MainWindow::setFontSLot);
QObject::connect(ui->action_D,&QAction::triggered,this,&MainWindow::setCurrenttime);
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

void MainWindow::openFileSlot()
{
    QString filename = QFileDialog::getOpenFileName(this,"openfile",QDir::currentPath());
    if(filename.isEmpty() )
    {
        QMessageBox::information(this,"Error Message","Please Seletor a Test file");
        return ;
    }
    else {
        QFile *file = new QFile();
        file->setFileName("fileName");
        bool ok =file->open(QIODevice::ReadOnly);
        if(ok)
        {
            QTextStream in (file);
            ui->textEdit->setText(in.readAll());
            file->close();
            delete  file;
        }
        else {

            QMessageBox::information(this,"Message Error","File open Error"+file->errorString());
            return;

        }
    }
}

void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())
    {
        this->saveASFileSlot();
    }
    else {

        QFile *file =new QFile;
        file->setFileName(saveFileName);
        bool ok =file->open(QIODevice::WriteOnly);
        if(ok)
        {
            QTextStream out (file);
            out<<ui->textEdit->toPlainText();
            file->close();
            delete  file;

        }
    }

}

void MainWindow::saveASFileSlot()
{
    QString saveFileName = QFileDialog::getSaveFileName(this,"Save name",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Please seletor a Test file");
        return ;
    }

    QFile *file =new QFile;
    file->setFileName(saveFileName);
    bool ok =file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out (file);
        out<<ui->textEdit->toPlainText();
        file->close();
        delete  file;

    }
    else {
        QMessageBox::information(this,"Message Error","save file error");
        return ;

    }

}

void MainWindow::printFileSlot()
{


}

void MainWindow::setFontSLot()
{
    //  get uesr choose/selected font


    /* bool ok;
    QFont font = QFontDialog::getFont(
                    &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        // the user clicked OK and font is set to the font the user selected
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
    }*/

    bool ok;
    QFont font = QFontDialog::getFont(
                &ok,QFont("HElvetica[Cronyx]",10),this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else {
        QMessageBox::information(this,"Error Message","set Error Font");
    }

}
void MainWindow::setColorSlot()
{ 
    QColor color = QColorDialog::getColor(Qt::green,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else {

        QMessageBox::information(this,"Error Messsage","set Color Error");

    }
}

void MainWindow::setCurrenttime()
{
    QDateTime datatime = QDateTime::currentDateTime();
    QString time = datatime.toString("yyyy-MM-dd hh:mm:ss");
    ui->textEdit->setText(time);
}
