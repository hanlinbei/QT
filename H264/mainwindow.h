#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include "videoplayer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    VideoPlayer *videoPlayerThread;
    void paintEvent(QPaintEvent *event);
    long currentCount=0;
private slots:
    void on_openFileBtn_clicked();
    void slotgetFrame(QImage image);
    void on_displayBtn_clicked();
    void slotSliderPressed();
    void slotSliderReleased();


private:
    Ui::MainWindow *ui;
    QImage mImage;


};

#endif // MAINWINDOW_H
