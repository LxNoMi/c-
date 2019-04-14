#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString saveFileName;
private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveAsFileSlot();
    void printFileSlot();
    void setFontSlot();
    void setColorSlot();
    void showDateTimeSlot();
    void aboutWebsiteSlot();
    void aboutSorftwareSlot();

    void on_textEdit_textChanged();
};

#endif // MAINWINDOW_H
