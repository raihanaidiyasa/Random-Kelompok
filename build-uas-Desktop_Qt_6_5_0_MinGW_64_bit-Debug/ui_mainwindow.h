/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelNama;
    QLabel *labelAbsolutPath;
    QLineEdit *lineAbsolutPath;
    QLabel *labelJumlahKel;
    QLineEdit *lineJumlahKel;
    QPushButton *pushButton;
    QCheckBox *cbBagiRata;
    QPushButton *pushButton_2;
    QPlainTextEdit *hasilTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(729, 282);
        MainWindow->setMaximumSize(QSize(730, 282));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelNama = new QLabel(centralwidget);
        labelNama->setObjectName("labelNama");
        labelNama->setGeometry(QRect(100, 10, 260, 36));
        QFont font;
        font.setPointSize(20);
        labelNama->setFont(font);
        labelAbsolutPath = new QLabel(centralwidget);
        labelAbsolutPath->setObjectName("labelAbsolutPath");
        labelAbsolutPath->setGeometry(QRect(40, 60, 81, 16));
        QFont font1;
        font1.setPointSize(11);
        labelAbsolutPath->setFont(font1);
        lineAbsolutPath = new QLineEdit(centralwidget);
        lineAbsolutPath->setObjectName("lineAbsolutPath");
        lineAbsolutPath->setGeometry(QRect(40, 80, 251, 24));
        lineAbsolutPath->setReadOnly(true);
        labelJumlahKel = new QLabel(centralwidget);
        labelJumlahKel->setObjectName("labelJumlahKel");
        labelJumlahKel->setGeometry(QRect(40, 120, 141, 16));
        labelJumlahKel->setFont(font1);
        lineJumlahKel = new QLineEdit(centralwidget);
        lineJumlahKel->setObjectName("lineJumlahKel");
        lineJumlahKel->setGeometry(QRect(40, 140, 251, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 80, 80, 24));
        cbBagiRata = new QCheckBox(centralwidget);
        cbBagiRata->setObjectName("cbBagiRata");
        cbBagiRata->setGeometry(QRect(40, 180, 91, 22));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 180, 80, 24));
        hasilTextEdit = new QPlainTextEdit(centralwidget);
        hasilTextEdit->setObjectName("hasilTextEdit");
        hasilTextEdit->setGeometry(QRect(453, 9, 251, 221));
        hasilTextEdit->setAutoFillBackground(false);
        hasilTextEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 729, 21));
        menubar->setNativeMenuBar(true);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Random Kelompok", nullptr));
        labelNama->setText(QCoreApplication::translate("MainWindow", "RANDOM KELOMPOK", nullptr));
        labelAbsolutPath->setText(QCoreApplication::translate("MainWindow", "Pilih File", nullptr));
        labelJumlahKel->setText(QCoreApplication::translate("MainWindow", "Jumlah Kelompok", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Pilih", nullptr));
        cbBagiRata->setText(QCoreApplication::translate("MainWindow", "Bagi Rata L/P", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Proses", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
