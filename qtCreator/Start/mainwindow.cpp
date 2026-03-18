#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>

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


void MainWindow::on_pushButtonBUTAO_clicked(){
    ui->label->setText("Alterado");
}

void MainWindow::on_pushButtonMensg_clicked(){
   QMessageBox::about(this, "Título", "Mensagem!");
}

