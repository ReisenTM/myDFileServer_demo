#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QHttpPart>
#include <QtNetwork/QHttpMultiPart>
#include <QFileInfo>
#include <QCryptographicHash>
#include "logininstance.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置进度条范围
    ui->file_uploadProcess->setRange(0,100);
    ui->file_uploadProcess->setValue(0);
    //能打开界面说明登录成功 ->设置用户名
    loginInstance* instance=loginInstance::getInstance();
    instance->setUserName("Tom");

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getMD5(const QString &filePath)
{
    //选择加密方法
    QCryptographicHash hash(QCryptographicHash::Md5);
    //添加数据
    QFile file(filePath);
    file.open(QFile::ReadOnly);
    hash.addData(&file);
    QByteArray res=hash.result().toHex();
    return res;
}

void MainWindow::on_file_choseBtn_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"Select one or more files to open","/Users/c.c/Downloads");
    if(filePath.isEmpty()){//如果路径为空
        QMessageBox::warning(this,"Warning","当前路径为空");
        return;
    }
    ui->file_lineEdit->setText(filePath);
}


void MainWindow::on_file_uploadBtn_clicked(){
    //清除上次的log
    ui->file_logText->clear();
    //1.创建accessManager对象
    QNetworkAccessManager* pManager=new QNetworkAccessManager(this);
    //2.发送数据
    QNetworkRequest request;
    QUrl url("http://127.0.0.1:8082/uploadFile");
    qDebug()<<"目标服务器地址: "<<url;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"multipart/form-data");

    //post数据块
    QFileInfo info(ui->file_lineEdit->text());
    //当前只需要一个数据库，如果有多个数据块，创建多个part即可，分界线会自动添加
    QHttpPart part;
    QString disp=QString(R"(form-data; user="%1"; filename="%2"; md5="%3"; size=%4)")\
    .arg(loginInstance::getInstance()->getUserName(),info.fileName(),getMD5(ui->file_lineEdit->text())).arg(info.size());
    qDebug()<<"单个数据块请求头"<<disp;
    //获取后缀名
    //QString suffix=info.suffix();
    //通过后缀判断传输的数据块的格式
    /*
        json配置文件{
        "-mp3": "audio/mp3",
        ".avi": "video/avi"
        ".html": "text/html",
        ". json":"application/json"
        ｝
    */
    //设置传输数据头的内容
    part.setRawHeader("Content-Disposition",disp.toLatin1());
    //part.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant(disp));
    part.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/octet-stream"));


    //设置数据块内容
    //为什么要new？因为qt里的大部分函数都是非阻塞的，函数很快就执行完了，析构局部变量的时候可能还没有发送完，所以要在堆区创建

    QFile* file=new QFile(ui->file_lineEdit->text());
    file->open(QFile::ReadOnly);
    qDebug()<<"上传文件地址: "<<ui->file_lineEdit->text();
    part.setBodyDevice(file);
    //拼接数据块(当前只有一块)
    //为什么要new？因为qt里的大部分函数都是非阻塞的，函数很快就执行完了，析构局部变量的时候可能还没有发送完，所以要在堆区创建

    QHttpMultiPart* multipart=new QHttpMultiPart(QHttpMultiPart::FormDataType, this);
    multipart->setBoundary("----CustomBoundary12345");
    multipart->append(part);
    ui->file_logText->append("开始向服务器发送数据");
    //debug
    // for (const QByteArray &header : request.rawHeaderList()) {
    //     qDebug() << header << ":" << request.rawHeader(header);
    // }
    //
    QNetworkReply* reply=pManager->post(request,multipart);
    connect(reply,&QNetworkReply::readyRead,this,[=](){
        //接受数据
        QByteArray all=reply->readAll();
        //格式解析
        ui->file_logText->append("服务器返回："+all);

        //收到返回数据说明发送已经完成，释放资源
        // delete multiPart;
        multipart->deleteLater();
        file->close();
        file->deleteLater();
        reply->deleteLater();
    });
    //进度条处理
    connect(reply,&QNetworkReply::uploadProgress,this,[=](qint64 bytesSent, qint64 bytesTota){
        //更新进度条
        qDebug() << "当前进度: " << bytesSent << ", 总数: " << bytesTota;
        if(bytesSent>0)
            ui->file_uploadProcess->setValue(bytesSent*100/bytesTota);
    });
}

