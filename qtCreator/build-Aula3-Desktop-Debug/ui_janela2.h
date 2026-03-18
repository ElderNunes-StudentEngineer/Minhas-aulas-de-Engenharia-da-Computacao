/********************************************************************************
** Form generated from reading UI file 'janela2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA2_H
#define UI_JANELA2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Janela2
{
public:
    QLabel *labelFigura;

    void setupUi(QDialog *Janela2)
    {
        if (Janela2->objectName().isEmpty())
            Janela2->setObjectName(QString::fromUtf8("Janela2"));
        Janela2->resize(548, 392);
        labelFigura = new QLabel(Janela2);
        labelFigura->setObjectName(QString::fromUtf8("labelFigura"));
        labelFigura->setGeometry(QRect(110, 40, 331, 261));
        labelFigura->setPixmap(QPixmap(QString::fromUtf8("../../../../../home/alunos/a2625288/Downloads/Minecraft-creeper-face.jpg")));
        labelFigura->setScaledContents(true);

        retranslateUi(Janela2);

        QMetaObject::connectSlotsByName(Janela2);
    } // setupUi

    void retranslateUi(QDialog *Janela2)
    {
        Janela2->setWindowTitle(QCoreApplication::translate("Janela2", "Dialog", nullptr));
        labelFigura->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Janela2: public Ui_Janela2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA2_H
