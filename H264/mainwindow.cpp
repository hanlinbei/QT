#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->curTime->setText("0");
    ui->totalTime->setText("0");

    videoPlayerThread=new VideoPlayer;
    connect(videoPlayerThread,SIGNAL(readOneframe(QImage)),this,SLOT(slotgetFrame(QImage)));
    connect(ui->horizontalSlider,SIGNAL(sliderPressed()),this,SLOT(slotSliderPressed()));
    connect(ui->horizontalSlider,SIGNAL(sliderReleased()),this,SLOT(slotSliderReleased()));
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::black);
    QRect rect=ui->widget->geometry();
    painter.drawRect(rect);
    if(mImage.size().width()<=0) return;
    //将图像按比例缩放成和窗口一样大小
    QImage img=mImage.scaled(ui->widget->size(),Qt::KeepAspectRatio);
    int x=ui->widget->width()-img.width();
    int y=ui->widget->height()-img.height();
    x/=2;
    y/=2;
    x+=ui->widget->x();
    y+=ui->widget->y();
    painter.drawImage(QPoint(x,y),img);//画出图像

    //int min=videoPlayerThread->m_Duration/60;
    //int sec=videoPlayerThread->m_Duration%60;
    //char buf[1024]={0};
    //sprintf(buf,"%03d:%02d",min,sec);


}
//显示图像
void MainWindow::slotgetFrame(QImage image)
{
    //ui->m_label_show->setPixmap(QPixmap::fromImage(image).scaled(ui->m_label_show->size(),
    //Qt::KeepAspectRatio,Qt::SmoothTransformation));
    //ui->m_label_show->setScaledContents(true);
    mImage=image;
    this->update();
    ui->curTime->setText(QString::number(currentCount));
    ui->horizontalSlider->setValue(currentCount);
            currentCount++;
}

//打开文件
void MainWindow::on_openFileBtn_clicked()
{
    QString s=QFileDialog::getOpenFileName(this,"选择H264文件","C:/Users/hanlinbei/Videos","H264文件(*.*);;");
       if(!s.isEmpty())
       {
           s.replace("/","\\\\");
           ui->filePath->setText(s);
       }
}

//播放按钮
void MainWindow::on_displayBtn_clicked()
{
    QString filePath=ui->filePath->text();
    videoPlayerThread->setSource(filePath);
    //videoPlayerThread->GetTime();
    videoPlayerThread->start();
}

void MainWindow::slotSliderReleased()
{

}


void MainWindow::slotSliderPressed()
{

}
