/*
 * Key.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEY_H_
#define KEY_H_

#include "KeyImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{
    typedef KeyImpl<char> Key;

    typedef KeyImpl<wchar_t> KeyWide;

} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/


#endif /* KEY_H_ */
