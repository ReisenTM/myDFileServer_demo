#include "titlewg.h"
#include "ui_titlewg.h"


Title::Title(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Titlewg)
{
    ui->setupUi(this);
    //设置icon
    //ui->logo->setPixmap(QPixmap(":/images/logo.ico").scaled(40,40));
    //设置按钮图片填充
    // ui->close->setStyleSheet("QToolButton { border: none; background: transparent; }");
    // ui->min->setStyleSheet("QToolButton{border: none;background:transparent}");
    // ui->setting->setStyleSheet("QToolButton {border:none;background:transparent}");

    //title里的按键一收到按下信号就发出自定义信号
    connect(ui->min,&QPushButton::clicked,this,[this](){
        emit this->showMinWindow();
    });
    connect(ui->setting,&QPushButton::clicked,this,[this](){
        emit this->showSetWindow();
    });
    connect(ui->close,&QPushButton::clicked,this,[this](){
        emit this->closeWindow();
    });

}

Title::~Title()
{
    delete ui;
}

void Title::setMyParent(QWidget *parent)
{
    this->my_parent=parent;
}

void Title::mouseMoveEvent(QMouseEvent *event)
{
    //如果是左键
    if(event->buttons() & Qt::LeftButton){
        //左上角的位置=当前鼠标位置-相对位置；
        this->my_parent->move (event->globalPosition().toPoint()-this->m_pt) ;
    }
}

void Title::mousePressEvent(QMouseEvent *event)
{
    //如果是左键
    if(event->button()==Qt::LeftButton){
        //相对位置=当前鼠标位置-左上角的位置；
        m_pt=event->globalPosition().toPoint()-this->my_parent->geometry().topLeft();
    }
}
