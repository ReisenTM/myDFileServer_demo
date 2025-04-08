#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPainter>
#include <QRegularExpression>
#include <QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include "logininfoinstance.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

protected:
    //绘图事件函数
    void paintEvent(QPaintEvent *event);
private slots:
    void on_regCommitButton_clicked();
    void on_loginCommitButton_clicked();
private:
    Ui::Login *ui;

};

#endif // LOGIN_H
