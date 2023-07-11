/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterJournalInterface.h
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 16:00
 */

#ifndef _AJOUTERJOURNALINTERFACE_H
#define _AJOUTERJOURNALINTERFACE_H

#include "ui_AjouterJournalInterface.h"

class AjouterJournalInterface : public QDialog
{
  Q_OBJECT
public:
  AjouterJournalInterface ();
  virtual ~AjouterJournalInterface ();

  QString reqAutheurs () const;
  QString reqNom () const;
  QString reqID () const;
  int reqAnnee () const;
  int reqVolume () const;
  int reqNumero () const;
  int reqPage () const;

private slots:
  void validation ();
private:
  Ui::AjouterJournalInterface widget;
};

#endif /* _AJOUTERJOURNALINTERFACE_H */
