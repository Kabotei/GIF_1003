/**
 * \file   ReferenceDejaPresenteException.h
 * \brief  Fichier contenant la déclaration de la classe ReferenceDejaPresenteException et de ses héritiers
 * \author etudiant
 * \date 2 décembre 2021, 18:27
 */

#ifndef REFERENCEDEJAPRESENTEEXCEPTION_H
#define REFERENCEDEJAPRESENTEEXCEPTION_H

#include "ReferenceException.h"
#include <string>

/**
 * \class ReferenceDejaPresenteException
 * \brief Classe fille des exceptions de Reference deja presente.
 */
class ReferenceDejaPresenteException : public ReferenceException
{
public:
  ReferenceDejaPresenteException (const std::string& p_raison);
private:

};

#endif /* REFERENCEDEJAPRESENTEEXCEPTION_H */

