/********************************************************************************
** Form generated from reading UI file 'BibliographieInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOGRAPHIEINTERFACE_H
#define UI_BIBLIOGRAPHIEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BibliographieInterface
{
public:
    QAction *actionSuprimmer_un_r_f_rence;
    QAction *actionQuitter;
    QAction *actionAjouter_un_ouvrage;
    QAction *actionAjouter_un_journal;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuInterface;
    QMenu *menuAjouter_un_r_f_rence;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BibliographieInterface)
    {
        if (BibliographieInterface->objectName().isEmpty())
            BibliographieInterface->setObjectName(QString::fromUtf8("BibliographieInterface"));
        BibliographieInterface->resize(800, 600);
        actionSuprimmer_un_r_f_rence = new QAction(BibliographieInterface);
        actionSuprimmer_un_r_f_rence->setObjectName(QString::fromUtf8("actionSuprimmer_un_r_f_rence"));
        actionQuitter = new QAction(BibliographieInterface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAjouter_un_ouvrage = new QAction(BibliographieInterface);
        actionAjouter_un_ouvrage->setObjectName(QString::fromUtf8("actionAjouter_un_ouvrage"));
        actionAjouter_un_journal = new QAction(BibliographieInterface);
        actionAjouter_un_journal->setObjectName(QString::fromUtf8("actionAjouter_un_journal"));
        centralwidget = new QWidget(BibliographieInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(180, 100, 401, 321));
        affichage->setReadOnly(true);
        BibliographieInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BibliographieInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuInterface = new QMenu(menubar);
        menuInterface->setObjectName(QString::fromUtf8("menuInterface"));
        menuAjouter_un_r_f_rence = new QMenu(menuInterface);
        menuAjouter_un_r_f_rence->setObjectName(QString::fromUtf8("menuAjouter_un_r_f_rence"));
        BibliographieInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(BibliographieInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BibliographieInterface->setStatusBar(statusbar);

        menubar->addAction(menuInterface->menuAction());
        menuInterface->addAction(menuAjouter_un_r_f_rence->menuAction());
        menuInterface->addAction(actionSuprimmer_un_r_f_rence);
        menuInterface->addAction(actionQuitter);
        menuAjouter_un_r_f_rence->addAction(actionAjouter_un_ouvrage);
        menuAjouter_un_r_f_rence->addAction(actionAjouter_un_journal);

        retranslateUi(BibliographieInterface);
        QObject::connect(actionQuitter, SIGNAL(triggered()), BibliographieInterface, SLOT(close()));
        QObject::connect(actionAjouter_un_journal, SIGNAL(triggered()), BibliographieInterface, SLOT(ajouterJournal()));
        QObject::connect(actionAjouter_un_ouvrage, SIGNAL(triggered()), BibliographieInterface, SLOT(ajouterOuvrage()));
        QObject::connect(actionSuprimmer_un_r_f_rence, SIGNAL(triggered()), BibliographieInterface, SLOT(supprimerReference()));

        QMetaObject::connectSlotsByName(BibliographieInterface);
    } // setupUi

    void retranslateUi(QMainWindow *BibliographieInterface)
    {
        BibliographieInterface->setWindowTitle(QApplication::translate("BibliographieInterface", "BibliographieInterface", nullptr));
        actionSuprimmer_un_r_f_rence->setText(QApplication::translate("BibliographieInterface", "Supprimer r\303\251f\303\251rence", nullptr));
        actionQuitter->setText(QApplication::translate("BibliographieInterface", "Quitter", nullptr));
        actionAjouter_un_ouvrage->setText(QApplication::translate("BibliographieInterface", "Ajouter un ouvrage", nullptr));
        actionAjouter_un_journal->setText(QApplication::translate("BibliographieInterface", "Ajouter un journal", nullptr));
        menuInterface->setTitle(QApplication::translate("BibliographieInterface", "Menu", nullptr));
        menuAjouter_un_r_f_rence->setTitle(QApplication::translate("BibliographieInterface", "Ajouter un r\303\251f\303\251rence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BibliographieInterface: public Ui_BibliographieInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOGRAPHIEINTERFACE_H
