/*
 * RuleMaker.cpp
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#include "RuleMaker.h"

namespace InnerImplementation
{
    std::unique_ptr<SymbolConfig> RuleMaker::symbolConfig;

    std::unique_ptr<KeyConfig> RuleMaker::keyConfig;

    std::unique_ptr<SymbolConfigWide> RuleMakerWide::symbolConfig;

    std::unique_ptr<KeyConfigWide> RuleMakerWide::keyConfig;
}
