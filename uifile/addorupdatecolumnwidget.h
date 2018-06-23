#ifndef ADDORUPDATECOLUMNWIDGET_H
#define ADDORUPDATECOLUMNWIDGET_H

#include <QWidget>

namespace Ui {
class addorUpdateColumnWidget;
}

class addorUpdateColumnWidget : public QWidget
{
    Q_OBJECT

public:
    explicit addorUpdateColumnWidget(QWidget *parent = 0);
    ~addorUpdateColumnWidget();

private:
    Ui::addorUpdateColumnWidget *ui;
};

#endif // ADDORUPDATECOLUMNWIDGET_H
