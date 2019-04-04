#-------------------------------------------------
#
# Project created by QtCreator 2019-04-02T16:29:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = H264
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videoplayer.cpp

HEADERS  += mainwindow.h \
    videoplayer.h

FORMS    += mainwindow.ui

INCLUDEPATH +=E:/QT/H264/ffmpeg/include


LIBS +=E:/QT/H264/ffmpeg/lib/avcodec.lib \
       E:/QT/H264/ffmpeg/lib/avdevice.lib \
       E:/QT/H264/ffmpeg/lib/avfilter.lib \
       E:/QT/H264/ffmpeg/lib/avformat.lib \
       E:/QT/H264/ffmpeg/lib/avutil.lib \
       E:/QT/H264/ffmpeg/lib/postproc.lib \
       E:/QT/H264/ffmpeg/lib/swresample.lib \
       E:/QT/H264/ffmpeg/lib/swscale.lib \

