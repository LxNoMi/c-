#include "sorftwore.h"
#include "ui_sorftwore.h"
#include<QDebug>
#include<QMessageBox>

sorftwore::sorftwore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sorftwore)
{
    this->count=0;
    this->player = new QMediaPlayer();
    this->movie1=new QMovie("star.gif");
    this->movie2=new QMovie("flower.gif");
    this->movie3=new QMovie("flower1.gif");
    this->movie=new QMovie("star.gif");
    ui->setupUi(this);
    on_pushButton_clicked();
    QObject::connect(ui->playButton,SIGNAL(clicked()),this,SLOT(playMovie()));
    QObject::connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stopMovie()));

    //播放背景音乐音乐
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("music1.mp3"));
    player->setVolume(50);
}

sorftwore::~sorftwore()
{
    delete ui;
}

void sorftwore::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void sorftwore::playMovie()
{
    this->movie->start();
    this->player->play();
}

void sorftwore::stopMovie()
{
    this->movie->stop();
    this->player->stop();
}

void sorftwore::on_pushButton_clicked()
{
    sorftwore::count=(sorftwore::count+1)%3;
    switch (sorftwore::count)
    {
    case 0:
        this->movie=this->movie1;
        break;
    case 1:
        this->movie=this->movie2;
        break;
    case 2:
        this->movie=this->movie3;
        break;
    default:
        QMessageBox::information(this,"错误:","播放序号出错");
        break;
    }
    ui->movieLabel->setMovie(this->movie);
    this->movie->start();
}
