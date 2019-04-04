#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QThread>
#include <stdio.h>
#include <QEventLoop>
#include <QTimer>
#include <QImage>
enum VideoPlayerTppe {
    NoneType = -1,
    VideoType
};

extern"C"{
#include"libswscale/swscale.h"
#include"libavcodec/avcodec.h"
#include"libavformat/avformat.h"
#include"libavdevice/avdevice.h"
#include"libavutil/opt.h"
#include"libavutil/parseutils.h"
#include"libavutil/samplefmt.h"
#include"libavutil/fifo.h"
#include"libavutil/intreadwrite.h"
#include"libavutil/dict.h"
#include"libavutil/mathematics.h"
#include"libavutil/pixdesc.h"
#include"libavutil/avstring.h"
#include"libavutil/imgutils.h"
#include"libavfilter/avfilter.h"
#include"libavutil/pixfmt.h"
}


class VideoPlayer : public QThread
{
    Q_OBJECT
public:
    VideoPlayer();
    void setSource(QString str);
    long m_nFrameCount=0;

    AVPacket pkt;
    void GetFrameCount();

signals:
    void readOneframe(QImage);
    void saveframe(QImage);

private slots:
     void readPacket();

private:
    void initAvcodec();
    AVFormatContext *pFormatCtx;
    AVFormatContext *pFormatCtx2;
    VideoPlayerTppe curType;
    //AVMediaType VideoType=1;
    QEventLoop *eventloop;
    AVCodecContext *pCodecCtx;
    AVPacket nextPacket;
    AVPacket packet;
    AVFrame * pFrame;
    AVFrame * pFrameRGB;
    AVPixelFormat pix_fmt;
    void run();
    bool openVideo(char *filename);
    void stop();
    void closeVideo();
    int videoStream;
    int width;
    int height;
    uint8_t* bufferRGB;

};

#endif // VIDEOPLAYER_H
