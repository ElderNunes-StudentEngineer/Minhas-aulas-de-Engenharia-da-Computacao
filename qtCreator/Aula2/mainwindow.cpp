#include "mainwindow.h"
#include "ui_mainwindow.h"

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



void MainWindow::on_pushButtonCalcular_clicked()
{
    IMC obj;
    obj.setPeso(ui->lineEditPeso->text().toDouble());
    obj.setAltura(ui->lineEditAltura->text().toDouble());
    obj.setResultado(obj.calculaImc());
    ui->labelResposta->setText(obj.statusImc());
}

void MainWindow::on_pushButtonClear_clicked()
{/*
    ui->lineEditAltura->clear();
    ui->lineEditPeso->clear();
    ui->labelResposta->clear();
*/
}

