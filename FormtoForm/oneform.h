#ifndef ONEFORM_H
#define ONEFORM_H

#include <QMainWindow>
#include "twoform.h"


namespace Ui {
class OneForm;
}

class OneForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit OneForm(QWidget *parent = nullptr);
    ~OneForm();

    void init ();

private slots:
    void onClickButton();
    void onshowsecond();

private:
    Ui::OneForm *ui;
    TwoForm *twoform;
};

#endif // ONEFORM_H
