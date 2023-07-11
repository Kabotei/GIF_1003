//!
//! \class Ouvrage
//! \brief Header de la classe Ouvrage
//! \date Created on 19 novembre 2021, 11:47
//!

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include "Reference.h"
#include "validationFormat.h"
#include "ContratException.h"
namespace biblio
{

  class Ouvrage : public Reference
  {
  public:
    //Constructeur
    Ouvrage (const std::string& p_auteurs,
             const std::string& p_titre,
             int p_annee,
             const std::string& p_identifiant,
             const std::string& p_editeur,
             const std::string& p_ville
             );

    //Getteur & Setteur
    const std::string& reqEditeur ()const;
    const std::string& reqVille ()const;

    //Méthodes
    std::string reqReferenceFormate ()const;
    virtual Reference* clone () const;

  private:
    //Attribut
    std::string m_editeur;
    std::string m_ville;

    //Méthodes
    void verifieInvariant () const;
  };
}
#endif /* OUVRAGE_H */

