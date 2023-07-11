/**
 * \file   ReferenceAbsenteException.cpp
 * \brief  Fichier contenant la déclaration de la classe ReferenceAbsenteException et de ses héritiers
 * \author etudiant
 * \date 2 décembre 2021, 18:37
 */

#include "ReferenceAbsenteException.h"


/**
 * \brief Constructeur de la classe de base ReferenceAbsenteException
 * \param p_raison chaîne de caractères raison pour laquelle l'exception a lieu
 */
ReferenceAbsenteException::ReferenceAbsenteException (const std::string& p_raison) : ReferenceException::ReferenceException (p_raison) { }


