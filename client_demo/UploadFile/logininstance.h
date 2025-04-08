#ifndef LOGININSTANCE_H
#define LOGININSTANCE_H
//单例对象
#include <QtCore/qobject.h>
class loginInstance
{
public:
    static loginInstance* getInstance();
    void setUserName(QString name);
    QString getUserName();
private:
    loginInstance();
    loginInstance(const loginInstance& instance);
    static loginInstance m_login;
    //保存数据
    QString m_userName;
    QString m_passwd;
    QString m_ip;
    QString m_port;
    QString m_token;

};

#endif // LOGININSTANCE_H
