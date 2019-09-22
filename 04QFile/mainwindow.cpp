#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#define MSG_length 1024
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

void MainWindow::on_openButton_clicked()
{
   QString filename = QFileDialog::getOpenFileName(this,"hello world","../..",
                                 "HEADERS(*.h);;SOURCES(*.cpp)");

   if(filename.isEmpty())
   {
       QMessageBox::warning(this,"Waring","file is empty");
       return;
   }
   file->setFileName(filename);
   bool succ = file->open(QIODevice::ReadOnly|QIODevice::Text);
   if(!succ)
   {
       QMessageBox::warning(this,"Error","Open file error");
       return  ;
   }
   // QFile 操作yi
   /*
    * ////////////
   while (!file->atEnd()) {

       QByteArray ba = file->read(MSG_length);
       QString str= QString(ba);
       ui->textEdit->append(str);
   }  */


   /////2//////
  /* char buf [MSG_length+1] = {0};
   while (!file->atEnd()) {
       memset(buf,0,MSG_length);
       QString str= QString(buf);
       ui->textEdit->append(str);
   } */
      QByteArray ba = file->readAll();
      QString str =QString (ba);
      ui->textEdit->append(str);

   /////////////
   //TextStream
      QTextStream  text(file);
      while(file->atEnd())
      {
          QString str =text.readAll();
          ui->textEdit->append(str);
      }
   file->close();

}

void MainWindow::init()
{
      file = new QFile(this);
}

void MainWindow::on_saveButton_clicked()
{
   QString filename =  QFileDialog::getSaveFileName(this,"Save","../..","Text(*.txt);;Image(*.igp,*.png)");

    if(filename.isEmpty())
    {
        QMessageBox::warning(this,"Save Error","Save file fail !");
        return;
    }
    file->setFileName(filename);



}
