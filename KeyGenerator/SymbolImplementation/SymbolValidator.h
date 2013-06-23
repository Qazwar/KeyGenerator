/*
 * SymbolValidator.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef SYMBOLVALIDATOR_H_
#define SYMBOLVALIDATOR_H_

#include "SymbolValidatorImpl.h"

namespace InnerImplementation
{
namespace SymbolImplementation
{

    typedef SymbolValidatorImpl<char> SymbolValidator;

    typedef SymbolValidatorImpl<wchar_t> SymbolValidatorWide;

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */

#endif /* SYMBOLVALIDATOR_H_ */
