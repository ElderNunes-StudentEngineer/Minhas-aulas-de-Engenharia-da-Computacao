#ifndef JANELA1_H
#define JANELA1_H

#include <QDialog>

namespace Ui {
class Janela1;
}

class Janela1 : public QDialog
{
    Q_OBJECT

public:
    explicit Janela1(QWidget *parent = nullptr);
    ~Janela1();

private:
    Ui::Janela1 *ui;
};

#endif // JANELA1_H
