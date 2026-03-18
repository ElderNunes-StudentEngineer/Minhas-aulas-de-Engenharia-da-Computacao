#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janela2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    jan2 = new Janela2();
    jan2->show();
    //Janela2 jan2; Primeira estratégia
    //jan2.exec();
}

