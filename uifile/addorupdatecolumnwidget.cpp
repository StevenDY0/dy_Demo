#include "addorupdatecolumnwidget.h"
#include "ui_addorupdatecolumnwidget.h"

addorUpdateColumnWidget::addorUpdateColumnWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addorUpdateColumnWidget)
{
    ui->setupUi(this);
}

addorUpdateColumnWidget::~addorUpdateColumnWidget()
{
    delete ui;
}
