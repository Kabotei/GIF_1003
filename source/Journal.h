//!
//! \class Journal
//! \author Léo BACKERT
//! \brief Header de la classe Journal
//! \date Created on 19 novembre 2021, 13:20
//!


#ifndef JOURNAL_H
#define JOURNAL_H

#include "Reference.h"
#include "validationFormat.h"
#include "ContratException.h"

namespace biblio
{

  class Journal : public Reference
  {
  public:
    //Constructeur
    Journal (const std::string& p_auteurs,
             const std::string& p_nom,
             int p_annee,
             const std::string& p_identifiant,
             int p_volume,
             int p_numero,
             int p_page
             );

    //Getteur & Setteur
    const std::string& reqNom ()const;
    int reqVolume ()const;
    int reqNumero ()const;
    int reqPage ()const;

    //Méthodes
    std::string reqReferenceFormate ()const;
    virtual Reference* clone () const;

  private:
    //Attribut
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;

    //Méthodes
    void verifieInvariant () const;
  };
}
#endif /* JOURNAL_H */
