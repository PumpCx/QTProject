#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onClickStartbutton();
    void onClickEndbutton();

private slots:
    void processtar();
    void init();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int num =0;

};

#endif // MAINWINDOW_H
