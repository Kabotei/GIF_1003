/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "validationFormat.h"

using namespace std;

namespace util
{


  bool
  validerFormatNom (const std::string& p_nom)
  {
    /*
     * Description :
     *
     * Cette fonction valide le format d’un nom.
     * Un nom ne doit être composé que de lettres, mais les espaces et
     * les tirets ‘-‘ sont permis s’ils ne sont pas doublés;
     * deux (ou plus) espaces ou ‘-‘ consécutifs;
     * un tiret ne pouvant pas être suivi d’un espace et inversement.
     *
     *Entrée : pointeur sur un string : p_nom
     *Sortie : bool
     *
     *
     */

    // Initialisation des variables
    const string CHAR_VALIDE = "AZERTYUIOPQSDFGHJKLMWXCVBNazertyuiopqsdfghjklmwxcvbn -";
    bool espace = false;

    // Test de validité du nom
    for (int i = 0; i < p_nom.size (); i++)
      {
        // Test sur l'appartenance au caractère autorisée
        if (CHAR_VALIDE.find (p_nom[i]) > CHAR_VALIDE.size ())
          {
            return false;
          }
          // Test sur la consécutivité des caractère exceptionnel
        else if (espace and (p_nom[i] == ' ' or p_nom[i] == '-'))
          {
            return false;
          }
          // Test sur les caractères exceptionnel
        else if (p_nom[i] == ' ' or p_nom[i] == '-')
          {
            espace = true;
          }
          // Ici le caractère appartient à l'alphabet latin moderne
        else
          {
            espace = false;
          }
      }
    return true;
  }


  bool
  validerCodeIssn (const std::string& p_issn)
  {
    /*
     * Description :
     *
     * Cette fonction valide le code ISSN
     *
     *Entrée : pointeur sur un string : p_issn
     *Sortie : bool
     *
     */
    //Initialisation des variables
    const string PARTIE1 = "ISSN ";
    const unsigned int ponderation = 8;
    string partie1 = "";
    string partie2 = "";
    string partie3 = "";
    int somme = 0;
    int dernierChiffre = 0;

    //premier test
    if (p_issn.size () != 14)
      {
        return false;
      }
    //Séparation du code
    for (int i = 0; i < p_issn.size (); i++)
      {
        if (i <= 4)
          {
            partie1 += p_issn[i];
          }
        else if (i == 9)
          {
            partie2 += p_issn[i];
          }
        else
          {
            partie3 += p_issn[i];
          }
      }

    //***Test de validité du code
    //Test de la partie "ISSN "
    if (PARTIE1 != partie1)
      {
        return false;
      }
    //Test du séparateur '-'
    if (partie2 != "-")
      {
        return false;
      }
    //**Test des chiffres
    //Vérification des caracrères
    for (int i = 0; i < partie3.size () - 1; i++)
      {
        if (partie3[i] < '0' or partie3[i] > '9')
          {
            return false;
          }
      }
    //Vérification du dernier chiffre
    for (int i = 0; i < partie3.size () - 1; i++)
      {
        somme += (ponderation - i) * ((int) partie3[i] - '0');
      }
    dernierChiffre = 11 - somme % 11;
    switch (dernierChiffre)
      {
        case 11:
          if (partie3[7] != '0')
            {
              return false;
            }
          break;
        case 10:
          if (partie3[7] != 'X')
            {
              return false;
            }
          break;
        default:
          if ((int) (partie3[7] - '0') != dernierChiffre)
            {
              return false;
            }

      }
    return true;
  }


