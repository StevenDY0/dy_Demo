#ifndef INFOQUERYWIDGET_H
#define INFOQUERYWIDGET_H

#include <QWidget>

namespace Ui {
class InfoQueryWidget;
}

class InfoQueryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoQueryWidget(QWidget *parent = 0);
    ~InfoQueryWidget();

private:
    Ui::InfoQueryWidget *ui;
};

#endif // INFOQUERYWIDGET_H
