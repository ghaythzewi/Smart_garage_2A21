/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *modifiesponsor;
    QWidget *widget;
    QGroupBox *groupBox;
    QPushButton *pb_ajouter;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QCommandLinkButton *commandLinkButton;
    QWidget *aff;
    QTableView *tab_etud;
    QWidget *g;
    QPushButton *pb_supprimer;
    QLineEdit *le_supp;
    QWidget *tab;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(947, 642);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        modifiesponsor = new QTabWidget(centralwidget);
        modifiesponsor->setObjectName(QStringLiteral("modifiesponsor"));
        modifiesponsor->setGeometry(QRect(40, 40, 741, 341));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 741, 261));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(400, 100, 93, 28));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 55, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 90, 55, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 160, 55, 16));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(140, 50, 113, 22));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(130, 100, 113, 22));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(110, 160, 113, 22));
        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(70, 230, 187, 41));
        modifiesponsor->addTab(widget, QString());
        aff = new QWidget();
        aff->setObjectName(QStringLiteral("aff"));
        tab_etud = new QTableView(aff);
        tab_etud->setObjectName(QStringLiteral("tab_etud"));
        tab_etud->setGeometry(QRect(130, 30, 461, 251));
        modifiesponsor->addTab(aff, QString());
        g = new QWidget();
        g->setObjectName(QStringLiteral("g"));
        pb_supprimer = new QPushButton(g);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(400, 90, 93, 28));
        le_supp = new QLineEdit(g);
        le_supp->setObjectName(QStringLiteral("le_supp"));
        le_supp->setGeometry(QRect(210, 90, 113, 22));
        modifiesponsor->addTab(g, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 120, 93, 28));
        modifiesponsor->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 947, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        modifiesponsor->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "ajout", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("MainWindow", "CommandLinkButton", Q_NULLPTR));
        modifiesponsor->setTabText(modifiesponsor->indexOf(widget), QApplication::translate("MainWindow", "ajouter un sponsor", Q_NULLPTR));
        modifiesponsor->setTabText(modifiesponsor->indexOf(aff), QApplication::translate("MainWindow", "afficher un sponsor", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        modifiesponsor->setTabText(modifiesponsor->indexOf(g), QApplication::translate("MainWindow", "supprimer un sponsor", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        modifiesponsor->setTabText(modifiesponsor->indexOf(tab), QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
