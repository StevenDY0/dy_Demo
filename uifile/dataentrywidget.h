#ifndef DATAENTRYWIDGET_H
#define DATAENTRYWIDGET_H

#include <QWidget>

namespace Ui {
class DataEntryWidget;
}

class DataEntryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataEntryWidget(QWidget *parent = 0);
    ~DataEntryWidget();

private:
    Ui::DataEntryWidget *ui;
};

#endif // DATAENTRYWIDGET_H
