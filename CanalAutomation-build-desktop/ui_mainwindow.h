/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jan 3 17:46:06 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Next_pushButton;
    QPushButton *Exit_pushButton;
    QFrame *Frame_1;
    QRadioButton *Single_radio;
    QRadioButton *Multi_radio;
    QFrame *Frame_2;
    QSpinBox *No_pool_spinbox;
    QLabel *No_pool_label;
    QFrame *Frame_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 400);
        MainWindow->setMinimumSize(QSize(800, 400));
        MainWindow->setMaximumSize(QSize(800, 400));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Next_pushButton = new QPushButton(centralWidget);
        Next_pushButton->setObjectName(QString::fromUtf8("Next_pushButton"));
        Next_pushButton->setGeometry(QRect(480, 240, 87, 27));
        Next_pushButton->setMinimumSize(QSize(87, 27));
        Next_pushButton->setMaximumSize(QSize(87, 27));
        Next_pushButton->setAutoDefault(true);
        Next_pushButton->setDefault(false);
        Next_pushButton->setFlat(false);
        Exit_pushButton = new QPushButton(centralWidget);
        Exit_pushButton->setObjectName(QString::fromUtf8("Exit_pushButton"));
        Exit_pushButton->setGeometry(QRect(610, 240, 87, 27));
        Exit_pushButton->setMinimumSize(QSize(87, 27));
        Exit_pushButton->setMaximumSize(QSize(87, 27));
        Exit_pushButton->setFocusPolicy(Qt::StrongFocus);
        Exit_pushButton->setCheckable(false);
        Exit_pushButton->setChecked(false);
        Exit_pushButton->setAutoDefault(true);
        Exit_pushButton->setDefault(false);
        Frame_1 = new QFrame(centralWidget);
        Frame_1->setObjectName(QString::fromUtf8("Frame_1"));
        Frame_1->setGeometry(QRect(210, 160, 151, 121));
        Frame_1->setFrameShape(QFrame::NoFrame);
        Frame_1->setFrameShadow(QFrame::Raised);
        Single_radio = new QRadioButton(Frame_1);
        Single_radio->setObjectName(QString::fromUtf8("Single_radio"));
        Single_radio->setGeometry(QRect(20, 30, 101, 21));
        Single_radio->setChecked(true);
        Multi_radio = new QRadioButton(Frame_1);
        Multi_radio->setObjectName(QString::fromUtf8("Multi_radio"));
        Multi_radio->setGeometry(QRect(20, 60, 101, 21));
        Frame_2 = new QFrame(centralWidget);
        Frame_2->setObjectName(QString::fromUtf8("Frame_2"));
        Frame_2->setGeometry(QRect(151, 52, 471, 81));
        Frame_2->setFrameShape(QFrame::NoFrame);
        Frame_2->setFrameShadow(QFrame::Raised);
        No_pool_spinbox = new QSpinBox(Frame_2);
        No_pool_spinbox->setObjectName(QString::fromUtf8("No_pool_spinbox"));
        No_pool_spinbox->setGeometry(QRect(210, 40, 51, 26));
        No_pool_spinbox->setMinimum(1);
        No_pool_spinbox->setMaximum(200);
        No_pool_label = new QLabel(Frame_2);
        No_pool_label->setObjectName(QString::fromUtf8("No_pool_label"));
        No_pool_label->setGeometry(QRect(200, 5, 71, 21));
        Frame_3 = new QFrame(centralWidget);
        Frame_3->setObjectName(QString::fromUtf8("Frame_3"));
        Frame_3->setEnabled(true);
        Frame_3->setGeometry(QRect(120, 150, 511, 80));
        Frame_3->setFrameShape(QFrame::NoFrame);
        Frame_3->setFrameShadow(QFrame::Raised);
        Frame_3->setLineWidth(1);
        pushButton = new QPushButton(Frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 85, 27));
        pushButton_2 = new QPushButton(Frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 20, 85, 27));
        pushButton_3 = new QPushButton(Frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 20, 85, 27));
        pushButton_4 = new QPushButton(Frame_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 20, 85, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Canal Automation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        Next_pushButton->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        Exit_pushButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        Single_radio->setText(QApplication::translate("MainWindow", "Single Pool", 0, QApplication::UnicodeUTF8));
        Multi_radio->setText(QApplication::translate("MainWindow", "Multi Pool", 0, QApplication::UnicodeUTF8));
        No_pool_label->setText(QApplication::translate("MainWindow", "No.of pools", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Editor", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Calculation", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Gate values", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
