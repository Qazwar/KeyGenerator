/*
 * KeyConfigurator.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef KEYCONFIGURATOR_H_
#define KEYCONFIGURATOR_H_

#include "KeyConfiguratorImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{
    typedef KeyConfiguratorImpl<> KeyConfigurator;

    typedef KeyConfiguratorImpl<wchar_t> KeyConfiguratorWide;

} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/


#endif /* KEYCONFIGURATOR_H_ */
