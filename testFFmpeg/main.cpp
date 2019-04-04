#include <iostream>

using namespace std;

extern "C"
{
#include<libswscale/swscale.h>
#include<libavcodec/avcodec.h>
#include<libavformat/avformat.h>
#include<libavdevice/avdevice.h>
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    av_register_all();
    unsigned version=avcodec_version();
    cout<<"version is "<<version;
    return 0;
}
