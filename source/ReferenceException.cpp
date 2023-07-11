/**
 * \file   ReferenceException.cpp
 * \brief  Fichier contenant la déclaration de la classe ReferenceException et de ses héritiers
 * \author etudiant
 * \date 2 décembre 2021, 18:13
 */

#include "ReferenceException.h"

using namespace std;


/**
 * \brief Constructeur de la classe de base v
 * \param p_raison chaîne de caractères : raison pour laquelle l'exception a lieu
 */
ReferenceException::ReferenceException (const std::string& p_raison) : runtime_error (p_raison) { }

