#include "syssetwidget.h"
#include "ui_syssetwidget.h"
#include "helper/myhelper.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>

SysSetWidget::SysSetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysSetWidget)
{
    ui->setupUi(this);

    ui->lineEdit_dbName->setText("database.db");
    ui->lineEdit_user->setText(tr("root"));
    ui->lineEdit_pwd->setText(tr("123456"));
    ui->lineEdit_pwd->setEchoMode(QLineEdit::Password);

    QStringList drivers = QSqlDatabase::drivers();
         foreach(QString driver, drivers)  //列出Qt5所有支持的数据库类型
              qDebug() << "\t" << driver;

}

SysSetWidget::~SysSetWidget()
{
    delete ui;
}

void SysSetWidget::on_btnDBConn_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    qDebug()<<"QSQLITE driver?"<<database.isValid();
    QString filePath=QApplication::applicationDirPath()+"/database.db";
    qDebug()<<filePath;
    database.setDatabaseName("database.db");
    database.setUserName(ui->lineEdit_user->text());
    database.setPassword(ui->lineEdit_pwd->text());

    //打开数据库
    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
    }

    QMessageBox::critical(0, tr("提示"), tr("open db success!"), QMessageBox::Cancel);
}
