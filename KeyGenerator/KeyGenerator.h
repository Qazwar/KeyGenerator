/*
 * KeyGenerator.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYGENERATOR_H_
#define KEYGENERATOR_H_

#include "KeyGeneratorImpl.h"

namespace BinaryStudio
{

    typedef InnerImplementation::KeyGeneratorImpl<char> KeyGenerator;

    typedef InnerImplementation::KeyGeneratorImpl<wchar_t> KeyGeneratorWide;

}

#endif /* KEYGENERATOR_H_ */
