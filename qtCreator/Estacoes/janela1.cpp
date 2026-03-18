#include "janela1.h"
#include "ui_janela1.h"

Janela1::Janela1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela1)
{
    ui->setupUi(this);
}

Janela1::~Janela1()
{
    delete ui;
}
