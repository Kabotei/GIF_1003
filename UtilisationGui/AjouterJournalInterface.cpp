/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterJournalInterface.cpp
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 16:00
 */

#include "AjouterJournalInterface.h"
#include "validationFormat.h"
#include <QMessageBox>
#include <string>


using namespace util;


AjouterJournalInterface::AjouterJournalInterface ()
{
  widget.setupUi (this);
}


AjouterJournalInterface::~AjouterJournalInterface () { }


QString
AjouterJournalInterface::reqAutheurs () const
{
  return widget.autheur->text ();
}


QString
AjouterJournalInterface::reqNom () const
{
  return widget.nom->text ();
}


QString
AjouterJournalInterface::reqID () const
{
  return widget.id->text ();
}


int
AjouterJournalInterface::reqAnnee () const
{
  return widget.annee->value ();
}


int
AjouterJournalInterface::reqVolume () const
{
  return widget.volume->value ();
}


int
AjouterJournalInterface::reqNumero () const
{
  return widget.numero->value ();
}


int
AjouterJournalInterface::reqPage () const
{
  return widget.page->value ();
}


void
AjouterJournalInterface::validation ()
{

  if (!validerFormatNom (reqAutheurs ().toStdString ()))
    {
      QString message ("Le nom des autheurs doivent suivre un certain format.");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  if (reqNom ().isEmpty ())
    {
      QString message ("Le nom du journal ne doit pas être vide");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }

  if (!validerCodeIssn (reqID ().toStdString ()))
    {
      QString message ("L'dentifiant doit suivre un format ISSN");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  if (reqAnnee () <= 0)
    {
      QString message ("L'année doit être strictement positif");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }

  accept ();
}