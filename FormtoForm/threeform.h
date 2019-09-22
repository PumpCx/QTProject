#ifndef THREEFORM_H
#define THREEFORM_H

#include <QWidget>

namespace Ui {
class ThreeForm;
}

class ThreeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ThreeForm(QWidget *parent = nullptr);
    ~ThreeForm();

private slots:
   // void onShowfirst();
    void onShowsecond();

signals:
       void  onshowoherwidget();

private:
    Ui::ThreeForm *ui;
};

#endif // THREEFORM_H
