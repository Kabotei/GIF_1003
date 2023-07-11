/**
 * \file   ReferenceAbsenteException.h
 * \brief  Fichier contenant la déclaration de la classe ReferenceAbsenteException et de ses héritiers
 * \author etudiant
 * \date 2 décembre 2021, 18:37
 */

#ifndef REFERENCEABSENTEEXCEPTION_H
#define REFERENCEABSENTEEXCEPTION_H

#include "ReferenceException.h"
#include <string>

/**
 * \class ReferenceAbsenteException
 * \brief Classe fille des exceptions de Reference absente.
 */
class ReferenceAbsenteException : public ReferenceException
{
public:
  ReferenceAbsenteException (const std::string& p_raison);
private:

};

#endif /* REFERENCEABSENTEEXCEPTION_H */

