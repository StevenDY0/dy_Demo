#include "dataentrywidget.h"
#include "ui_dataentrywidget.h"

DataEntryWidget::DataEntryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataEntryWidget)
{
    ui->setupUi(this);
}

DataEntryWidget::~DataEntryWidget()
{
    delete ui;
}
