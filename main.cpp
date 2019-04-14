#include "mainwindow.h"
#include <QApplication>
#include<QPixmap>
#include<QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPixmap pixmap("screenImg.png");
    QSplashScreen splash(pixmap);
    splash.show();
    for(int i=0;i<9000000;i++);
    app.processEvents();
    QMainWindow window;
    MainWindow w;
    w.show();
    splash.finish(&w);
    return app.exec();
}
