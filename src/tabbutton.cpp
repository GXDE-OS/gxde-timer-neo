#include "tabbutton.h"
#include <QHBoxLayout>
#include <DGuiApplicationHelper>

TabButton::TabButton(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(m_btn1);
    layout->addWidget(m_btn2);
    layout->addStretch();
    layout->setAlignment(Qt::AlignCenter);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);
    m_btn1->setText(tr("番茄钟"));
    m_btn2->setText(tr("统计"));
    m_btn1->setFixedSize(110,28);
    m_btn2->setFixedSize(110,28);

    setIndex(0);
    connect(Dtk::Gui::DGuiApplicationHelper::instance(),&Dtk::Gui::DGuiApplicationHelper::themeTypeChanged,[=](){
        maincolor=Dtk::Gui::DGuiApplicationHelper::instance()->applicationPalette().highlight().color();
        if(!(Dtk::Gui::DGuiApplicationHelper::instance()->themeType()==Dtk::Gui::DGuiApplicationHelper::DarkType)){
            bgcolor="#E5E5E5";
        }else {
            bgcolor="#444444";
        }
        TabButton::setIndex(index);

    });

    connect(m_btn1,&QPushButton::clicked,[=](){TabButton::setIndex(0);});
    connect(m_btn2,&QPushButton::clicked,[=](){TabButton::setIndex(1);});


}

void TabButton::setIndex(int index_t)
{
    index=index_t;
    if(index==0){
        m_btn2->setStyleSheet("background-color:"+bgcolor.name()+";border:0px;border-top-right-radius:12px;border-bottom-right-radius:12px");
        m_btn1->setStyleSheet("background-color:"+maincolor.name()+";border:0px;border-top-left-radius:12px;border-bottom-left-radius:12px;color:#FFFFFF");
        emit indexChange(0);
    }else {
        m_btn1->setStyleSheet("background-color:"+bgcolor.name()+";border:0px;border-top-left-radius:12px;border-bottom-left-radius:12px");
        m_btn2->setStyleSheet("background-color:"+maincolor.name()+";border:0px;border-top-right-radius:12px;border-bottom-right-radius:12px;color:#FFFFFF");
        emit indexChange(1);
    }

}
