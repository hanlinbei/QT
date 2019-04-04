#include "TransCodeThread.h"

typedef unsigned char BYTE;

typedef struct RGB32 {
  BYTE    rgbBlue;      // 蓝色分量
  BYTE    rgbGreen;     // 绿色分量
  BYTE    rgbRed;       // 红色分量
  BYTE    rgbReserved;  // 保留字节（用作Alpha通道或忽略）
} RGB32;

TransCodeThread::TransCodeThread()
{

}

void TransCodeThread::startPlay(QString infile,int width,int height)
{
    mFilePath=infile;
    mWidth=width;
    mHeight=height;
    isPressSlider = false;
    start();

}

void TransCodeThread::run()
{
    time.start();
        wchar_t  filePath[1024]={0};
        UTF8ToUnicode(mFilePath.toUtf8(), filePath);
        FILE *fp_rgb = _wfopen(filePath, L"rb");
        //char filePath[1024]={0};
        //strcpy(filePath,mFilePath.toUtf8().data());

        //FILE *fp_rgb=fopen(filePath,"rb");


        int width = mWidth;
        int height = mHeight;
        if (fp_rgb == NULL) return;

        int rgbSize = width * height * sizeof(RGB32);
        int yuvSize = width * height * 3 /2;

        BYTE *rgbBuffer = (BYTE *)malloc(rgbSize);
        BYTE *yuvBuffer = (BYTE *)malloc(yuvSize);
        for(int i=0;;i++)
        {
            if(isPressSlider)
            {
                fseek(fp_rgb, width * height * 3 / 2 * currentFrame, 0);
                continue;
            }
            if (feof(fp_rgb))
                break;
            int readedsize = fread(yuvBuffer,1,yuvSize,fp_rgb);
            Yuv420p2Rgb32(yuvBuffer,rgbBuffer,width,height);
            QImage tmpImg((uchar *)rgbBuffer,width,height,QImage::Format_RGB32);
            QImage image = tmpImg.copy(); //把图像复制一份 传递给界面显示
            if(fps == 25)
            {
                msleep(20);
            }
            else if(fps == 30)
            {
                msleep(10);
            }
            emit sig_GetOneFrame(image);  //发送信号
            int time_Diff = time.elapsed();//消逝的时间
            float f = time_Diff/1000.0;//秒转换为毫秒
            float TotalTime = 0 ;
            TotalTime += f;//播放的总时间
            QString TT = QString("%1").arg(TotalTime);
            qDebug() << TT;
        }
}

void TransCodeThread::Setfps_25()
{
    fps=25;
}

void TransCodeThread::Setfps_30()
{
    fps=30;
}

bool TransCodeThread::UTF8ToUnicode(const char* UTF8, wchar_t* strUnicode)
{
    DWORD dwUnicodeLen;    //转换后Unicode的长度
    TCHAR *pwText;      //保存Unicode的指针
    // wchar_t* strUnicode;    //返回值
    //获得转换后的长度，并分配内存
    dwUnicodeLen = MultiByteToWideChar(CP_UTF8,0,UTF8,-1,NULL,0);
    pwText = new TCHAR[dwUnicodeLen];
    if(!pwText)
    {
        return false;
    }
    //转为Unicode
     MultiByteToWideChar(CP_UTF8,0,UTF8,-1,pwText,dwUnicodeLen);
    //转为CString
     wcscpy(strUnicode, pwText);
    //清除内存
     delete[]pwText;
    return true;
}

void TransCodeThread::Yuv420p2Rgb32(const BYTE *yuvBuffer_in,const BYTE *rgbBuffer_out,int width,int height)
{
    BYTE *yuvBuffer = (BYTE *)yuvBuffer_in;
    RGB32 *rgb32Buffer = (RGB32 *)rgbBuffer_out;

    for (int y = 0; y < height; y++)
    {

        for (int x = 0; x < width; x++)
        {
            int index = y * width + x;

            int indexY = y * width + x;
            int indexU = width * height + y / 2 * width / 2 + x / 2;
            int indexV = width * height + width * height / 4 + y / 2 * width / 2 + x / 2;

            BYTE Y = yuvBuffer[indexY];
            BYTE U = yuvBuffer[indexU];
            BYTE V = yuvBuffer[indexV];

            RGB32 *rgbNode = &rgb32Buffer[index];

            ///这转换的公式 百度有好多 下面这个效果相对好一些

            rgbNode->rgbRed = Y + 1.402 * (V-128);
            rgbNode->rgbGreen = Y - 0.34413 * (U-128) - 0.71414*(V-128);
            rgbNode->rgbBlue = Y + 1.772*(U-128);
        }
    }
}

void TransCodeThread::getFileSize(QString mFilePath)
{
    QFileInfo minfo(mFilePath);

    numFrame = (int)(minfo.size()/mWidth/mHeight/3*2);
    qDebug() << "视频帧数：" << numFrame;
}







