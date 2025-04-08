#ifndef TITLEWG_H
#define TITLEWG_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class Titlewg;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();
    //绑定父窗口
    void setMyParent(QWidget * parent);
signals:
    void showMinWindow();
    void showSetWindow();
    void closeWindow();
protected:
    //鼠标拖动
    void mouseMoveEvent(QMouseEvent* event);
    //鼠标按下，获得相对位置
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::Titlewg *ui;
    //绑定父窗口
    QWidget* my_parent=nullptr;
    QPoint m_pt;
};

#endif // TITLEWG_H
