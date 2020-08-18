#ifndef TABBUTTON_H
#define TABBUTTON_H

#include <QWidget>
#include <DPushButton>
#include <DGuiApplicationHelper>


DWIDGET_USE_NAMESPACE
class TabButton : public QWidget
{
    Q_OBJECT
public:
    explicit TabButton(QWidget *parent = nullptr);
    void setText(QString btn1,QString btn2);
    void setIndex(int index_t);
    int index;
signals:
    void indexChange(int index);
private:

    DPushButton *m_btn1=new DPushButton;
    DPushButton *m_btn2=new DPushButton;

    QColor maincolor;
    QColor bgcolor;
public slots:
};

#endif // TABBUTTON_H
