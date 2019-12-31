#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::openNum()
{
    QString numPath = QFileDialog::getOpenFileName(
                this,
                tr("student number"),
                "",
                "all file (*)");
    if (!numPath.isNull())
    {
        QFile numFile( numPath);
        numFile.open(QFile::ReadOnly|QFile::Text);
        QTextStream numIn(&numFile);
        while (!numIn.atEnd())
        {
            num.append(numIn.readLine());
        }
        return 0;
    }
    return -1;
}

int MainWindow::openName()
{
    qDebug()<<"1";
    QString namePath = QFileDialog::getOpenFileName(
                this,
                tr("name"),
                "",
                "all file (*)");
    qDebug()<<"2";
    if (!namePath.isNull())
    {
        QFile nameFile( namePath);
        nameFile.open(QFile::ReadOnly|QFile::Text);
        QTextStream nameIn(&nameFile);
        int i=0;
        qDebug()<<"3";
        while (!nameIn.atEnd())
        {
            name.append(nameIn.readLine());
            name[i].remove('\t');
            name[i].remove(" ");
            name[i].remove('\n');
            i++;
        }
        return 0;
    }
    return -1;
}

int MainWindow::openfiles()
{
    QFileDialog fd(this);
    fd.setFileMode( QFileDialog::ExistingFiles);
    fd.setNameFilter("all file (*)");
    fd.setViewMode( QFileDialog::Detail);
    QDir fileDir;
    QString filePath;
    if (fd.exec())
    {
        fileNameList = fd.selectedFiles();
        fileDir = fd.directory();
        filePath = fileDir.path();
        Dir = filePath;
        return filePath.count();
    }
    return -1;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName;
    openName();
    openNum();
    openfiles();

    QFile QF;
    for (int i=0; i<fileNameList.count(); i++)
    {
        QF.setFileName(fileNameList[i]);
        for (int j=0; j<name.count(); j++)
        {
            fileName = QF.fileName();
            if (fileName.remove(0, Dir.count()+1).contains(name[j]))
            {
                QF.rename(Dir + "/" + num[j] + " " + fileName);
            }
        }
    }
}
