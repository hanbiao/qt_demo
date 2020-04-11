#-------------------------------------------------
#
# Project created by QtCreator 2020-04-09T21:52:24
#
#-------------------------------------------------
#表示项目中加入core gui模块 -- 用于GUI设计的类库模块
QT       += core gui

#加入widgets模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 1): QT += serialport

TARGET = demo_proj
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
