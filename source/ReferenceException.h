/**
 * \file   ReferenceException.h
 * \brief  Fichier contenant la déclaration de la classe ReferenceException et de ses héritiers
 * \author etudiant
 * \date 2 décembre 2021, 18:13
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <string>
#include <stdexcept>

/**
 * \class ReferenceException
 * \brief Classe de base des exceptions de reference.
 */
class ReferenceException : public std::runtime_error
{
public:
  ReferenceException (const std::string& p_raison);
private:

};

#endif /* REFERENCEEXCEPTION_H */

