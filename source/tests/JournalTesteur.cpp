#include <gtest/gtest.h>
#include "Journal.h"
#include "ContratException.h"
#include <sstream>

using namespace std;
using namespace util;
using namespace biblio;

//Constructeur


TEST (Journal, ConstructeurValide)
{
  Journal unJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", 24, 6, 13);
  ASSERT_EQ ("Hart", unJournal.reqAuteur ());
  ASSERT_EQ ("A survey of source code management tools for programming courses", unJournal.reqNom ());
  ASSERT_EQ (2009, unJournal.reqAnnee ());
  ASSERT_EQ ("ISSN 1937-4771", unJournal.reqIdentifiant ());
  ASSERT_EQ (24, unJournal.reqVolume ());
  ASSERT_EQ (6, unJournal.reqNumero ());
  ASSERT_EQ (13, unJournal.reqPage ());
}


TEST (Journal, ConstructeurAuteurInvalide)
{


  ASSERT_THROW (Journal unJournal ("12", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", 24, 6, 13), ContratException) << "Un auteur doit suivre le format de nom";
}


TEST (Journal, ConstructeurNomInvalide)
{


  ASSERT_THROW (Journal unJournal ("Hart", "", 2009, "ISSN 1937-4771", 24, 6, 13), ContratException) << "Un nom ne doit pas être vide";
}


TEST (Journal, ConstructeurAnneeInvalide)
{


  ASSERT_THROW (Journal unJournal ("Hart", "A survey of source code management tools for programming courses", 0, "ISSN 1937-4771", 24, 6, 13), ContratException) << "Une année doit être strictement positive";
}


TEST (Journal, ConstructeurIdentifiantInvalide)
{


  ASSERT_THROW (Journal unJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "1937-4771", 24, 6, 13), ContratException) << "Le code ISSN est invalide";
}

class JournalValide : public ::testing::Test
{

public:


  JournalValide () : journalV ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", 24, 6, 13) { }


  Journal journalV;
} ;

//Getteur setteur


TEST_F (JournalValide, reqNom)
{
  ASSERT_EQ ("A survey of source code management tools for programming courses", journalV.reqNom ());
}


TEST_F (JournalValide, reqVolume)
{
  ASSERT_EQ (24, journalV.reqVolume ());
}


TEST_F (JournalValide, reqNumero)
{
  ASSERT_EQ (6, journalV.reqNumero ());
}


TEST_F (JournalValide, reqPage)
{


  ASSERT_EQ (13, journalV.reqPage ());
}


// Méthodes


TEST_F (JournalValide, reqReferenceFormate)
{
  ostringstream ost;
  ost << journalV.reqAuteur () << ". " << journalV.reqTitre () << ". "
          << journalV.reqNom () << ", "
          << "vol. " << journalV.reqVolume () << ", "
          << "no. " << journalV.reqNumero () << ", "
          << "pp. " << journalV.reqPage () << ", "
          << journalV.reqAnnee () << ". "
          << journalV.reqIdentifiant () << ".";
  ASSERT_EQ (ost.str (), journalV.reqReferenceFormate ());
}