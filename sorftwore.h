#ifndef SORFTWORE_H
#define SORFTWORE_H

#include <QDialog>
#include<QMovie>
#include<QMediaPlayer>
#include<QCloseEvent>

namespace Ui {
class sorftwore;
}

class sorftwore : public QDialog
{
    Q_OBJECT

public:
    explicit sorftwore(QWidget *parent = nullptr);
    ~sorftwore();

    int count;
    QMediaPlayer *player;
    QMovie *movie;

private:
    Ui::sorftwore *ui;
    QMovie *movie1;
    QMovie *movie2;
    QMovie *movie3;

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void playMovie();
    void stopMovie();
    void on_pushButton_clicked();
};

#endif // SORFTWORE_H
