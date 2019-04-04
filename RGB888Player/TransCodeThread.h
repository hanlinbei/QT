#ifndef TRANSCODETHREAD_H
#define TRANSCODETHREAD_H
#include <QString>
#include <QThread>
#include <QTime>
#include <QImage>
#include <QDebug>
#include<QWidget>
#include <iostream>
#include <windows.h>
#include <QFileInfo>
typedef unsigned char BYTE;
class TransCodeThread:public QThread
{
    Q_OBJECT
public:
     TransCodeThread();
     void startPlay(QString infile,int width,int height);
     void run();
     void Setfps_25();
     void Setfps_30();
     void Yuv420p2Rgb32(const BYTE *yuvBuffer_in,const BYTE *rgbBuffer_out,int width,int height);
     void getFileSize(QString mFilePath);
     bool UTF8ToUnicode(const char* UTF8, wchar_t* strUnicode);
     bool isPressSlider=false;
     int numFrame = 0;      //用于寻找下一帧位置
     int currentFrame = 0;

signals:
     void sig_GetOneFrame(QImage);
     void sig_GetSlider(int i);

private:
     QString mFilePath;
     int mWidth;
     int mHeight;
     QTime time;
     int fps=25;


};

#endif // TRANSCODETHREAD_H