  bool
  validerCodeIsbn (const std::string& p_isbn)
  {
    /*
     * Description :
     *
     * Cette fonction valide le code ISBN
     *
     *Entrée : pointeur sur un string : p_isbn
     *Sortie : bool
     *
     */

    //Initialisation des variables
    const string PREFIXE = "ISBN ";
    const string ponderation = "131313131313";
    string prefixe = ""; // va contenir "ISBN "
    string separateur = ""; // va contenir les "-"
    string codeLivre = ""; // va contenir le numero de la catégorie du produit
    string domaine = ""; // va contenir le numero du domaine
    string editeur = ""; // va contenir le numéro de l'editeur
    string ouvrage = ""; // va contenir le numéro de l'ouvrage
    string cleDeControle = ""; // va contenir la clé de controle
    string codeIsbn13 = "";
    int somme = 0;
    int dernierChiffre = 0;
    int domaineEntier = 0;
    int editeurEntier = 0;

    //Controle de la taille
    if (p_isbn.size () != 22)
      {
        return false;
      }

    //Séparation du code
    for (int i = 0; i < p_isbn.size () - 1; i++)
      {
        if (i <= 4)
          {
            prefixe += p_isbn[i];
          }
        else if (p_isbn[i] == '-')
          {
            separateur += p_isbn[i];
          }
        else if (i < 8)
          {
            codeLivre += p_isbn[i];
          }
        else if (separateur.size () == 1)
          {
            domaine += p_isbn[i];
          }
        else if (separateur.size () == 2)
          {
            editeur += p_isbn[i];
          }
        else
          {
            ouvrage += p_isbn[i];
          }
      }
    cleDeControle += p_isbn[p_isbn.size () - 1];

    //***Test de validité du code ISBN-13
    //Controle des caractère:
    codeIsbn13 = codeLivre + domaine + editeur + ouvrage;
    for (int i = 0; i < codeIsbn13.size (); i++)
      {
        if (codeIsbn13[i] < '0' or codeIsbn13[i] > '9')
          {
            return false;
          }
      }

    //Test de la partie "ISSN "
    if (PREFIXE != prefixe)
      {
        return false;
      }

    //Test du séparateur '-'
    if (separateur != "----")
      {
        return false;
      }

    //controle de la code Livre
    if (codeLivre != "978" and codeLivre != "979")
      {
        return false;
      }

    //controle de la domaine
    domaineEntier = stoi (domaine);
    switch (domaine.size ())
      {
        case(1):
          if (domaine[0] > '5' and domaine[0] != '7')
            {
              return false;
            }
          break;
        case(2):
          if (domaineEntier < 80 or domaineEntier > 94)
            {
              return false;
            }
          break;
        case(3):
          if (domaineEntier < 600 or (domaineEntier > 649 and domaineEntier < 950) or domaineEntier > 989)
            {
              return false;
            }
          break;
        case(4):
          if (domaineEntier < 9900 or domaineEntier > 9989)
            {
              return false;
            }
          break;
        case(5):
          if (domaineEntier < 99900)
            {
              return false;
            }
          break;
        default:
          return false;
      }

    //controle de l'éditeur
    editeurEntier = stoi (editeur);
    switch (editeur.size ())
      {
        case(1):
          break;
        case(2):
          if (editeurEntier > 19)
            {
              return false;
            }
          break;
        case(3):
          if (editeurEntier < 200 or editeurEntier > 699)
            {
              return false;
            }
          break;
        case(4):
          if (editeurEntier < 7000 or editeurEntier > 8499)
            {
              return false;
            }
          break;
        case(5):
          if (editeurEntier < 85000 or editeurEntier > 89999)
            {
              return false;
            }
          break;
        case(6):
          if (editeurEntier < 900000 or editeurEntier > 949999)
            {
              return false;
            }
          break;
        case(7):
          if (editeurEntier < 9500000)
            {
              return false;
            }
          break;
        default:
          return false;
      }

    //Controle de la clé de controle
    for (int i = 0; i < ponderation.size (); i++)
      {
        somme += ((int) ponderation[i] - '0')*((int) (codeIsbn13[i]) - '0');
      }
    dernierChiffre = 10 - somme % 10;
    if (dernierChiffre != (int) cleDeControle[0] - '0')
      {
        return false;
      }

    return true;
  }

}