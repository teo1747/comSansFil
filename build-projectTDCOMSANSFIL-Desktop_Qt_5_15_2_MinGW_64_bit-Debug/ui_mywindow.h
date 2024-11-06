/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mYWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Connect;
    QTextEdit *Affichage;
    QPushButton *Disconnect;
    QGroupBox *Identite;
    QTextEdit *Name;
    QTextEdit *Surname;
    QPushButton *Mise_a_jour;
    QLabel *label2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mYWindow)
    {
        if (mYWindow->objectName().isEmpty())
            mYWindow->setObjectName(QString::fromUtf8("mYWindow"));
        mYWindow->resize(800, 600);
        centralwidget = new QWidget(mYWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Connect = new QPushButton(centralwidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(20, 260, 75, 23));
        Affichage = new QTextEdit(centralwidget);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->setGeometry(QRect(360, 110, 104, 71));
        Disconnect = new QPushButton(centralwidget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(130, 260, 75, 23));
        Identite = new QGroupBox(centralwidget);
        Identite->setObjectName(QString::fromUtf8("Identite"));
        Identite->setGeometry(QRect(390, 20, 120, 80));
        Name = new QTextEdit(Identite);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(0, 10, 111, 31));
        Surname = new QTextEdit(Identite);
        Surname->setObjectName(QString::fromUtf8("Surname"));
        Surname->setGeometry(QRect(0, 40, 111, 31));
        Mise_a_jour = new QPushButton(centralwidget);
        Mise_a_jour->setObjectName(QString::fromUtf8("Mise_a_jour"));
        Mise_a_jour->setGeometry(QRect(80, 150, 75, 23));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(230, 90, 47, 13));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 90, 47, 13));
        mYWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mYWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        mYWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mYWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mYWindow->setStatusBar(statusbar);

        retranslateUi(mYWindow);

        QMetaObject::connectSlotsByName(mYWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mYWindow)
    {
        mYWindow->setWindowTitle(QCoreApplication::translate("mYWindow", "mYWindow", nullptr));
        Connect->setText(QCoreApplication::translate("mYWindow", "connect", nullptr));
        Disconnect->setText(QCoreApplication::translate("mYWindow", "DIsconnect", nullptr));
        Identite->setTitle(QCoreApplication::translate("mYWindow", "GroupBox", nullptr));
        Mise_a_jour->setText(QCoreApplication::translate("mYWindow", "Update", nullptr));
        label2->setText(QCoreApplication::translate("mYWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("mYWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mYWindow: public Ui_mYWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
