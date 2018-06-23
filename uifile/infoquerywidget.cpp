#include "infoquerywidget.h"
#include "ui_infoquerywidget.h"

InfoQueryWidget::InfoQueryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoQueryWidget)
{
    ui->setupUi(this);
}

InfoQueryWidget::~InfoQueryWidget()
{
    delete ui;
}
