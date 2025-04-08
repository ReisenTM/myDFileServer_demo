/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include </Users/c.c/Project/QT/CloudDisk/titlewg.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    Title *Titlewg;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QWidget *loginWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *loginPasswdEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *loginUserEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *storePasswdCheck;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *regButton;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loginCommitButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QWidget *regPage;
    QGridLayout *gridLayout_4;
    QWidget *regWidget;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_7;
    QWidget *widget9;
    QGridLayout *gridLayout_3;
    QLineEdit *reg_phoneLine;
    QLineEdit *reg_passLine_confirm;
    QLineEdit *reg_passLine;
    QLineEdit *reg_nickLine;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_8;
    QLineEdit *reg_emailLine;
    QLineEdit *reg_userLine;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *regCommitButton;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *verticalSpacer_3;
    QWidget *setPage;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QWidget *setWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget_8;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *setPortEdit;
    QLineEdit *setAddrEdit;
    QLabel *label_6;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_13;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(640, 490);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Titlewg = new Title(Login);
        Titlewg->setObjectName("Titlewg");

        verticalLayout->addWidget(Titlewg);

        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(640, 480));
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        horizontalLayout_4 = new QHBoxLayout(loginPage);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_6 = new QSpacerItem(19, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        loginWidget = new QWidget(loginPage);
        loginWidget->setObjectName("loginWidget");
        verticalLayout_2 = new QVBoxLayout(loginWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget_5 = new QWidget(loginWidget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget_5);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label);


        verticalLayout_2->addWidget(widget_5);

        widget_2 = new QWidget(loginWidget);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        loginPasswdEdit = new QLineEdit(widget_2);
        loginPasswdEdit->setObjectName("loginPasswdEdit");

        gridLayout->addWidget(loginPasswdEdit, 1, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        loginUserEdit = new QLineEdit(widget_2);
        loginUserEdit->setObjectName("loginUserEdit");

        gridLayout->addWidget(loginUserEdit, 0, 1, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(loginWidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(33, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        storePasswdCheck = new QCheckBox(widget_3);
        storePasswdCheck->setObjectName("storePasswdCheck");

        horizontalLayout_2->addWidget(storePasswdCheck);

        horizontalSpacer_4 = new QSpacerItem(32, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        regButton = new QPushButton(widget_3);
        regButton->setObjectName("regButton");
        regButton->setFlat(true);

        horizontalLayout_2->addWidget(regButton);

        horizontalSpacer_5 = new QSpacerItem(33, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(loginWidget);
        widget_4->setObjectName("widget_4");
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(137, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        loginCommitButton = new QPushButton(widget_4);
        loginCommitButton->setObjectName("loginCommitButton");

        horizontalLayout->addWidget(loginCommitButton);

        horizontalSpacer = new QSpacerItem(137, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(loginWidget);

        horizontalSpacer_7 = new QSpacerItem(19, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(loginPage);
        regPage = new QWidget();
        regPage->setObjectName("regPage");
        gridLayout_4 = new QGridLayout(regPage);
        gridLayout_4->setObjectName("gridLayout_4");
        regWidget = new QWidget(regPage);
        regWidget->setObjectName("regWidget");
        verticalLayout_4 = new QVBoxLayout(regWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        label_7 = new QLabel(regWidget);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        widget9 = new QWidget(regWidget);
        widget9->setObjectName("widget9");
        widget9->setBaseSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(widget9);
        gridLayout_3->setObjectName("gridLayout_3");
        reg_phoneLine = new QLineEdit(widget9);
        reg_phoneLine->setObjectName("reg_phoneLine");

        gridLayout_3->addWidget(reg_phoneLine, 5, 1, 1, 1);

        reg_passLine_confirm = new QLineEdit(widget9);
        reg_passLine_confirm->setObjectName("reg_passLine_confirm");

        gridLayout_3->addWidget(reg_passLine_confirm, 3, 1, 1, 1);

        reg_passLine = new QLineEdit(widget9);
        reg_passLine->setObjectName("reg_passLine");

        gridLayout_3->addWidget(reg_passLine, 2, 1, 1, 1);

        reg_nickLine = new QLineEdit(widget9);
        reg_nickLine->setObjectName("reg_nickLine");

        gridLayout_3->addWidget(reg_nickLine, 1, 1, 1, 1);

        label_10 = new QLabel(widget9);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_13 = new QLabel(widget9);
        label_13->setObjectName("label_13");

        gridLayout_3->addWidget(label_13, 5, 0, 1, 1);

        label_11 = new QLabel(widget9);
        label_11->setObjectName("label_11");

        gridLayout_3->addWidget(label_11, 3, 0, 1, 1);

        label_9 = new QLabel(widget9);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        label_12 = new QLabel(widget9);
        label_12->setObjectName("label_12");

        gridLayout_3->addWidget(label_12, 4, 0, 1, 1);

        label_8 = new QLabel(widget9);
        label_8->setObjectName("label_8");

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        reg_emailLine = new QLineEdit(widget9);
        reg_emailLine->setObjectName("reg_emailLine");

        gridLayout_3->addWidget(reg_emailLine, 4, 1, 1, 1);

        reg_userLine = new QLineEdit(widget9);
        reg_userLine->setObjectName("reg_userLine");

        gridLayout_3->addWidget(reg_userLine, 0, 1, 1, 1);


        verticalLayout_4->addWidget(widget9);

        widget_10 = new QWidget(regWidget);
        widget_10->setObjectName("widget_10");
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);

        regCommitButton = new QPushButton(widget_10);
        regCommitButton->setObjectName("regCommitButton");

        horizontalLayout_8->addWidget(regCommitButton);

        horizontalSpacer_14 = new QSpacerItem(15, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);


        verticalLayout_4->addWidget(widget_10);


        gridLayout_4->addWidget(regWidget, 0, 2, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_17, 0, 3, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_16, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 1, 2, 1, 1);

        stackedWidget->addWidget(regPage);
        setPage = new QWidget();
        setPage->setObjectName("setPage");
        horizontalLayout_7 = new QHBoxLayout(setPage);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_12 = new QSpacerItem(197, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        setWidget = new QWidget(setPage);
        setWidget->setObjectName("setWidget");
        verticalLayout_3 = new QVBoxLayout(setWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget = new QWidget(setWidget);
        widget->setObjectName("widget");
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);


        verticalLayout_3->addWidget(widget);

        widget_8 = new QWidget(setWidget);
        widget_8->setObjectName("widget_8");
        gridLayout_2 = new QGridLayout(widget_8);
        gridLayout_2->setObjectName("gridLayout_2");
        label_5 = new QLabel(widget_8);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        setPortEdit = new QLineEdit(widget_8);
        setPortEdit->setObjectName("setPortEdit");

        gridLayout_2->addWidget(setPortEdit, 1, 1, 1, 1);

        setAddrEdit = new QLineEdit(widget_8);
        setAddrEdit->setObjectName("setAddrEdit");

        gridLayout_2->addWidget(setAddrEdit, 0, 1, 1, 1);

        label_6 = new QLabel(widget_8);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);


        verticalLayout_3->addWidget(widget_8);

        widget_7 = new QWidget(setWidget);
        widget_7->setObjectName("widget_7");
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_8 = new QSpacerItem(229, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        pushButton_3 = new QPushButton(widget_7);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_5->addWidget(pushButton_3);

        horizontalSpacer_9 = new QSpacerItem(229, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_3->addWidget(widget_7);


        horizontalLayout_7->addWidget(setWidget);

        horizontalSpacer_13 = new QSpacerItem(196, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        stackedWidget->addWidget(setPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\345\270\225\351\262\201\344\272\221\347\233\230", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        storePasswdCheck->setText(QCoreApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        regButton->setText(QCoreApplication::translate("Login", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\214\351\251\254\344\270\212\346\263\250\345\206\214", nullptr));
        loginCommitButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label_7->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_10->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        label_13->setText(QCoreApplication::translate("Login", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        label_11->setText(QCoreApplication::translate("Login", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_9->setText(QCoreApplication::translate("Login", "\346\230\265\347\247\260", nullptr));
        label_12->setText(QCoreApplication::translate("Login", "\351\202\256\347\256\261", nullptr));
        label_8->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        regCommitButton->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
