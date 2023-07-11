/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BibliographieInterface.cpp
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 14:43
 */

#include "BibliographieInterface.h"
#include "AjouterJournalInterface.h"
#include "AjouterOuvrageInterface.h"
#include "SupprimerReferenceInterface.h"
#include "Journal.h"
#include "Ouvrage.h"


using namespace std;
using namespace util;
using namespace biblio;


BibliographieInterface::BibliographieInterface () : m_biblio (Bibliographie ("Bibliographie"))
{
  widget.setupUi (this);

  widget.affichage->setText (m_biblio.reqBibliographieFormate ().c_str ());
}


BibliographieInterface::~BibliographieInterface () { }


void
BibliographieInterface::ajouterJournal ()
{
  AjouterJournalInterface reference;
  if (reference.exec ())
    {
      ajouterReferenceJournal (reference.reqAutheurs ().toStdString (),
                               reference.reqNom ().toStdString (),
                               reference.reqAnnee (),
                               reference.reqID ().toStdString (),
                               reference.reqVolume (),
                               reference.reqNumero (),
                               reference.reqPage ());
    }
  widget.affichage->setText (m_biblio.reqBibliographieFormate ().c_str ());
}


void
BibliographieInterface::ajouterOuvrage ()
{
  AjouterOuvrageInterface reference;
  if (reference.exec ())
    {


      ajouterReferenceOuvrage (reference.reqAutheurs ().toStdString (),
                               reference.reqTitre ().toStdString (),
                               reference.reqAnnee (),
                               reference.reqID ().toStdString (),
                               reference.reqEditeur ().toStdString (),
                               reference.reqVille ().toStdString ());
    }
  widget.affichage->setText (m_biblio.reqBibliographieFormate ().c_str ());
}


void
BibliographieInterface::supprimerReference ()
{
  SupprimerReferenceInterface reference;
  if (reference.exec ())
    {
      supprimer (reference.reqID ().toStdString ());
    }
  widget.affichage->setText (m_biblio.reqBibliographieFormate ().c_str ());
}


void
BibliographieInterface::ajouterReferenceJournal (const std::string& p_auteurs,
                                                 const std::string& p_nom,
                                                 int p_annee,
                                                 const std::string& p_identifiant,
                                                 int p_volume,
                                                 int p_numero,
                                                 int p_page
                                                 )
{


  Journal j (p_auteurs, p_nom, p_annee, p_identifiant, p_volume, p_numero, p_page);
  m_biblio.ajouterReference (j);
}


void
BibliographieInterface::ajouterReferenceOuvrage (const std::string& p_auteurs,
                                                 const std::string& p_titre,
                                                 int p_annee,
                                                 const std::string& p_identifiant,
                                                 const std::string& p_editeur,
                                                 const std::string& p_ville
                                                 )
{
  Ouvrage o (p_auteurs, p_titre, p_annee, p_identifiant, p_editeur, p_ville);
  m_biblio.ajouterReference (o);
}


void
BibliographieInterface::supprimer (const std::string& p_identifiant)
{
  m_biblio.supprimerReference (p_identifiant);
}
