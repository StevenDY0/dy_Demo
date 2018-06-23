#ifndef SYSSETWIDGET_H
#define SYSSETWIDGET_H

#include <QWidget>

namespace Ui {
class SysSetWidget;
}

class SysSetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SysSetWidget(QWidget *parent = 0);
    ~SysSetWidget();

private slots:
    void on_btnDBConn_clicked();

private:
    Ui::SysSetWidget *ui;
};

#endif // SYSSETWIDGET_H
