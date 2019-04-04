#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(SendSignal(char)),this,SLOT(MySendSignal(char)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_todayBtn_clicked()
{
    emit SendSignal(1);
}

void MainWindow::on_nextMonthBtn_clicked()
{
    emit SendSignal(2);
}

void MainWindow::MySendSignal(char i)
{
    if(i==1)
    {
        ui->calendarWidget->showToday();
    }
    else if(i==2)
    {
        ui->calendarWidget->showNextMonth();
    }


}
