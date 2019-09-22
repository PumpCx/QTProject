#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();

private slots:
    void on_openButton_clicked();

private:
    Ui::MainWindow *ui;
    QFile *file;
};

#endif // MAINWINDOW_H
