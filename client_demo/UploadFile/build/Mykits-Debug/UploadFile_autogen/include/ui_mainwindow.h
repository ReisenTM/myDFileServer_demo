/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *file_lineEdit;
    QPushButton *file_choseBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *file_logText;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QProgressBar *file_uploadProcess;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *file_uploadBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(613, 445);
        MainWindow->setMaximumSize(QSize(1240, 640));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        file_lineEdit = new QLineEdit(widget1);
        file_lineEdit->setObjectName("file_lineEdit");

        horizontalLayout_2->addWidget(file_lineEdit);

        file_choseBtn = new QPushButton(widget1);
        file_choseBtn->setObjectName("file_choseBtn");

        horizontalLayout_2->addWidget(file_choseBtn);


        verticalLayout->addWidget(widget1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        file_logText = new QTextEdit(widget_2);
        file_logText->setObjectName("file_logText");

        horizontalLayout_3->addWidget(file_logText);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(565, 60));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        file_uploadProcess = new QProgressBar(widget_3);
        file_uploadProcess->setObjectName("file_uploadProcess");
        file_uploadProcess->setValue(24);

        horizontalLayout_5->addWidget(file_uploadProcess);


        verticalLayout->addWidget(widget_3);

        widget2 = new QWidget(widget);
        widget2->setObjectName("widget2");
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        file_uploadBtn = new QPushButton(widget2);
        file_uploadBtn->setObjectName("file_uploadBtn");

        horizontalLayout->addWidget(file_uploadBtn);


        verticalLayout->addWidget(widget2);


        horizontalLayout_4->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        file_choseBtn->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        file_uploadBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
