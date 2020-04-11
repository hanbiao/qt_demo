#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //创建应用程序
    MainWindow w; //创建窗口
    w.show(); //显示窗口

    return a.exec(); //启动应用程序运行，开始处理事件
}
