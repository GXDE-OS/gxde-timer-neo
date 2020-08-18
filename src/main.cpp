#include <DApplication>
#include <QDesktopWidget>
#include <DWidgetUtil>  //Dtk::Widget::moveToCenter(&w); 要调用它，就得引用DWidgetUtil
#include <widget.h>
#include <QTranslator>

DWIDGET_USE_NAMESPACE
int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();  //让bar处在标题栏中
    DApplication a(argc, argv);
    //加载翻译文件
    QTranslator translator;
    translator.load(a.applicationDirPath()+"/translations/one-tomato_" + QLocale::system().name());
     a.setAttribute(Qt::AA_UseHighDpiPixmaps);
     a.loadTranslator();
     a.setOrganizationName("deepin");
     a.setApplicationVersion(DApplication::buildVersion("1.0.3"));
     a.setApplicationAcknowledgementPage("https://blog.yzzi.top");
     a.setProductIcon(QIcon(":/icon/icon/top.yzzi.tomato.svg"));  //设置Logo
     a.setProductName(QObject::tr("OneTomato"));
     a.setApplicationName(QObject::tr("OneTomato")); //只有在这儿修改窗口标题才有效
     a.setApplicationDescription(QObject::tr("Thanks to Deepin community @gbwater for help"));

    Widget w;
    QDesktopWidget *s=DApplication::desktop();
    w.show();

    //让打开时界面显示在正中
    Dtk::Widget::moveToCenter(&w);


    return a.exec();
}
