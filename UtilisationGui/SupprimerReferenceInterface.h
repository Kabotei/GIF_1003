/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SupprimerReferenceInterface.h
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 15:50
 */

#ifndef _SUPPRIMERREFERENCEINTERFACE_H
#define _SUPPRIMERREFERENCEINTERFACE_H

#include "ui_SupprimerReferenceInterface.h"

class SupprimerReferenceInterface : public QDialog
{
  Q_OBJECT
public:
  SupprimerReferenceInterface ();
  virtual ~SupprimerReferenceInterface ();
  QString reqID () const;
private slots:
  void validation ();
private:
  Ui::SupprimerReferenceInterface widget;
};

#endif /* _SUPPRIMERREFERENCEINTERFACE_H */
