#ifndef TWOFORM_H
#define TWOFORM_H

#include <QWidget>
#include "threeform.h"

namespace Ui {
class TwoForm;
}

class TwoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TwoForm(QWidget *parent = nullptr);
    ~TwoForm();

private slots:
    void clickthreewindow();
    void clickonewindow();
    void onShowmyself();


signals:
    void clicksignale();

private:
    Ui::TwoForm *ui;
    ThreeForm *threeform;
};

#endif // TWOFORM_H
