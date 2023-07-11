//!
//! \class Bibliographie
//! \brief La classe bibliographie permet d'implementer le concept d'un bibliographie
//! \date Created on 19 novembre 2021, 14:48
//!

#include "Bibliographie.h"
#include <string>
#include <sstream>
#include <iostream>



using namespace std;
using namespace util;

namespace biblio
{
  // Constructeurs

  //!
  //! \brief            Constructeur avec paramètre
  //! \param[in] p_nom  Le nom de l'auteur
  //! \post m_nom       prend la valeur de p_nom
  //! \return Un objet bibliographie
  //!


  Bibliographie::Bibliographie (const std::string& p_nom) : m_nom (p_nom)
  {
    PRECONDITION (!p_nom.empty ())

    POSTCONDITION (m_nom == p_nom);

    INVARIANTS ();
  }


  // Destructeur

  //!
  //! \brief désalloue tous les pointeur de références d'une bibliographie dans le vecteur
  //!


  Bibliographie::~Bibliographie ()
  {
    vector<Reference*>::iterator iter;
    for (iter = m_vReferences.begin (); iter !=  m_vReferences.end (); iter++)
      {
        delete(*iter);
      }
  }
  // Getteur & Setteur

  //!
  //! \brief   assesseur de m_nom
  //! \return m_nom
  //!


  const string&
  Bibliographie::reqNom ()const
  {
    return m_nom;
  }

  //!
  //! \brief   assesseur de m_vReferences
  //! \return m_vReferences
  //!


  const std::vector<Reference*>&
  Bibliographie::reqVReferences ()const
  {
    return m_vReferences;
  }

  //Méthodes

  //!
  //! \brief verifie si la bibliographie a déjà une référence
  //! \return boolean true si la réference est déjà presente dans la bibliographie false sinon
  //!


  bool
  Bibliographie::referenceEstDejaPresente (const Reference& p_reference) const
  {
    vector<Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin (); iter !=  m_vReferences.end (); iter++)
      {
        Reference& ref = **iter;
        if (ref.operator == (p_reference))
          {
            return true;
          }
      }
    return false;
  }

  //!
  //! \brief permet d’ajouter une référence au vecteur des références
  //!


  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {
    try
      {
        if (!referenceEstDejaPresente (p_nouvelleReference))
          {
            m_vReferences.push_back (p_nouvelleReference.clone ());
          }
        else
          {
            ostringstream ost;
            ost << "La référence : " << p_nouvelleReference.reqReferenceFormate () << " est déja prensente" << endl;
            throw ReferenceDejaPresenteException (ost.str ());
          }
      }
    catch (exception& e)
      {
        cout << e.what () << endl;
      }

  }

  //!
  //! \brief permet de supprimer une référence au vecteur des références
  //!


  void
  Bibliographie::supprimerReference (const string& p_identifiant)
  {
    try
      {
        vector<Reference*>::const_iterator iter;
        bool refPresente = false;
        for (iter = m_vReferences.begin (); iter !=  m_vReferences.end (); )
          {
            Reference& ref = **iter;
            if (ref.reqIdentifiant () == (p_identifiant))
              {
                refPresente = true;
                delete * iter;
                iter = m_vReferences.erase (iter);
              }
            else
              {
                iter++;
              }
          }
        if (!refPresente)
          {
            ostringstream ost;
            ost << "l'identifiant : " << p_identifiant << " est absent." << endl;
            throw ReferenceAbsenteException (ost.str ());
          }
      }
    catch (exception& e)
      {
        cout << e.what () << endl;
      }

  }

  //!
  //! \brief formate l'objet courant en chaîne de caractères
  //! \return la bibliographie formaté en chaîne de caractères.
  //!


  std::string
  Bibliographie::reqBibliographieFormate ()const
  {
    ostringstream ost;
    vector<Reference*>::const_iterator iter;
    int i = 0;
    ost << m_nom << endl
            << "===============================" << endl;
    for (iter = m_vReferences.begin (); iter !=  m_vReferences.end (); iter++)
      {
        Reference& ref = **iter;
        i++;
        ost << "[" << i << "] " << ref.reqReferenceFormate () << endl;
      }
    return ost.str ();

  }

  //!
  //! \brief verifie les invariants
  //!


  void
  Bibliographie::verifieInvariant () const
  {
    INVARIANT (!m_nom.empty ());
  }

  //Opérateur d'assignation


  const Bibliographie& Bibliographie::operator= (const Bibliographie& p_biblio)
  {
    m_nom = p_biblio.reqNom ();
    m_vReferences = p_biblio.reqVReferences ();
    return *this;
  }
}