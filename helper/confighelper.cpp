#include "confighelper.h"
#include <QSettings>
#include "myhelper.h"

QString configHelper::AppPath = "";
int configHelper::DeskWidth = 1920;
int configHelper::DeskHeight = 1024;

QString configHelper::AppTitle = "数据管理软件";
QString configHelper::AppStyle = ":/skin/qss/flatblack.css";


//读取配置文件
void configHelper::ReadConfig()
{
    QString fileName = configHelper::AppPath + "config.ini";
    //如果配置文件不存在,则以初始值继续运行
    if (!myHelper::FileIsExist(fileName)) {
        //对应中文转成正确的编码
        configHelper::AppTitle = configHelper::AppTitle.toLatin1();
        configHelper::AppStyle = configHelper::AppStyle.toLatin1();
        return;
    }

    QSettings *set = new QSettings(fileName, QSettings::IniFormat);

    set->beginGroup("AppConfig");
    configHelper::AppTitle = set->value("AppTitle").toString();
    configHelper::AppStyle = set->value("AppStyle").toString();
    set->endGroup();
}

//写入配置文件
void configHelper::WriteConfig()
{
    QString fileName = configHelper::AppPath + "config.ini";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);

    set->beginGroup("AppConfig");
    set->setValue("AppTitle", configHelper::AppTitle);
    set->setValue("AppStyle", configHelper::AppStyle);
    set->endGroup();
}
