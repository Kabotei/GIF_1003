#include <gtest/gtest.h>
#include "Ouvrage.h"
#include "ContratException.h"
#include <sstream>

using namespace std;
using namespace util;
using namespace biblio;

//Constructeur


TEST (Ouvrage, ConstructeurValide)
{
  Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  ASSERT_EQ ("Homayoon Beigi", unOuvrage.reqAuteur ());
  ASSERT_EQ ("Fundamentals of Speaker Recognition", unOuvrage.reqTitre ());
  ASSERT_EQ (2011, unOuvrage.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", unOuvrage.reqIdentifiant ());
  ASSERT_EQ ("Springer", unOuvrage.reqEditeur ());
  ASSERT_EQ ("New York", unOuvrage.reqVille ());
}


TEST (Ouvrage, ConstructeurAuteurInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("12", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York"), ContratException) << "Un auteur dois suivre le format de nom";
}


TEST (Ouvrage, ConstructeurTitreInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Homayoon Beigi", "", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York"), ContratException) << "Un titre ne dois pas être vide";
}


TEST (Ouvrage, ConstructeurAnneeInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 0, "ISBN 978-0-387-77591-3", "Springer", "New York"), ContratException) << "Une année doit être strictement positive";
}


TEST (Ouvrage, ConstructeurIdentifiantInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "978-0-387-77591-3", "Springer", "New York"), ContratException) << "Le code ISBN est invalide";
}


TEST (Ouvrage, ConstructeurEditeurInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "12", "New York"), ContratException) << "Le nom de l'editeur doit suivre le format nom";
}


TEST (Ouvrage, ConstructeurVilleInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "12"), ContratException) << "Le nom de la ville doit suivre le format nom";
}

class OuvrageValide : public ::testing::Test
{

public:


  OuvrageValide () : ouvrageV ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York") { }
  Ouvrage ouvrageV;
} ;

//Getteur setteur


TEST_F (OuvrageValide, reqAuteur)
{
  ASSERT_EQ ("Homayoon Beigi", ouvrageV.reqAuteur ());
}


TEST_F (OuvrageValide, reqTitre)
{
  ASSERT_EQ ("Fundamentals of Speaker Recognition", ouvrageV.reqTitre ());
}


TEST_F (OuvrageValide, reqAnnee)
{
  ASSERT_EQ (2011, ouvrageV.reqAnnee ());
}


TEST_F (OuvrageValide, reqIdentifiant)
{
  ASSERT_EQ ("ISBN 978-0-387-77591-3", ouvrageV.reqIdentifiant ());
}


TEST_F (OuvrageValide, reqEditeur)
{
  ASSERT_EQ ("Springer", ouvrageV.reqEditeur ());
}


TEST_F (OuvrageValide, reqVille)
{
  ASSERT_EQ ("New York", ouvrageV.reqVille ());
}


TEST_F (OuvrageValide, asgAnneeValide)
{
  ouvrageV.asgAnnee (5);
  ASSERT_EQ (5, ouvrageV.reqAnnee ());
}


TEST_F (OuvrageValide, asgAnneeInvalide)
{
  ASSERT_THROW (ouvrageV.asgAnnee (-5), ContratException) << "Une annee doit être strictement positive";
}

// Méthodes


TEST_F (OuvrageValide, reqReferenceFormate)
{
  ostringstream ost;
  ost << ouvrageV.reqAuteur () << ". " << ouvrageV.reqTitre () << ". "
          << ouvrageV.reqVille () << " : "
          << ouvrageV.reqEditeur () << ", "
          << ouvrageV.reqAnnee () << ". "
          << ouvrageV.reqIdentifiant () << ".";
  ASSERT_EQ (ost.str (), ouvrageV.reqReferenceFormate ());
}