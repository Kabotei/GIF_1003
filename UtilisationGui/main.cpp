/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 3 décembre 2021, 14:42
 */

#include <QApplication>
#include <BibliographieInterface.h>
#include "Bibliographie.h"


int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  BibliographieInterface fenetrePincipale;
  fenetrePincipale.show ();

  return app.exec ();
}
