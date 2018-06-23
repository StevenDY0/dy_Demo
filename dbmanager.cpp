#include "dbmanager.h"
#include "ui_dbmanager.h"
#include "helper/iconhelper.h"
#include "helper/confighelper.h"
#include "helper/myhelper.h"

DBManager::DBManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBManager)
{
    ui->setupUi(this);

    this->initForm();
    //this->initLeftConfig();
}

DBManager::~DBManager()
{
    delete ui;
}
void DBManager::initForm()
{
    this->max = false;
    this->location = this->geometry();
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);


    ui->widgetTitle->setProperty("form", "title");
    ui->widgetLeft->setProperty("nav", "left");
    ui->widgetMain->setProperty("form", "bottom");
    ui->labTitle->setText(tr("数据管理软件"));
    ui->labTitle->setFont(QFont("Microsoft Yahei", 18));
    this->setWindowTitle(ui->labTitle->text());

    menuStyle = new QMenu(this);
    menuStyle->addAction("蓝色", this, SLOT(change_style()));
    //menuStyle->addAction("淡蓝色", this, SLOT(change_style()));
    //menuStyle->addAction("黑色", this, SLOT(change_style()));
    menuStyle->addAction("黑色扁平", this, SLOT(change_style()));
    //menuStyle->addAction("关于", this, SLOT(OnAbout()));
    menuStyle->setStyleSheet("font: 10pt \"微软雅黑\";");
    ui->btnMenu->setMenu(menuStyle);

    //添加自定义属性,用于切换ico用
    ui->btnInfoTable->setProperty("icoName", "infotable");
    ui->btnDataEntry->setProperty("icoName", "dataentry");
    ui->btnInfoQuery->setProperty("icoName", "infoquery");
    ui->btnDataExport->setProperty("icoName", "dataexport");
    ui->btnSysSet->setProperty("icoName", "sysset");

    //widget init
    m_syssetWidget=new SysSetWidget(this);
    ui->gridLayout_SysSet->addWidget(m_syssetWidget);
    m_infotableWidget=new InfoTableWidget(this);
    ui->gridLayout_InfoTable->addWidget(m_infotableWidget);
    m_dataentryWidget=new DataEntryWidget(this);
    ui->gridLayout_DataEntry->addWidget(m_dataentryWidget);
    m_infoqueryWidget=new InfoQueryWidget(this);
    ui->gridLayout_InfoQuery->addWidget(m_infoqueryWidget);
    m_dataexportWidget=new DataExportWidget(this);
    ui->gridLayout_DataExport->addWidget(m_dataexportWidget);


    QList<QToolButton *> btns = ui->widgetLeft->findChildren<QToolButton *>();
    foreach (QToolButton *btn, btns) {
        btn->setMaximumHeight(80);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
    }
    ui->btnSysSet->clicked();
}

void DBManager::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString text = b->text();

    QList<QToolButton *> btns = ui->widgetLeft->findChildren<QToolButton *>();
    foreach (QToolButton *btn, btns) {
        QString icoName = btn->property("icoName").toString();
        if (btn != b) {
            btn->setChecked(false);
        } else {
            btn->setChecked(true);
        }
    }

    if(text == tr("新建表信息"))
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(text == tr("数据录入"))
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(text == tr("信息查询"))
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(text == tr("数据导出"))
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if(text == tr("系统设置"))
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
}


void DBManager::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void DBManager::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void DBManager::on_btnMenu_Close_clicked()
{
    close();
}
void DBManager::change_style()
{
    QAction *action = (QAction *)sender();
    QString style = action->text();
    if (style == "淡蓝色")
    {
        configHelper::AppStyle = ":/skin/qss/lightblue.css";
    }
    else if (style == "蓝色")
    {
        configHelper::AppStyle = ":/skin/qss/blue.css";
    }
    else if (style == "黑色")
    {
        configHelper::AppStyle = ":/skin/qss/psblack.css";
    }
    else if (style == "黑色扁平")
    {
        configHelper::AppStyle = ":/skin/qss/flatblack.css";
    }

    myHelper::SetStyle(configHelper::AppStyle);
    configHelper::WriteConfig();
}

void DBManager::initLeftConfig()
{
    btnsConfig << ui->btnInfoTable << ui->btnDataEntry << ui->btnInfoQuery << ui->btnDataExport << ui->btnSysSet;
    int count = btnsConfig.count();
    QSize icoSize(50,50);
    for (int i = 0; i < count; i++) {
        QString icoName = btnsConfig.at(i)->property("icoName").toString();
        btnsConfig.at(i)->setCheckable(true);
        btnsConfig.at(i)->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        btnsConfig.at(i)->setIcon(QIcon(QString(":/images/skin/images/%1.png").arg(icoName)));
        btnsConfig.at(i)->setIconSize(icoSize);

        connect(btnsConfig.at(i), SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
    }

    ui->btnSysSet->click();
}
