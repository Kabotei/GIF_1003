//!
//! \class Reference
//! \brief Header de la classe Références
//! \date 17 octobre 2021, 21:20
//!

#ifndef REFERENCE_H
#define REFERENCE_H

#include "validationFormat.h"
#include "ContratException.h"
namespace biblio
{

  class Reference
  {
  public:
    //Constructeur
    Reference (const std::string& p_auteurs,
               const std::string& p_titre,
               int p_annee,
               const std::string& p_identifiant);

    //Destructeur

    virtual
    ~Reference () { };

    //Getteur & Setteur
    const std::string& reqAuteur ()const;
    const std::string& reqTitre ()const;
    int reqAnnee ()const;
    const std::string& reqIdentifiant ()const;

    void asgAnnee (int p_annee);

    //Méthodes
    virtual std::string reqReferenceFormate () const = 0;
    virtual Reference* clone () const = 0;
    bool operator== (const Reference& p_ref) const;

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
    void verifieInvariant () const;
  };
}

#endif /* REFERENCE_H */

