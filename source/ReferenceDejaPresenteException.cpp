/**
 * \file   ReferenceDejaPresenteException.cpp
 * \brief  Fichier contenant la déclaration de la classe ReferenceDejaPresenteException et de ses héritiers
 * \author etudiant
 * \date 2 décembre 2021, 18:27
 */

#include "ReferenceDejaPresenteException.h"


/**
 * \brief Constructeur de la classe de base ReferenceDejaPresenteException
 * \param p_raison chaîne de caractères raison pour laquelle l'exception a lieu
 */
ReferenceDejaPresenteException::ReferenceDejaPresenteException (const std::string& p_raison) : ReferenceException::ReferenceException (p_raison) { }

