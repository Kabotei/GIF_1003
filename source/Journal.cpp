//!
//! \class Journal
//! \author Léo BACKERT
//! \brief La classe journal permet d'implementer le concept d'un journal
//! \date Created on 19 novembre 2021, 13 : 20
//!

#include "Journal.h"
#include "Reference.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using namespace util;

namespace biblio
{
  //!
  //! \brief                    Constructeur avec paramètre
  //! \param[in] p_auteurs      Le nom de l'auteur
  //! \param[in] p_titre        Le titre du livre
  //! \param[in] p_annee        L'année d'édition de la références
  //! \parma[in] p_identifiant  Code ISSN ou ISBN
  //! \param[in] p_nom          Le nom du journal
  //! \param[in] p_volume       Le volume du journal
  //! \param[in] p_numero       Le numero du journal
  //! \parma[in] p_page         Le numero de page où commence la référence publiée dans le journal
  //! \pre p_nom                doit être non vide
  //! \pre p_identifiant        doit suivre le format d'un code ISSN
  //! \post m_nom               prend la valeur de p_nom
  //! \post m_volume            prend la valeur de p_volume
  //! \post m_numero            prend la valeur de p_numero
  //! \post m_page              prend la valeur de p_page
  //! \post m_identifiant       prend la valeur de p_identifiant
  //! \return Un objet ouvrage
  //!


  Journal::Journal (const std::string& p_auteurs,
                    const std::string& p_nom,
                    int p_annee,
                    const std::string& p_identifiant,
                    int p_volume,
                    int p_numero,
                    int p_page
                    )
  : Reference (p_auteurs, p_nom, p_annee, p_identifiant),
  m_volume (p_volume),
  m_numero (p_numero),
  m_page (p_page)
  {
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (validerCodeIssn (p_identifiant));

    POSTCONDITION (m_volume == p_volume);
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == p_page);
    POSTCONDITION (Reference::reqIdentifiant () == p_identifiant);

    INVARIANTS ();
  }

  // Getteur & Setteur



  //!
  //! \brief   assesseur de m_nom
  //! \return m_auteur
  //!


  const string&
  Journal::reqNom ()const
  {
    return reqTitre ();
  }

  //!
  //! \brief   assesseur de m_volume
  //! \return m_volume
  //!


  int
  Journal::reqVolume ()const
  {
    return m_volume;
  }

  //!
  //! \brief   assesseur de m_numero
  //! \return m_numero
  //!


  int
  Journal::reqNumero ()const
  {
    return m_numero;
  }

  //!
  //! \brief   assesseur de m_page
  //! \return m_page
  //!


  int
  Journal::reqPage ()const
  {
    return m_page;
  }

  //Méthodes

  //!
  //! \brief formate l'objet courant en chaîne de caractères
  //! \return le journal formaté en chaîne de caractères.
  //!


  string
  Journal::reqReferenceFormate () const
  {
    ostringstream ost;
    ost << this->reqAuteur () << ". " << this->reqTitre () << ". "
            << "vol. " << m_volume << ", "
            << "no. " << m_numero << ", "
            << "pp. " << m_page << ", "
            << Reference::reqAnnee () << ". "
            << Reference::reqIdentifiant () << ".";
    return ost.str ();
  }



  //!
  //! \brief verifie les invariants
  //!


  void
  Journal::verifieInvariant () const
  {
    INVARIANT (!m_nom.empty ());
    INVARIANT (validerCodeIssn (Reference::reqIdentifiant ()));
  }


  //!
  //! \brief Clone un ouvrage
  //! \return Une copie de l'objet courant
  //!


  Reference*
  Journal::clone () const
  {
    return new Journal (*this); // Appel du constructeur copie
  }
}

