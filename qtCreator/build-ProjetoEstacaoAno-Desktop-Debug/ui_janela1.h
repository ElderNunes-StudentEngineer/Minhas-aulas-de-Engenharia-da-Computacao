/********************************************************************************
** Form generated from reading UI file 'janela1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA1_H
#define UI_JANELA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_JanelaMain
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *JanelaMain)
    {
        if (JanelaMain->objectName().isEmpty())
            JanelaMain->setObjectName(QString::fromUtf8("JanelaMain"));
        JanelaMain->resize(524, 358);
        label = new QLabel(JanelaMain);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 41, 17));
        label_2 = new QLabel(JanelaMain);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 120, 67, 17));
        lineEdit = new QLineEdit(JanelaMain);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 70, 113, 25));
        lineEdit_2 = new QLineEdit(JanelaMain);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 120, 113, 25));
        pushButton = new QPushButton(JanelaMain);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 170, 89, 25));

        retranslateUi(JanelaMain);

        QMetaObject::connectSlotsByName(JanelaMain);
    } // setupUi

    void retranslateUi(QDialog *JanelaMain)
    {
        JanelaMain->setWindowTitle(QCoreApplication::translate("JanelaMain", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("JanelaMain", "Dia:", nullptr));
        label_2->setText(QCoreApplication::translate("JanelaMain", "M\303\252s:", nullptr));
        pushButton->setText(QCoreApplication::translate("JanelaMain", "Esta\303\247\303\243o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaMain: public Ui_JanelaMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA1_H
