#include "dataexportwidget.h"
#include "ui_dataexportwidget.h"

DataExportWidget::DataExportWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataExportWidget)
{
    ui->setupUi(this);
}

DataExportWidget::~DataExportWidget()
{
    delete ui;
}
