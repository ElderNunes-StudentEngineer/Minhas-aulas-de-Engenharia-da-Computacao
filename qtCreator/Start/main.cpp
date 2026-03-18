#include "mainwindow.h"

#include <QApplication> //essencial em qualquer aplicação que usa o QT com interface

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //criando um obj da aplicação QT
    MainWindow w; //cria a janela principal da aplicação
    w.show(); //exibe a janela da aplicação
    return a.exec(); //loop de eventos (por exemplo: click do botão, etc)
}
