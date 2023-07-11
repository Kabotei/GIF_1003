/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SupprimerReferenceInterface.cpp
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 15:50
 */

#include "SupprimerReferenceInterface.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace util;


SupprimerReferenceInterface::SupprimerReferenceInterface ()
{
  widget.setupUi (this);
}


SupprimerReferenceInterface::~SupprimerReferenceInterface () { }


QString
SupprimerReferenceInterface::reqID () const
{
  return widget.id->text ();
}


void
SupprimerReferenceInterface::validation ()
{
  if (!(validerCodeIsbn (reqID ().toStdString ()) or validerCodeIssn (reqID ().toStdString ())))
    {
      QString message ("L'dentifiant doit suivre un format ISBN ou un format ISSN");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  accept ();
}