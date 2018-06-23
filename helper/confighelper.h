#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H

class QString;

class configHelper
{
public:
    static QString AppPath;                 //应用程序路径
    static int DeskWidth;                   //桌面可用宽度
    static int DeskHeight;                  //桌面可用高度

    static QString AppTitle;                //界面标题
    static QString AppStyle;                //界面样式

    static void ReadConfig();               //读取配置文件
    static void WriteConfig();              //写入配置文件

};

#endif // CONFIGHELPER_H
