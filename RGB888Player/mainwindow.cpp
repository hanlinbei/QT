#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mThread=new TransCodeThread;
    connect(mThread,SIGNAL(sig_GetOneFrame(QImage)),this,SLOT(slotGetOneFrame(QImage)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)), this, SLOT(mSetText(int)));
    connect(ui->pushButton_open,SIGNAL(clicked()),this,SLOT(slotBtnClicked()));
    connect(ui->pushButton_display,SIGNAL(clicked()),this,SLOT(slotBtnClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::black);
    QRect rect=ui->widget_video->geometry();
    painter.drawRect(rect);
    if(mImage.size().width()<=0) return;
    //将图像按比例缩放成和窗口一样大小
    QImage img=mImage.scaled(ui->widget_video->size(),Qt::KeepAspectRatio);
    int x=ui->widget_video->width()-img.width();
    int y=ui->widget_video->height()-img.height();
    x/=2;
    y/=2;
    x+=ui->widget_video->x();
    y+=ui->widget_video->y();
    painter.drawImage(QPoint(x,y),img);//画出图像

}


void MainWindow::slotGetOneFrame(QImage img)
{
    mImage=img;
    update();//调用update将执行paintEvent函数
    ui->horizontalSlider->setValue(countFrame);
        countFrame++;
}


void MainWindow::slotBtnClicked()
{
    int width=ui->lineEdit_weight->text().toInt();
    int height=ui->lineEdit_height->text().toInt();
    if(QObject::sender()==ui->pushButton_open)
    {

        QString s=QFileDialog::getOpenFileName(this,"选择RGB文件","C:/Users/hanlinbei/Videos","rgb文件(*.*);;");
        if(!s.isEmpty())
        {
            s.replace("/","\\\\");
            ui->lineEdit_filepath->setText(s);



        }
    }
        else if(QObject::sender()==ui->pushButton_display)
        {
            QString filePath=ui->lineEdit_filepath->text();           
            mThread->startPlay(filePath,width,height);
            mThread->getFileSize(filePath);
            ui->horizontalSlider->setMaximum(mThread->numFrame);
            countFrame = 1;
        }




}


void MainWindow::mSetText(int value)
{

    ui->currentFrame->setText(QString::number(value));



}


/*
* 获取窗体fps的值
*/
void MainWindow::on_fpsBox_currentIndexChanged(int index)
{
    if(index==0)
    {
       mThread->Setfps_25();
    }
    if(index==1)
    {
       mThread->Setfps_30();
    }
}








void MainWindow::on_horizontalSlider_sliderPressed()
{
    mThread->isPressSlider = true;
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    mThread->currentFrame = ui->horizontalSlider->value();
    mThread->isPressSlider = false;
    countFrame = ui->horizontalSlider->value();

}


