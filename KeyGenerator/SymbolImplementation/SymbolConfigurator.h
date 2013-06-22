/*
 * SymbolConfigurator.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef SYMBOLCONFIGURATOR_H_
#define SYMBOLCONFIGURATOR_H_

#include "SymbolConfiguratorImpl.h"
#include "RuleMakerImpl.h"

namespace InnerImplementation
{
namespace SymbolImplementation
{

    typedef SymbolConfiguratorImpl<char> SymbolConfigurator;

    typedef SymbolConfiguratorImpl<wchar_t> SymbolConfiguratorWide;

    typedef RuleMakerImpl<char> RuleMaker;

    typedef RuleMakerImpl<wchar_t> RuleMakerWide;

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */

#endif /* SYMBOLCONFIGURATOR_H_ */
