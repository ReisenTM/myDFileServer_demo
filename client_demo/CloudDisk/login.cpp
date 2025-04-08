#include "login.h"
#include "myRegexp.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    //设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    //设置自己为title的父窗口
    ui->Titlewg->setMyParent(this);
    //设置默认为login界面
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    //处理title里发出的按键信号
    connect(ui->Titlewg,&Title::showMinWindow,this,[this](){
       //最小化
        this->showMinimized();
    });
    connect(ui->Titlewg,&Title::showSetWindow,this,[this](){
        ui->stackedWidget->setCurrentWidget(ui->setPage);

    });
    connect(ui->Titlewg,&Title::closeWindow,this,[this](){
        //如果不是登录页面，返回到登录页面
        if(ui->stackedWidget->currentWidget()!=ui->loginPage){
            ui->stackedWidget->setCurrentWidget(ui->loginPage);
        }else
        {
            //如果是登录界面，关闭
            this->close();
        }

    });
    //没有账号，跳转到注册界面
    connect(ui->regButton,&QPushButton::clicked,this,[this](){
        ui->stackedWidget->setCurrentWidget(ui->regPage);
    });

    //导入样式表
    QFile file("/Users/c.c/Project/QT/CloudDisk/mytest.qss");
    file.open(QFile::ReadOnly);
    QByteArray all=file.readAll();
    qApp->setStyleSheet(all);
}

Login::~Login()
{
    delete ui;
}

//不需要手动调用，满足条件会自动调用，只需要写好实现
void Login::paintEvent(QPaintEvent *event)
{
    //给当前窗口画背景图
    // QPainter p(this);//参数：要画到哪
    // QPixmap bg(":/images/login_bk.jpg");
    // p.drawPixmap(0,0,this->width(),this->height(),bg);
}

//按下注册提交键的响应
void Login::on_regCommitButton_clicked()
{
    //1.获取输入内容
    QString userName=ui->reg_userLine->text();
    QString nickName=ui->reg_nickLine->text();
    QString passwd=ui->reg_passLine->text();
    QString confirmPasswd=ui->reg_passLine_confirm->text();
    QString email=ui->reg_emailLine->text();
    QString phoneNum=ui->reg_phoneLine->text();
    //2.对输入的内容进行数据校验
    QRegularExpression regexp;
    regexp.setPattern(USERNAME_REG);
    bool isMatched = regexp.match(userName).hasMatch();
    if(isMatched == false)
    {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确!");
        ui->reg_userLine->clear();
        return;
    }
    if(passwd!=confirmPasswd)
    {
        QMessageBox::warning(this,"ERROR","两次密码输入不一致");
        ui->reg_passLine->clear();
        ui->reg_passLine_confirm->clear();
        return;
    }
    //3.用户信息发送给服务器
    // - 如何发送：使用http协议,使用post方式
    // - 数据格式：json格式
    QNetworkAccessManager * pManager=new QNetworkAccessManager(this);
    QNetworkRequest request;
    //3.1 从用户服务器设置输入框里读取服务器地址
    QString inputURL=ui->setAddrEdit->text()+":"+ui->setPortEdit->text();
    QUrl url=QString("http://%1/reg").arg(inputURL);//匿名对象格式匹配初始化
#ifdef _DEBUG_
    qDebug()<<"Seting page`s Input url :"<<url;
#endif
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    //将用户提交的数据拼接成json对象字符串
    QJsonObject regJsonObj;
    regJsonObj.insert("username",userName);//做了隐式转换 原本应该先：QJsonValue(username)
    regJsonObj.insert("passwd",passwd);
    regJsonObj.insert("nickname",nickName);
    regJsonObj.insert("email",email);
    regJsonObj.insert("phonenum",phoneNum);
    QJsonDocument doc(regJsonObj);
    QNetworkReply * reply=pManager->post(request,doc.toJson());
    //4.接受服务器返回的响应数据
    connect(reply,&QNetworkReply::readyRead,this,[=](){
    //5.对服务器响应进行分析处理
        //5.1接受数据  ->> {"code","002"}
        QByteArray rcvData=reply->readAll();
        //将数据转为JsonDocument
        QJsonDocument rcvJsonDoc=QJsonDocument::fromJson(rcvData);
        if(rcvJsonDoc.isEmpty())
        {
            qDebug()<<"服务器返回的数据为空";
            return;  // 退出 lambda
        }
        QJsonObject rcvObj=rcvJsonDoc.object();
        //5.2 需要知道服务器发送的响应的格式来进行解析
        //5.3判断成功/失败，给用户反馈
        //通过返回的键值取出状态码
        //成功："002"
        QString rcvCode=rcvObj.value("code").toString();
        if(rcvCode==CORRECT_STAT)//如果成功
        {
            QMessageBox::information(this,"成功","用户成功注册");
            return;
        }else if(rcvCode==EXISTED_STAT)//如果已经注册过
        {
            QMessageBox::warning(this,"NOTICE","该用户已经注册过");
            return;
        }else//如果错误
        {
            QString errOutput="错误码: "+rcvCode;
            QMessageBox::warning(this,"ERROR",errOutput);
            return;
        }

    });


}

//按下登录提交键的响应
void Login::on_loginCommitButton_clicked()
{
    //收到信号-》发送json报表给web服务器
    //1.读取输入框内的内容
    QString userName=ui->loginUserEdit->text();
    QString passwd=ui->loginPasswdEdit->text();
    //2.数据校验
    QRegularExpression regexp;
    regexp.setPattern(USERNAME_REG);
    if(!regexp.match(userName).hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确!");
        ui->loginUserEdit->clear();
        return;
    }
    regexp.setPattern(PASS_REG);
    if(!regexp.match(passwd).hasMatch())
    {
        QMessageBox::warning(this, "ERROR", "密码格式不正确!");
        ui->loginPasswdEdit->clear();
        return;
    }
    //3.获取服务器地址
    QString inputURL=ui->setAddrEdit->text()+":"+ui->setPortEdit->text();
    QUrl url=QString("https://%1/login").arg(inputURL);
    //4.把数据组织成json格式
    QNetworkAccessManager* pManager=new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QJsonObject snd_obj;
    snd_obj.insert("username",userName);
    snd_obj.insert("passwd",passwd);

    //5.将数据通过post请求给服务器
    QJsonDocument doc(snd_obj);
    //debug
    qDebug()<<"服务器信息"<<url;
    qDebug()<<"客户端登录信息:"<<doc;
    QNetworkReply* reply=pManager->post(request,doc.toJson());
    //6.接受服务器返回的数据,判断成功/失败
    //成功 "002" 密码错误 "003" 用户不存在"004"
    connect(reply,&QNetworkReply::readyRead,this,[=](){
        QByteArray rcv_data=reply->readAll();
        QJsonDocument doc=QJsonDocument::fromJson(rcv_data);
        QJsonObject rcv_obj=doc.object();
        QString status_code=rcv_obj.value("code").toString();
        if(status_code=="002")
        {
            QMessageBox::warning(this,"NOTICE","登录成功");
            this->close();
            MainWindow* newWindow=new MainWindow();
            newWindow->setAttribute(Qt::WA_DeleteOnClose); // 关键设置
            newWindow->show();
            return;
        }else if(status_code=="003")
        {
            QMessageBox::warning(this,"ERROR","密码错误");
            return;
        }else if(status_code=="004")
        {
            QMessageBox::warning(this,"ERROR","用户不存在");
            return;
        }else
        {
            QMessageBox::warning(this,"ERROR","登录失败");
            return;
        }
    });

}

