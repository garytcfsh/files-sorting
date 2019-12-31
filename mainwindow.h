#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int openName();
    int openNum();
    int openfiles();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList name, num;
    QStringList fileNameList;
    QString Dir;
};
#endif // MAINWINDOW_H
