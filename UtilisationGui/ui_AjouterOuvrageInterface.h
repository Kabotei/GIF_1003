/********************************************************************************
** Form generated from reading UI file 'AjouterOuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTEROUVRAGEINTERFACE_H
#define UI_AJOUTEROUVRAGEINTERFACE_H

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

class Ui_AjouterOuvrageInterface
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *autheur;
    QLabel *label_2;
    QLineEdit *titre;
    QLabel *label_4;
    QSpinBox *annee;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *editeur;
    QLabel *label_6;
    QLineEdit *ville;
    QLineEdit *id;
    QPushButton *ok;

    void setupUi(QDialog *AjouterOuvrageInterface)
    {
        if (AjouterOuvrageInterface->objectName().isEmpty())
            AjouterOuvrageInterface->setObjectName(QString::fromUtf8("AjouterOuvrageInterface"));
        AjouterOuvrageInterface->resize(495, 381);
        formLayoutWidget = new QWidget(AjouterOuvrageInterface);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 70, 461, 220));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        autheur = new QLineEdit(formLayoutWidget);
        autheur->setObjectName(QString::fromUtf8("autheur"));

        formLayout->setWidget(0, QFormLayout::FieldRole, autheur);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        titre = new QLineEdit(formLayoutWidget);
        titre->setObjectName(QString::fromUtf8("titre"));

        formLayout->setWidget(1, QFormLayout::FieldRole, titre);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        annee = new QSpinBox(formLayoutWidget);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setMaximum(3000);

        formLayout->setWidget(2, QFormLayout::FieldRole, annee);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        editeur = new QLineEdit(formLayoutWidget);
        editeur->setObjectName(QString::fromUtf8("editeur"));

        formLayout->setWidget(4, QFormLayout::FieldRole, editeur);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        ville = new QLineEdit(formLayoutWidget);
        ville->setObjectName(QString::fromUtf8("ville"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ville);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));

        formLayout->setWidget(3, QFormLayout::FieldRole, id);

        ok = new QPushButton(AjouterOuvrageInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(370, 330, 90, 28));

        retranslateUi(AjouterOuvrageInterface);
        QObject::connect(ok, SIGNAL(clicked()), AjouterOuvrageInterface, SLOT(validation()));

        QMetaObject::connectSlotsByName(AjouterOuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *AjouterOuvrageInterface)
    {
        AjouterOuvrageInterface->setWindowTitle(QApplication::translate("AjouterOuvrageInterface", "AjouterOuvrageInterface", nullptr));
        label->setText(QApplication::translate("AjouterOuvrageInterface", "Autheur(s) : ", nullptr));
        label_2->setText(QApplication::translate("AjouterOuvrageInterface", "Titre : ", nullptr));
        label_4->setText(QApplication::translate("AjouterOuvrageInterface", "Annee : ", nullptr));
        label_3->setText(QApplication::translate("AjouterOuvrageInterface", "ISBN : ", nullptr));
        label_5->setText(QApplication::translate("AjouterOuvrageInterface", "Editeur : ", nullptr));
        label_6->setText(QApplication::translate("AjouterOuvrageInterface", "Ville : ", nullptr));
        id->setText(QString());
        ok->setText(QApplication::translate("AjouterOuvrageInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterOuvrageInterface: public Ui_AjouterOuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEROUVRAGEINTERFACE_H
