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
    a.loadTranslator();
    //translator.load(a.applicationDirPath()+"/translations/gxde-timer_" + QLocale::system().name());
     a.setAttribute(Qt::AA_UseHighDpiPixmaps);
     a.loadTranslator();
     a.setOrganizationName("GXDE");
     a.setApplicationVersion(DApplication::buildVersion("1.2.3"));
     a.setApplicationAcknowledgementPage("https://gitee.com/GXDE-OS/gxde-timer-neo");
     a.setProductIcon(QIcon::fromTheme("gxde-timer"));  //设置Logo
     a.setProductName(QObject::tr("GXDE Timer"));
     a.setApplicationName(QObject::tr("GXDE Timer")); //只有在这儿修改窗口标题才有效
     a.setApplicationDescription(QObject::tr("Thanks to Deepin community @gbwater for help"));

    Widget w;
    QDesktopWidget *s=DApplication::desktop();
    w.show();

    //让打开时界面显示在正中
    Dtk::Widget::moveToCenter(&w);


    return a.exec();
}
