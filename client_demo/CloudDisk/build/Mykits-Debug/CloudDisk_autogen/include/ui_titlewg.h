/********************************************************************************
** Form generated from reading UI file 'titlewg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEWG_H
#define UI_TITLEWG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Titlewg
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QPushButton *min;
    QPushButton *setting;

    void setupUi(QWidget *Titlewg)
    {
        if (Titlewg->objectName().isEmpty())
            Titlewg->setObjectName("Titlewg");
        Titlewg->resize(641, 79);
        horizontalLayout = new QHBoxLayout(Titlewg);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(12, 5, 0, -1);
        logo = new QLabel(Titlewg);
        logo->setObjectName("logo");
        logo->setMinimumSize(QSize(40, 40));
        logo->setMaximumSize(QSize(16777215, 16777215));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.ico")));
        logo->setScaledContents(true);

        horizontalLayout->addWidget(logo);

        title = new QLabel(Titlewg);
        title->setObjectName("title");
        QFont font;
        font.setFamilies({QString::fromUtf8("HanziPen SC")});
        font.setBold(true);
        title->setFont(font);

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(343, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close = new QPushButton(Titlewg);
        close->setObjectName("close");
        close->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        close->setMouseTracking(false);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        close->setIcon(icon);
        close->setIconSize(QSize(25, 25));
        close->setFlat(true);

        horizontalLayout->addWidget(close);

        min = new QPushButton(Titlewg);
        min->setObjectName("min");
        min->setMouseTracking(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/title_min.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        min->setIcon(icon1);
        min->setIconSize(QSize(25, 25));
        min->setFlat(true);

        horizontalLayout->addWidget(min);

        setting = new QPushButton(Titlewg);
        setting->setObjectName("setting");
        setting->setMouseTracking(false);
        setting->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/config.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        setting->setIcon(icon2);
        setting->setIconSize(QSize(25, 25));
        setting->setCheckable(false);
        setting->setAutoRepeat(false);
        setting->setAutoExclusive(false);
        setting->setFlat(true);

        horizontalLayout->addWidget(setting);


        retranslateUi(Titlewg);

        QMetaObject::connectSlotsByName(Titlewg);
    } // setupUi

    void retranslateUi(QWidget *Titlewg)
    {
        Titlewg->setWindowTitle(QCoreApplication::translate("Titlewg", "Form", nullptr));
        logo->setText(QString());
        title->setText(QCoreApplication::translate("Titlewg", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\270\225\351\262\201\344\272\221\347\233\230</span></p></body></html>", nullptr));
        close->setText(QString());
        min->setText(QString());
        setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Titlewg: public Ui_Titlewg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEWG_H
