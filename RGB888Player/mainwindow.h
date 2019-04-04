#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Qpainter>
#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QPoint>
#include <QImage>
#include "TransCodeThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    TransCodeThread *mThread;
    void paintEvent(QPaintEvent *event);

     int countFrame;

private slots:
    void slotGetOneFrame(QImage);
    void slotBtnClicked();
    void on_fpsBox_currentIndexChanged(int index);
    void slotGetSlider(int i);
    void mSetText(int);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QImage mImage;

};

#endif // MAINWINDOW_H
