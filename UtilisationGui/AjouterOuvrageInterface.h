/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterOuvrageInterface.h
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 16:01
 */

#ifndef _AJOUTEROUVRAGEINTERFACE_H
#define _AJOUTEROUVRAGEINTERFACE_H

#include "ui_AjouterOuvrageInterface.h"

class AjouterOuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  AjouterOuvrageInterface ();
  virtual ~AjouterOuvrageInterface ();
  QString reqAutheurs () const;
  QString reqTitre () const;
  QString reqID () const;
  QString reqEditeur () const;
  QString reqVille () const;
  int reqAnnee () const;
private slots:
  void validation ();
private:
  Ui::AjouterOuvrageInterface widget;
};

#endif /* _AJOUTEROUVRAGEINTERFACE_H */
