#include "janela2.h"
#include "ui_janela2.h"


Janela2::Janela2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela2)
{
    ui->setupUi(this);

    QPixmap img("/home/alunos/a2625288/Downloads/Minecraft-creeper-face.jpg");
    ui->labelFigura->setPixmap(img.scaled(300, 200, Qt::KeepAspectRatio));
}

Janela2::~Janela2()
{
    delete ui;
}
