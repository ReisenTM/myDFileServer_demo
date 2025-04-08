#ifndef LOGININFOINSTANCE_H
#define LOGININFOINSTANCE_H

#include <QtCore/qobject.h>
class LoginInfoInstance
{
public:
    void setLoginInfo(QString name,QString pass,QString ad,QString port);

private:
    LoginInfoInstance();
    LoginInfoInstance(const LoginInfoInstance& t);
    //编译器只知道 count 存在于 MyClass，但它不会为 count 分配存储空间。需要在 .cpp 文件中提供一个定义
    static LoginInfoInstance m_instance;
    //登录属性
    QString user;
    QString passwd;
    QString addr;
    QString port;

};

#endif // LOGININFOINSTANCE_H
