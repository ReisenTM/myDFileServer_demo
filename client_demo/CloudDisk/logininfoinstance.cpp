#include "logininfoinstance.h"
LoginInfoInstance LoginInfoInstance::m_instance;
void LoginInfoInstance::setLoginInfo(QString name, QString pass, QString ad, QString port)
{
    this->user=name;
    this->addr=ad;
    this->port=port;
    this->passwd=pass;
}

LoginInfoInstance::LoginInfoInstance() {}
