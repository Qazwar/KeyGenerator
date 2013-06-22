/*
 * SymbolRun.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef SYMBOLRUN_H_
#define SYMBOLRUN_H_

#include "SymbolRunImpl.h"

namespace InnerImplementation
{
namespace SymbolImplementation
{

    typedef SymbolRunImpl<char> SymbolRun;

    typedef SymbolRunImpl<wchar_t> SymbolRunWide;

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */
#endif /* SYMBOLRUN_H_ */
