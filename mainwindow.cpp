#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogentredata.h"
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

void MainWindow::on_pushButton_clicked()
{
    DialogEntreData d(ui->D_HDB,this);
    d.exec();
}
