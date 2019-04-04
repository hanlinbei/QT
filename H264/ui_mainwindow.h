/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QSlider *horizontalSlider;
    QLabel *curTime;
    QLabel *totalTime;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *filePath;
    QPushButton *openFileBtn;
    QLabel *label2;
    QLineEdit *width;
    QLabel *lable3;
    QLineEdit *height;
    QPushButton *displayBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(479, 408);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 431, 231));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 240, 431, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        curTime = new QLabel(centralWidget);
        curTime->setObjectName(QStringLiteral("curTime"));
        curTime->setGeometry(QRect(100, 260, 54, 12));
        totalTime = new QLabel(centralWidget);
        totalTime->setObjectName(QStringLiteral("totalTime"));
        totalTime->setGeometry(QRect(390, 260, 54, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 260, 91, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 260, 54, 12));
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 290, 427, 54));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        filePath = new QLineEdit(widget1);
        filePath->setObjectName(QStringLiteral("filePath"));

        gridLayout->addWidget(filePath, 0, 1, 1, 3);

        openFileBtn = new QPushButton(widget1);
        openFileBtn->setObjectName(QStringLiteral("openFileBtn"));

        gridLayout->addWidget(openFileBtn, 0, 4, 1, 1);

        label2 = new QLabel(widget1);
        label2->setObjectName(QStringLiteral("label2"));

        gridLayout->addWidget(label2, 1, 0, 1, 1);

        width = new QLineEdit(widget1);
        width->setObjectName(QStringLiteral("width"));

        gridLayout->addWidget(width, 1, 1, 1, 1);

        lable3 = new QLabel(widget1);
        lable3->setObjectName(QStringLiteral("lable3"));

        gridLayout->addWidget(lable3, 1, 2, 1, 1);

        height = new QLineEdit(widget1);
        height->setObjectName(QStringLiteral("height"));

        gridLayout->addWidget(height, 1, 3, 1, 1);

        displayBtn = new QPushButton(widget1);
        displayBtn->setObjectName(QStringLiteral("displayBtn"));

        gridLayout->addWidget(displayBtn, 1, 4, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        curTime->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        totalTime->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\247\206\351\242\221\346\227\266\351\227\264", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\200\273\345\270\247\346\225\260", 0));
        label->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\357\274\232", 0));
        openFileBtn->setText(QApplication::translate("MainWindow", "...", 0));
        label2->setText(QApplication::translate("MainWindow", "\345\256\275\345\272\246", 0));
        width->setText(QApplication::translate("MainWindow", "1920", 0));
        lable3->setText(QApplication::translate("MainWindow", "\351\253\230\345\272\246", 0));
        height->setText(QApplication::translate("MainWindow", "1080", 0));
        displayBtn->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
