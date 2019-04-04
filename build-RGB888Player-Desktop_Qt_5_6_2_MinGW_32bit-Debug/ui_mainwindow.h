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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *widget_video;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *weightlabel;
    QLineEdit *lineEdit_weight;
    QLabel *hightlabel;
    QLineEdit *lineEdit_height;
    QPushButton *pushButton_display;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *fpslabel;
    QComboBox *fpsBox;
    QLabel *filelabel;
    QLineEdit *lineEdit_filepath;
    QPushButton *pushButton_open;
    QSlider *horizontalSlider;
    QLabel *currentFrame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(548, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget_video = new QWidget(centralWidget);
        widget_video->setObjectName(QStringLiteral("widget_video"));
        widget_video->setGeometry(QRect(20, 10, 521, 261));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 350, 391, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        weightlabel = new QLabel(layoutWidget);
        weightlabel->setObjectName(QStringLiteral("weightlabel"));

        horizontalLayout->addWidget(weightlabel);

        lineEdit_weight = new QLineEdit(layoutWidget);
        lineEdit_weight->setObjectName(QStringLiteral("lineEdit_weight"));

        horizontalLayout->addWidget(lineEdit_weight);

        hightlabel = new QLabel(layoutWidget);
        hightlabel->setObjectName(QStringLiteral("hightlabel"));

        horizontalLayout->addWidget(hightlabel);

        lineEdit_height = new QLineEdit(layoutWidget);
        lineEdit_height->setObjectName(QStringLiteral("lineEdit_height"));

        horizontalLayout->addWidget(lineEdit_height);

        pushButton_display = new QPushButton(layoutWidget);
        pushButton_display->setObjectName(QStringLiteral("pushButton_display"));

        horizontalLayout->addWidget(pushButton_display);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 310, 338, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fpslabel = new QLabel(layoutWidget1);
        fpslabel->setObjectName(QStringLiteral("fpslabel"));

        horizontalLayout_2->addWidget(fpslabel);

        fpsBox = new QComboBox(layoutWidget1);
        fpsBox->setObjectName(QStringLiteral("fpsBox"));

        horizontalLayout_2->addWidget(fpsBox);

        filelabel = new QLabel(layoutWidget1);
        filelabel->setObjectName(QStringLiteral("filelabel"));

        horizontalLayout_2->addWidget(filelabel);

        lineEdit_filepath = new QLineEdit(layoutWidget1);
        lineEdit_filepath->setObjectName(QStringLiteral("lineEdit_filepath"));

        horizontalLayout_2->addWidget(lineEdit_filepath);

        pushButton_open = new QPushButton(layoutWidget1);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));

        horizontalLayout_2->addWidget(pushButton_open);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 280, 511, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        currentFrame = new QLabel(centralWidget);
        currentFrame->setObjectName(QStringLiteral("currentFrame"));
        currentFrame->setGeometry(QRect(480, 310, 54, 12));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        widget_video->raise();
        horizontalSlider->raise();
        currentFrame->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 548, 23));
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
        weightlabel->setText(QApplication::translate("MainWindow", "\345\256\275", 0));
        lineEdit_weight->setText(QApplication::translate("MainWindow", "800", 0));
        hightlabel->setText(QApplication::translate("MainWindow", "\351\253\230", 0));
        lineEdit_height->setText(QApplication::translate("MainWindow", "400", 0));
        pushButton_display->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276", 0));
        fpslabel->setText(QApplication::translate("MainWindow", "\345\270\247\347\216\207", 0));
        fpsBox->clear();
        fpsBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "25fps", 0)
         << QApplication::translate("MainWindow", "30fps", 0)
        );
        filelabel->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        pushButton_open->setText(QApplication::translate("MainWindow", "...", 0));
        currentFrame->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
