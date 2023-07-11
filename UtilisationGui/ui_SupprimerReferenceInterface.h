/********************************************************************************
** Form generated from reading UI file 'SupprimerReferenceInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERREFERENCEINTERFACE_H
#define UI_SUPPRIMERREFERENCEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupprimerReferenceInterface
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *id;
    QPushButton *ok;

    void setupUi(QDialog *SupprimerReferenceInterface)
    {
        if (SupprimerReferenceInterface->objectName().isEmpty())
            SupprimerReferenceInterface->setObjectName(QString::fromUtf8("SupprimerReferenceInterface"));
        SupprimerReferenceInterface->resize(535, 257);
        formLayoutWidget = new QWidget(SupprimerReferenceInterface);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(18, 80, 511, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, id);

        ok = new QPushButton(SupprimerReferenceInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(410, 210, 90, 28));

        retranslateUi(SupprimerReferenceInterface);
        QObject::connect(ok, SIGNAL(clicked()), SupprimerReferenceInterface, SLOT(validation()));

        QMetaObject::connectSlotsByName(SupprimerReferenceInterface);
    } // setupUi

    void retranslateUi(QDialog *SupprimerReferenceInterface)
    {
        SupprimerReferenceInterface->setWindowTitle(QApplication::translate("SupprimerReferenceInterface", "SupprimerReferenceInterface", nullptr));
        label->setText(QApplication::translate("SupprimerReferenceInterface", "Identifiant \303\240 supprimer :", nullptr));
        ok->setText(QApplication::translate("SupprimerReferenceInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerReferenceInterface: public Ui_SupprimerReferenceInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERREFERENCEINTERFACE_H
