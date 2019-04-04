#include "videoplayer.h"

VideoPlayer::VideoPlayer()
{
      initAvcodec();
      pFormatCtx = NULL;
      eventloop = NULL;
      //curState = StoppedState;
      curType = NoneType;
}

void VideoPlayer::initAvcodec()//函数初始化
{
    av_register_all();//初始化ffmpeg库，注册一些带有封装协议的解码器
    avcodec_register_all();//注册编解码器
    avdevice_register_all();//对设备进行注册

}

void VideoPlayer::run()
{
    eventloop=new QEventLoop;
    QTimer playtimer;//控制播放的定时器
    connect(&playtimer,SIGNAL(timeout()),this,SLOT(readPacket()),Qt::DirectConnection);
    playtimer.start(45);
    eventloop->exec();  //循环进入等待，直到exec()被再次触发
    delete eventloop;
    eventloop=NULL;

}


//打开流媒体文件（本地文件）
bool VideoPlayer::openVideo(char *filename)
{
    unsigned int i;
    videoStream=-1;

    //打开流媒体文件（本地文件）
    if(avformat_open_input(&pFormatCtx,filename,NULL,NULL)!=0)
    {
        fprintf(stderr,"Coulden't open file\n");
                return false;
    }


    //查找文件的流信息
    if(avformat_find_stream_info(pFormatCtx,NULL)<0)
    {
        fprintf(stderr,"Coulden't find stream information\n");
                return false;
    }
    //遍历文件的流，找到第一个视频流，并记录流的编码信息
    for(i=0;i<pFormatCtx->nb_streams;i++)
    {
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoStream=i;
            break;
        }

    }




    if(videoStream==-1)
    {
        closeVideo();
        fprintf(stderr,"Didn't find a video stream \n");
        return false;
    }

    if(videoStream!=-1)
    {
        //得到视频流编码的上下文指针
        pCodecCtx=pFormatCtx->streams[videoStream]->codec;



        //查找FFmpeg的解码器，函数的参数是一个解码器的id,返回查找到的解码器
        AVCodec *pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
        if(pCodec==NULL)
        {
            fprintf(stderr,"Unsupport codec \n");
            return false;
        }


        //打开解码器
        if(avcodec_open2(pCodecCtx,pCodec,NULL)<0)
        {
            fprintf(stderr,"Could not open audio codec \n");
            return false;
        }
        curType=VideoType;
    }

       return true;
}


//设置播放文件
void VideoPlayer::setSource(QString str)
{
    //stop();
    char ch[1024];
    strcpy(ch,(const char*)str.toLocal8Bit());
    if(openVideo(ch))
    {
        //GetFrameCount();

        //获得一帧视频的压缩数据
        av_read_frame(pFormatCtx,&nextPacket);
        //av_seek_frame(pFormatCtx,-1,pFormatCtx->streams[videoStream]->start_time,0);
        if(curType==VideoType)
        {
            width=pCodecCtx->width;
            height=pCodecCtx->height;
            pix_fmt=pCodecCtx->pix_fmt;
            //根据像素格式和视频分辨率获得picture存储的大小
            int numBytes=av_image_get_buffer_size(AV_PIX_FMT_RGB24,pCodecCtx->width,
                                                  pCodecCtx->height,1);
            bufferRGB=(uint8_t*)av_malloc(numBytes*sizeof(uint8_t));
        }
    }
    else
    {
        qDebug("open %s error\n",ch);
    }


}

//解码并转换为RGB
void VideoPlayer::readPacket()
{

    if(pFormatCtx==NULL) return;
    packet=nextPacket;
    int frameFinished=0;
    //分配一个帧指针，指向解码后的原始帧
    pFrame=av_frame_alloc();
    //解码该帧
    avcodec_decode_video2(pCodecCtx,pFrame,&frameFinished,&packet);
    //分配一个帧指针，指向存放转换成rgb后的帧
    pFrameRGB=av_frame_alloc();
    //给pFrameRGB帧附加上分配的内存
    av_image_fill_arrays(pFrameRGB->data,pFrameRGB->linesize,bufferRGB,AV_PIX_FMT_RGB24,
                         pCodecCtx->width,pCodecCtx->height,1);
    SwsContext *convert_ctx=sws_getContext(width,height,pix_fmt,width,height,
                                           AV_PIX_FMT_RGB24,SWS_X,NULL,NULL,NULL);
    sws_scale(convert_ctx,(const uint8_t* const*)pFrame->data,pFrame->linesize,
              0,height,pFrameRGB->data,pFrameRGB->linesize);

    QImage tmpImage((uchar*)bufferRGB,width,height,QImage::Format_RGB888);
    QImage image=tmpImage.copy();

    //发送信号
    emit readOneframe(image);
    //emit saveframe(image);

    av_free(pFrameRGB);
    av_free(pFrame);
    sws_freeContext(convert_ctx);
    av_packet_unref(&packet);

    //判断整个视频文件是否读取完毕
    if(av_read_frame(pFormatCtx,&nextPacket)<0)
    {
        //整个视频读取完毕
        stop();
    }
}

//关闭视频
void VideoPlayer::closeVideo()
{
    if(pFormatCtx!=NULL)
    {
        avformat_close_input(&pFormatCtx);
    }
    av_frame_free(&pFrameRGB);
    av_frame_free(&pFrame);
    pFormatCtx=NULL;
    curType=NoneType;

}

void VideoPlayer::stop()
{
    exit();

}

void VideoPlayer::GetFrameCount()
{
   while(av_read_frame(pFormatCtx,&nextPacket)>=0)
   {
       if(nextPacket.stream_index==videoStream)
       {
           m_nFrameCount++;
       }
       av_free_packet(&nextPacket);

   }
   av_seek_frame(pFormatCtx,videoStream,0,0);

}
