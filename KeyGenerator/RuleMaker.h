/*
 * RuleMaker.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKER_H_
#define RULEMAKER_H_

#include "RuleMakerImpl/RuleMakerCharImpl.h"
#include "RuleMakerImpl/RuleMakerWideImpl.h"

namespace InnerImplementation
{

    typedef RuleMakerImpl<char, SymbolConfig, KeyConfig> RuleMaker;

    typedef RuleMakerImpl<wchar_t, SymbolConfigWide, KeyConfigWide> RuleMakerWide;

}


#endif /* RULEMAKER_H_ */
