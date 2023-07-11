#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
#include <sstream>
#include <gtest/gtest.h>

using namespace std;
using namespace util;
using namespace biblio;

//Constructeur


/* TODO
 *
 * Modifier les testeurs pour ajouter ReferenceTesteur (Optional car non évaluer)
 *
 */

TEST (Bibliographie, ConstructeurValide)
{
  Bibliographie uneBibliographie ("Bibliographie");
  ASSERT_EQ ("Bibliographie", uneBibliographie.reqNom ());

}


TEST (Journal, ConstructeurNomInvalide)
{
  ASSERT_THROW (Bibliographie uneBibliographie (""), ContratException) << "Un nom ne dois pas être vide";
}

class BibliographieValide : public ::testing::Test
{

public:


  BibliographieValide () : bibliographieV ("Bibliographie") { }


  Bibliographie bibliographieV;
} ;

//Getteur setteur


TEST_F (BibliographieValide, reqNom)
{
  ASSERT_EQ ("Bibliographie", bibliographieV.reqNom ());
}


TEST_F (BibliographieValide, reqVReferences)
{
  std::vector<Reference*> vReferences;
  ASSERT_EQ (vReferences, bibliographieV.reqVReferences ());
}


// Méthodes


TEST_F (BibliographieValide, reqBibliographieFormate)
{
  ostringstream ost;
  ost << bibliographieV.reqNom () << endl
          << "===============================" << endl;
  for (int i = 0; i < bibliographieV.reqVReferences ().size (); i++)
    {
      ost << "[" << i << "] " << bibliographieV.reqVReferences ()[i]->reqReferenceFormate () << endl;
    }
  ASSERT_EQ (ost.str (), bibliographieV.reqBibliographieFormate ());
}


TEST_F (BibliographieValide, ajouterReference)
{
  Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  bibliographieV.ajouterReference (unOuvrage);
  ASSERT_EQ (bibliographieV.reqVReferences ().size (), 1);
}


TEST_F (BibliographieValide, ajouterReferenceDejaPresente)
{
  Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  bibliographieV.ajouterReference (unOuvrage);
  ASSERT_THROW (bibliographieV.ajouterReference (unOuvrage), ReferenceDejaPresenteException) << "On ne peut pas ajouter une réference déja présente";
}


TEST_F (BibliographieValide, supprimerReference)
{
  Ouvrage unOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  bibliographieV.ajouterReference (unOuvrage);
  bibliographieV.supprimerReference ("ISBN 978-0-387-77591-3");
  ASSERT_EQ (bibliographieV.reqVReferences ().size (), 0);
}


TEST_F (BibliographieValide, supprimerReferenceAbsente)
{
  ASSERT_THROW (bibliographieV.supprimerReference ("ISBN 978-0-387-77591-3"), ReferenceAbsenteException) << "On ne peut pas supprimer une réference absente";
}