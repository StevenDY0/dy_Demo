#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QWidget>
#include <QMenu>
#include "uifile/syssetwidget.h"
#include "uifile/infotablewidget.h"
#include "uifile/dataentrywidget.h"
#include "uifile/infoquerywidget.h"
#include "uifile/dataexportwidget.h"

namespace Ui {
class DBManager;
}

class DBManager : public QWidget
{
    Q_OBJECT

public:
    explicit DBManager(QWidget *parent = 0);
    ~DBManager();

private:
    Ui::DBManager *ui;
    bool max;
    QRect location;
    QMenu *menuStyle;  //样式菜单
    QList<QToolButton *> btnsConfig;

private slots:
    void initForm();
    void buttonClick();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void change_style();
    void initLeftConfig();

public:
    SysSetWidget* m_syssetWidget;
    InfoTableWidget* m_infotableWidget;
    DataEntryWidget* m_dataentryWidget;
    InfoQueryWidget* m_infoqueryWidget;
    DataExportWidget* m_dataexportWidget;
};

#endif // DBMANAGER_H
