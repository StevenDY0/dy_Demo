#include "infotablewidget.h"
#include "ui_infotablewidget.h"

InfoTableWidget::InfoTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoTableWidget)
{
    ui->setupUi(this);

    this->initForm();
    ui->comboBox_Type->addItem(tr("INTEGER"));
    ui->comboBox_Type->addItem(tr("TEXT"));
}

InfoTableWidget::~InfoTableWidget()
{
    delete ui;
}

void InfoTableWidget::initForm()
{
//    ui->tableWidget->clear();
//    //ui->tableWidget->setStyleSheet("QHeaderView::section{background-color:rgb(52, 73, 94)}");
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableWidget->setColumnCount(4);
//    ui->tableWidget->setRowCount(0);
//    QStringList headers;
//    headers<<tr("name")<<tr("数据类型")<<tr("主键唯一")<<tr("不为空");
//    ui->tableWidget->setHorizontalHeaderLabels(headers);

    //最后一列自动填充
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    //奇数偶数行不同背景色
    ui->tableView->setAlternatingRowColors(true);
    //选中整行,每次只允许选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    model = new QStandardItemModel;
    model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(tr("数据类型")));
    model->setHorizontalHeaderItem(2, new QStandardItem(tr("主键唯一")));
    model->setHorizontalHeaderItem(3, new QStandardItem(tr("是否有子列")));
    ui->tableView->setModel(model);
    //ui->tableMain->verticalHeader()->hide();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//bu neng bian ji
}

void InfoTableWidget::on_pushButton_colAdd_clicked()
{
    /*ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    int Index=ui->tableWidget->rowCount()-1;

    //ui->tableWidget->setRowCount(Index);

    QTableWidgetItem *itemName = new QTableWidgetItem("");
    QTableWidgetItem *itemType = new QTableWidgetItem("");
    QTableWidgetItem *primaryKey = new QTableWidgetItem("");
    QTableWidgetItem *notNull = new QTableWidgetItem("");
    ui->tableWidget->setItem(Index,0,itemName );
    ui->tableWidget->setItem(Index,1,itemPath );
    ui->tableWidget->setItem(Index,2,para );
    ui->tableWidget->setItem(Index,3,titleName );*/

    int index=model->rowCount();
    QString temp=tr("是");
    if(ui->checkBox_IsPrimaryKey->isChecked()==false)
        temp=tr("否");
    QString temp2=tr("有子列");
    if(ui->checkBox_IsChildCol->isChecked()==false)
        temp2=tr("");
    model->setItem(index, 0, new QStandardItem(ui->lineEdit_ColumnName->text()));
    model->setItem(index, 1, new QStandardItem(ui->comboBox_Type->currentText()));
    model->setItem(index, 2, new QStandardItem(temp));
    model->setItem(index, 3, new QStandardItem(temp2));
}

void InfoTableWidget::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_ColumnName->text()!= "" && ui->lineEdit_TableName->text()!="")
    {
        //QString sqlStr="CREATE TABLE test ( id INTEGER PRIMARY KEY UNIQUE,name TEXT NOT NULL,parentid INTEGER);";
        //QString sqlStr=QString("CREATE TABLE %1 ( id INTEGER PRIMARY KEY UNIQUE,name TEXT NOT NULL,parentid INTEGER);");
    }
}
