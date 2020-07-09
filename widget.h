#ifndef WIDGET_H
#define WIDGET_H

#include <dswitchbutton.h>
#include <QWidget>
DWIDGET_USE_NAMESPACE

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void onSBtnSwitchButtonCheckedChanged(bool);


private:
    Ui::Widget *ui;
    DSwitchButton * switchbutton;
};

#endif // WIDGET_H
