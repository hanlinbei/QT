#-------------------------------------------------
#
# Project created by QtCreator 2019-03-26T15:50:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RGB888Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    transcodethread.cpp

HEADERS  += mainwindow.h \
    TransCodeThread.h

FORMS    += mainwindow.ui
