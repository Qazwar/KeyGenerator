/*
 * KeyValidator.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYVALIDATOR_H_
#define KEYVALIDATOR_H_

#include "KeyValidatorImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{

    typedef KeyValidatorImpl<char> KeyValidator;

    typedef KeyValidatorImpl<wchar_t> KeyValidatorWide;

} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/
#endif /* KEYVALIDATOR_H_ */
