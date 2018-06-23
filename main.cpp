#include "dbmanager.h"
#include <QApplication>
#include <QDir>
#include <QTextCodec>
#include <QTranslator>
#include "helper/appinit.h"
#include "helper/confighelper.h"
#include "helper/myhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif

    QDir::setCurrent(QApplication::applicationDirPath());

    //加载样式表
    myHelper::SetStyle(configHelper::AppStyle);

    QTranslator translator(&a);
    if (translator.load(":/other/skin/other/qt_zh_CN.qm", ":"))
    {
        a.installTranslator(&translator);
    }

    a.setWindowIcon(QIcon(":/images/skin/images/zx_logo.ico"));
    a.setFont(QFont("Microsoft YaHei", 9));
    AppInit::Instance()->start();
    DBManager w;

    w.show();

    return a.exec();
}
