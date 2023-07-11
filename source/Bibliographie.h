//!
//! \class Bibliographie
//! \brief Header de la classe Bibliographie
//! \date Created on 19 novembre 2021, 14:48
//!


#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include "Reference.h"
#include "ContratException.h"
#include "ReferenceAbsenteException.h"
#include "ReferenceDejaPresenteException.h"
#include <vector>
namespace biblio
{

  class Bibliographie
  {
  public:
    //Constructeur
    Bibliographie (const std::string& p_nom);

    //Destructeur
    ~Bibliographie ();

    //Getteur & Setteur
    const std::string& reqNom ()const;
    const std::vector<Reference*>& reqVReferences ()const;

    //Méthodes
    void ajouterReference (const Reference& p_nouvelleReference);
    void supprimerReference (const std::string& p_identifiant);
    std::string reqBibliographieFormate ()const;

    //Constructeur de copie
    Bibliographie (const Bibliographie& p_biblio);
  private:


    //Opérateur d'assignation
    const Bibliographie& operator= (const Bibliographie& p_biblio);

    //Attribut
    std::string m_nom;
    std::vector<Reference*> m_vReferences;

    //Méthodes
    bool referenceEstDejaPresente (const Reference& p_reference) const;
    void verifieInvariant () const;

  };
}
#endif /* BIBLIOGRAPHIE_H */
