#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

//找到窗口，并将目标窗口设置到最前面
void Widget::FindAndFocus(){
    QString title = ui->htmlWinTitle->text();
    if(title.isEmpty()){
        qDebug() <<"没有找到窗口";
        return;
    }
    qDebug() << "找到窗口";
    LPCWSTR  str = (LPCWSTR)title.toUtf8().data();
    m_hWnd = FindWindow(NULL,str);
    SetForegroundWindow(m_hWnd);
}
Widget::~Widget()
{
    delete ui;
}
//模拟键盘
void Widget::on_btn1_clicked()
{
    FindAndFocus();
    Sleep(1000);
    //按键模拟函数，模拟F5 3次
    keybd_event(VK_F5,0,0,0);
    Sleep(1000);
    keybd_event(VK_F5,0,0,0);
    Sleep(1000);
    keybd_event(VK_F5,0,0,0);
}
/*
 * 模拟鼠标
 * 先找到窗口，移动鼠标到窗口内，模拟 右键按下，模拟 L键 进行刷新
 * 用的2345浏览器，不知道其他浏览器的按键是好多
 */
void Widget::on_btn2_clicked()
{
    FindAndFocus();
    //得到窗口坐标
    POINT pt = {0};
    ClientToScreen(m_hWnd,&pt);
    //设置鼠标位置
    SetCursorPos(pt.x + 50,pt.y+400);
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    Sleep(100);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
    Sleep(1000);
    //弹出右键菜单，L快捷键刷新，L 的ASCII 76。
    keybd_event(76,0,0,0);
}
