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

    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveASFileSlot();
    void printFileSlot();

    void setFontSLot();
    void setColorSlot();
    void setCurrenttime();

private:
    Ui::MainWindow *ui;
    QString saveFileName;
};

#endif // MAINWINDOW_H
