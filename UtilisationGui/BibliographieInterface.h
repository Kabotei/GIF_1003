/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BibliographieInterface.h
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 14:43
 */

#ifndef _BIBLIOGRAPHIEINTERFACE_H
#define _BIBLIOGRAPHIEINTERFACE_H

#include "ui_BibliographieInterface.h"
#include "Bibliographie.h"
#include "Reference.h"
#include <string>

class BibliographieInterface : public QMainWindow
{
  Q_OBJECT
public:
  BibliographieInterface ();
  virtual ~BibliographieInterface ();
  void ajouterReferenceJournal (const std::string& p_auteurs,
                                const std::string& p_nom,
                                int p_annee,
                                const std::string& p_identifiant,
                                int p_volume,
                                int p_numero,
                                int p_page
                                );
  void ajouterReferenceOuvrage (const std::string& p_auteurs,
                                const std::string& p_titre,
                                int p_annee,
                                const std::string& p_identifiant,
                                const std::string& p_editeur,
                                const std::string& p_ville
                                );

  void supprimer (const std::string& p_identifiant);
private slots:
  void ajouterJournal ();
  void ajouterOuvrage ();
  void supprimerReference ();
private:
  Ui::BibliographieInterface widget;
  biblio::Bibliographie m_biblio;
};

#endif /* _BIBLIOGRAPHIEINTERFACE_H */
