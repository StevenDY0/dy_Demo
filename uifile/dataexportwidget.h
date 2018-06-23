#ifndef DATAEXPORTWIDGET_H
#define DATAEXPORTWIDGET_H

#include <QWidget>

namespace Ui {
class DataExportWidget;
}

class DataExportWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataExportWidget(QWidget *parent = 0);
    ~DataExportWidget();

private:
    Ui::DataExportWidget *ui;
};

#endif // DATAEXPORTWIDGET_H
