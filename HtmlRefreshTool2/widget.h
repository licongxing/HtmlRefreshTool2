#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Windows.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:

public slots:

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

private:
    Ui::Widget *ui;
    HWND m_hWnd;
private:
    void FindAndFocus();

};

#endif // WIDGET_H
