#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionClose_triggered();

    void on_actionAbout_us_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionPrint_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
