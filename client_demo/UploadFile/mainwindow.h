#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getMD5(const QString& filePath);
private slots:
    void on_file_choseBtn_clicked();

    void on_file_uploadBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
