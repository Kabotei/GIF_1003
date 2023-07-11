/********************************************************************************
** Form generated from reading UI file 'AjouterJournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERJOURNALINTERFACE_H
#define UI_AJOUTERJOURNALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjouterJournalInterface
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *autheur;
    QLineEdit *nom;
    QLineEdit *id;
    QSpinBox *volume;
    QSpinBox *numero;
    QSpinBox *page;
    QLabel *label_7;
    QSpinBox *annee;
    QPushButton *ok;

    void setupUi(QDialog *AjouterJournalInterface)
    {
        if (AjouterJournalInterface->objectName().isEmpty())
            AjouterJournalInterface->setObjectName(QString::fromUtf8("AjouterJournalInterface"));
        AjouterJournalInterface->resize(576, 440);
        formLayoutWidget = new QWidget(AjouterJournalInterface);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 30, 491, 226));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        autheur = new QLineEdit(formLayoutWidget);
        autheur->setObjectName(QString::fromUtf8("autheur"));

        formLayout->setWidget(0, QFormLayout::FieldRole, autheur);

        nom = new QLineEdit(formLayoutWidget);
        nom->setObjectName(QString::fromUtf8("nom"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nom);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));

        formLayout->setWidget(6, QFormLayout::FieldRole, id);

        volume = new QSpinBox(formLayoutWidget);
        volume->setObjectName(QString::fromUtf8("volume"));

        formLayout->setWidget(3, QFormLayout::FieldRole, volume);

        numero = new QSpinBox(formLayoutWidget);
        numero->setObjectName(QString::fromUtf8("numero"));

        formLayout->setWidget(4, QFormLayout::FieldRole, numero);

        page = new QSpinBox(formLayoutWidget);
        page->setObjectName(QString::fromUtf8("page"));

        formLayout->setWidget(5, QFormLayout::FieldRole, page);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        annee = new QSpinBox(formLayoutWidget);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setMaximum(3000);

        formLayout->setWidget(2, QFormLayout::FieldRole, annee);

        ok = new QPushButton(AjouterJournalInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(400, 380, 90, 28));

        retranslateUi(AjouterJournalInterface);
        QObject::connect(ok, SIGNAL(clicked()), AjouterJournalInterface, SLOT(validation()));

        QMetaObject::connectSlotsByName(AjouterJournalInterface);
    } // setupUi

    void retranslateUi(QDialog *AjouterJournalInterface)
    {
        AjouterJournalInterface->setWindowTitle(QApplication::translate("AjouterJournalInterface", "AjouterJournalInterface", nullptr));
        label_2->setText(QApplication::translate("AjouterJournalInterface", "Autheur(s) :", nullptr));
        label->setText(QApplication::translate("AjouterJournalInterface", "Nom :", nullptr));
        label_3->setText(QApplication::translate("AjouterJournalInterface", "Volume :", nullptr));
        label_4->setText(QApplication::translate("AjouterJournalInterface", "Numero :", nullptr));
        label_5->setText(QApplication::translate("AjouterJournalInterface", "Page :", nullptr));
        label_6->setText(QApplication::translate("AjouterJournalInterface", "ISSN :", nullptr));
        label_7->setText(QApplication::translate("AjouterJournalInterface", "Ann\303\251e :", nullptr));
        ok->setText(QApplication::translate("AjouterJournalInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterJournalInterface: public Ui_AjouterJournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERJOURNALINTERFACE_H
