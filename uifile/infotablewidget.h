#ifndef INFOTABLEWIDGET_H
#define INFOTABLEWIDGET_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class InfoTableWidget;
}

class InfoTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoTableWidget(QWidget *parent = 0);
    ~InfoTableWidget();

private slots:
    void initForm();
    void on_pushButton_colAdd_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::InfoTableWidget *ui;
private:
    QStandardItemModel *model;
};

#endif // INFOTABLEWIDGET_H
