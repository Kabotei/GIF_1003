/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterOuvrageInterface.cpp
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 16:01
 */

#include "AjouterOuvrageInterface.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace util;


AjouterOuvrageInterface::AjouterOuvrageInterface ()
{
  widget.setupUi (this);
}


AjouterOuvrageInterface::~AjouterOuvrageInterface () { }


QString
AjouterOuvrageInterface::reqAutheurs () const
{
  return widget.autheur->text ();
}


QString
AjouterOuvrageInterface::reqTitre () const
{
  return widget.titre->text ();
}


QString
AjouterOuvrageInterface::reqID () const
{
  return widget.id->text ();
}


QString
AjouterOuvrageInterface::reqEditeur () const
{
  return widget.editeur->text ();
}


QString
AjouterOuvrageInterface::reqVille () const
{
  return widget.ville->text ();
}


int
AjouterOuvrageInterface::reqAnnee () const
{
  return widget.annee->value ();
}


void
AjouterOuvrageInterface::validation ()
{

  if (!validerFormatNom (reqAutheurs ().toStdString ()))
    {
      QString message ("Le nom des autheurs doivent suivre un certain format.");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  if (reqTitre ().isEmpty ())
    {
      QString message ("Le titre de l'ouvrage ne doit pas être vide");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }

  if (!validerCodeIsbn (reqID ().toStdString ()))
    {
      QString message ("L'dentifiant doit suivre un format ISBN");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  if (reqAnnee () <= 0)
    {
      QString message ("L'année doit être strictement positif");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  if (!validerFormatNom (reqEditeur ().toStdString ()))
    {
      QString message ("Le nom de l'editeur doit suivre un certain format.");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }
  if (!validerFormatNom (reqVille ().toStdString ()))
    {
      QString message ("Le nom de la ville d'édition doit suivre un certain format.");
      QMessageBox::information (this, "Erreur Syntaxe :", message);
      return;
    }

  accept ();
}