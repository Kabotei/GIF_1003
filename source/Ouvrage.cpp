//!
//! \class Ouvrage
//! \author Léo BACKERT
//! \brief La classe ouvrage permet d'implementer le concept d'un ouvrage
//! \date Created on 19 novembre 2021, 11:47
//!
#include "Ouvrage.h"
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
  //! \param[in] p_editeur      Le nom de l'éditeur
  //! \param[in] p_ville        Le nom de la ville d'edition
  //! \pre p_editeur            doit suivre le format nom
  //! \pre p_ville              doit suivre le format nom
  //! \pre p_identifiant        doit suivre le format d'un code ISBN
  //! \post m_editeur           prend la valeur de p_editeur
  //! \post m_ville             prend la valeur de p_ville
  //! \post m_identifiant       prend la valeur de p_identifiant
  //! \return Un objet ouvrage
  //!


  Ouvrage::Ouvrage (const std::string& p_auteurs,
                    const std::string& p_titre,
                    int p_annee,
                    const std::string& p_identifiant,
                    const std::string& p_editeur,
                    const std::string& p_ville)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_editeur (p_editeur),
  m_ville (p_ville)
  {
    PRECONDITION (validerFormatNom (p_editeur));
    PRECONDITION (validerFormatNom (p_ville));
    PRECONDITION (validerCodeIsbn (p_identifiant));

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);
    POSTCONDITION (Reference::reqIdentifiant () == p_identifiant);

    INVARIANTS ();
  }

  // Getteur & Setteur



  //!
  //! \brief   assesseur de m_editeur
  //! \return m_auteur
  //!


  const string&
  Ouvrage::reqEditeur ()const
  {
    return m_editeur;
  }

  //!
  //! \brief   assesseur de m_ville
  //! \return m_ville
  //!


  const string&
  Ouvrage::reqVille ()const
  {
    return m_ville;
  }

  //Méthodes

  //!
  //! \brief formate l'objet courant en chaîne de caractères
  //! \return l'ouvrage formaté en chaîne de caractères.
  //!


  string
  Ouvrage::reqReferenceFormate () const
  {
    ostringstream ost;
    ost << this->reqAuteur () << ". " << this->reqTitre () << ". "
            << m_ville << " : "
            << m_editeur << ", "
            << this->reqAnnee () << ". "
            << this->reqIdentifiant () << ".";
    return ost.str ();
  }



  //!
  //! \brief verifie les invariants
  //!


  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (validerFormatNom (m_editeur));
    INVARIANT (validerFormatNom (m_ville));
    INVARIANT (validerCodeIsbn (Reference::reqIdentifiant ()));
  }


  //!
  //! \brief Clone un ouvrage
  //! \return Une copie de l'objet courant
  //!


  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this); // Appel du constructeur copie
  }

}