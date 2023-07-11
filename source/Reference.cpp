//!
//! \class Reference
//! \author Léo BACKERT
//! \brief La classe réference permet
//!        d'implementer le concept de référence d'un livre
//! \date 17 octobre 2021, 21:20
//!

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
  //! \pre p_auteurs            doit suivre le format nom
  //! \pre p_titre              doit etre nom vide
  //! \pre p_annee              doit etre supérieur a 0
  //! \pre p_identifiant        doit être conforme a un ISSN ou a un ISBN
  //! \post m_auteurs           prend la valeur de p_auteurs
  //! \post m_titre             prend la valeur de p_titre
  //! \post m_annee             prend la valeur de p_annee
  //! \post m_identifiant       prend la valeur de p_identifiant
  //! \return Un objet référence
  //!


  Reference::Reference (const std::string& p_auteurs,
                        const std::string& p_titre,
                        int p_annee,
                        const std::string& p_identifiant)
  : m_auteurs (p_auteurs),
  m_titre (p_titre),
  m_annee (p_annee),
  m_identifiant (p_identifiant)
  {
    PRECONDITION (validerFormatNom (p_auteurs));
    PRECONDITION (!p_titre.empty ());
    PRECONDITION (p_annee > 0);


    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);

    INVARIANTS ();
  }

  // Getteur & Setteur



  //!
  //! \brief   assesseur de m_auteurs
  //! \return m_auteur
  //!


  const string&
  Reference::reqAuteur ()const
  {
    return m_auteurs;
  }

  //!
  //! \brief   assesseur de m_titre
  //! \return m_titre
  //!


  const string&
  Reference::reqTitre ()const
  {
    return m_titre;
  }

  //!
  //! \brief   assesseur de m_annee
  //! \return m_annee
  //!


  int
  Reference::reqAnnee ()const
  {
    return m_annee;
  }

  //!
  //! \brief   assesseur de m_identifiant
  //! \return m_identifiant
  //!


  const string&
  Reference::reqIdentifiant ()const
  {
    return m_identifiant;
  }

  //!
  //! \brief mutateur de m_annee
  //! \param[in] assigne à m_annee un annee conforme au cahier des charges.
  //! \pre p_annee strictement supérieur a 0
  //! \post m_annee prend la valeur de p_annee
  //!


  void
  Reference::asgAnnee (int p_annee)
  {
    PRECONDITION (p_annee > 0);
    m_annee = p_annee;
    POSTCONDITION (m_annee == p_annee);
    INVARIANTS ();
  }

  //Méthodes

  //!
  //! \brief formate l'objet courant en chaîne de caractères
  //! \return la référence formater en chaîne de caractères.
  //!


  string
  Reference::reqReferenceFormate () const
  {
    return "";
  }

  //!
  //! \brief vérifie l'égalité de 2 objets sur tous leurs attributs.
  //! \param[in] une instance de référence.
  //! \return booléen.
  //!


  bool Reference::operator== (const Reference& p_ref) const
  {
    bool estEgal = true;
    estEgal = estEgal and m_auteurs == p_ref.reqAuteur ();
    estEgal = estEgal and m_titre == p_ref.reqTitre ();
    estEgal = estEgal and m_annee == p_ref.reqAnnee ();
    estEgal = estEgal and m_identifiant == p_ref.reqIdentifiant ();

    return estEgal;
  }

  //!
  //! \brief verifie les invariants
  //!


  void
  Reference::verifieInvariant () const
  {
    INVARIANT (validerFormatNom (m_auteurs));
    INVARIANT (!m_titre.empty ());
    INVARIANT (m_annee > 0);
  }

}

