#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include<QFontDialog>
#include<QColorDialog>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_us_triggered()
{
    QMessageBox::information(this, "About Us", "We are a software company bla bla bla bla bla......");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
  QApplication::aboutQt();
}
//for print dialog
void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("Print Dialog");
    if(ui->textEdit->textCursor().hasSelection())
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if(dialog.exec()!=QDialog::Accepted){
        return;}
}
//font dialog
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font= QFontDialog::getFont(&ok, QFont("Times New Roman", 12), this);
    if(ok){
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_actionColor_triggered()
{
    bool ok;
    QColor color= QColorDialog::getColor(Qt::blue, this);
    if(&ok){
        ui->textEdit->setTextColor(color);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    //Create File Dialog
    QString fileName= QFileDialog::getOpenFileName(this, "Open a file", "C://");
    ui->textEdit->setText(fileName);
}
