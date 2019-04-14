#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include<QFont>
#include<QFontDialog>
#include<QColor>
#include<QColorDialog>
#include<QDateTime>
#include<QUrl>
#include<QDesktopServices>
#include "sorftwore.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("未命名");
    QObject::connect(ui->action_N,SIGNAL(triggered()),this,SLOT(newFileSlot()));
    QObject::connect(ui->action_O,SIGNAL(triggered()),this,SLOT(openFileSlot()));
    QObject::connect(ui->action_S,SIGNAL(triggered()),this,SLOT(saveFileSlot()));
    QObject::connect(ui->action_A,SIGNAL(triggered()),this,SLOT(saveAsFileSlot()));
    QObject::connect(ui->action_P,SIGNAL(triggered()),this,SLOT(printFileSlot()));
    //退出
    QObject::connect(ui->action_X,SIGNAL(triggered()),this,SLOT(close()));
    //设置字体
    QObject::connect(ui->action_F_2,SIGNAL(triggered()),this,SLOT(setFontSlot()));
    //设置颜色
    QObject::connect(ui->action_C_2,SIGNAL(triggered()),this,SLOT(setColorSlot()));
    //时间/日期
    QObject::connect(ui->action_D,SIGNAL(triggered()),this,SLOT(showDateTimeSlot()));
    //撤销
    QObject::connect(ui->action_U_2,SIGNAL(triggered()),ui->textEdit,SLOT(undo()));
    //复制
    QObject::connect(ui->action_C,SIGNAL(triggered()),ui->textEdit,SLOT(copy()));
    //粘贴
    QObject::connect(ui->action_P_2,SIGNAL(triggered()),ui->textEdit,SLOT(paste()));
    //剪切
    QObject::connect(ui->action_T,SIGNAL(triggered()),ui->textEdit,SLOT(cut()));
    //删除
    QObject::connect(ui->action_L,SIGNAL(triggered()),ui->textEdit,SLOT(delete()));
    //挂于qt
    QObject::connect(ui->aboutQtAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    //连接官网
    QObject::connect(ui->websiteAction,SIGNAL(triggered()),this,SLOT(aboutWebsiteSlot()));
    //关于软件
    QObject::connect(ui->aboutSorftworeAction,SIGNAL(triggered()),this,SLOT(aboutSorftwareSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//新建文件
void MainWindow::newFileSlot()
{
    if(ui->textEdit->document()->isModified())
    {
        this->saveFileSlot();
        ui->textEdit->clear();
        this->setWindowTitle("未命名.txt");
    }
    else
    {
        ui->textEdit->clear();
        this->setWindowTitle("未命名.txt");
    }
}

//打开文件
void MainWindow::openFileSlot()
{
    QString fileName=QFileDialog::getOpenFileName(this,"打开文件:",QDir::currentPath());
    if(fileName.isEmpty())
    {
        return ;
    }
    QFile *file=new QFile;
    file->setFileName(fileName);
    bool ok=file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        ui->textEdit->setText(in.readAll());
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"错误:","文件:"+fileName+"不可读");
        return;
    }
}
//保存文件
void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())
    {
        this->saveAsFileSlot();
        return;
    }
    QFile *file=new QFile;
    file->setFileName(saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out<<ui->textEdit->toPlainText();
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"错误:","文件"+saveFileName+"不可写");
        return ;
    }
}

//另存文件
void MainWindow::saveAsFileSlot()
{
    QString saveFileName=QFileDialog::getSaveFileName(this,"保存文件:",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"错误:","保存文件名未设置");
        return;
    }
    QFile *file=new QFile;
    file->setFileName(saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out<<ui->textEdit->toPlainText();
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"Error:","文件："+saveFileName+"不可写入");
        return ;
    }
}

//打印文件
void MainWindow::printFileSlot()
{
    QMessageBox::information(this,"提示:","文件已打印");
    return ;
}

//设置字体
void MainWindow::setFontSlot()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        QMessageBox::information(this,"错误:","字体设置失败!");
        return ;
    }

}

void MainWindow::setColorSlot()
{
    QColor color = QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this,"错误:","颜色设置失败");
        return ;
    }
}

void MainWindow::showDateTimeSlot()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("yyyy-MM-dd  hh:mm:ss");
    ui->textEdit->append(time);
}

void MainWindow::aboutWebsiteSlot()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

void MainWindow::aboutSorftwareSlot()
{
    sorftwore *sorft=new sorftwore;
    sorft->show();
}

void MainWindow::on_textEdit_textChanged()
{

}
