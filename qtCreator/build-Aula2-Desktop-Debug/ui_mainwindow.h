/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelPeso;
    QLabel *labelAltura;
    QLineEdit *lineEditPeso;
    QLineEdit *lineEditAltura;
    QPushButton *pushButtonCalcular;
    QLabel *labelResposta;
    QPushButton *pushButtonClear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelPeso = new QLabel(centralwidget);
        labelPeso->setObjectName(QString::fromUtf8("labelPeso"));
        labelPeso->setGeometry(QRect(120, 50, 67, 17));
        labelAltura = new QLabel(centralwidget);
        labelAltura->setObjectName(QString::fromUtf8("labelAltura"));
        labelAltura->setGeometry(QRect(120, 90, 67, 17));
        lineEditPeso = new QLineEdit(centralwidget);
        lineEditPeso->setObjectName(QString::fromUtf8("lineEditPeso"));
        lineEditPeso->setGeometry(QRect(210, 40, 113, 25));
        lineEditAltura = new QLineEdit(centralwidget);
        lineEditAltura->setObjectName(QString::fromUtf8("lineEditAltura"));
        lineEditAltura->setGeometry(QRect(210, 90, 113, 25));
        pushButtonCalcular = new QPushButton(centralwidget);
        pushButtonCalcular->setObjectName(QString::fromUtf8("pushButtonCalcular"));
        pushButtonCalcular->setGeometry(QRect(350, 70, 89, 25));
        labelResposta = new QLabel(centralwidget);
        labelResposta->setObjectName(QString::fromUtf8("labelResposta"));
        labelResposta->setGeometry(QRect(230, 140, 211, 17));
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(510, 70, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelPeso->setText(QCoreApplication::translate("MainWindow", "Peso(Kg):", nullptr));
        labelAltura->setText(QCoreApplication::translate("MainWindow", "Altura(m):", nullptr));
        pushButtonCalcular->setText(QCoreApplication::translate("MainWindow", "Calcular", nullptr));
        labelResposta->setText(QCoreApplication::translate("MainWindow", "Resultado", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
