#include "logininstance.h"
loginInstance loginInstance::m_login;
loginInstance *loginInstance::getInstance()
{
    return &m_login;
}

void loginInstance::setUserName(QString name)
{
    this->m_userName=name;
}
QString loginInstance::getUserName()
{
    return this->m_userName;
}
loginInstance::loginInstance() {};

