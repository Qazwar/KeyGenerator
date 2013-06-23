/*
 * KeyGeneratorImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYGENERATORIMPL_H_
#define KEYGENERATORIMPL_H_

#include "RuleMaker.h"
#include "KeyImplementation/KeyValidator.h"

namespace InnerImplementation
{

    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>,
             typename TValidator=KeyImplementation::KeyValidatorImpl<Character>>
    class KeyGeneratorImpl
    {
    public:
        KeyGeneratorImpl()
        {
        }

        std::basic_string<Character> getFirstKey()
        {
             const SymbolImplementation::SymbolConfiguratorImpl<Character> * rule = TRuleMaker::getSymbolRule();

             return rule->getFirstSymbolKey();
        }

    private:
        TValidator validator;
    };
} /* namespace InnerImplementation */


#endif /* KEYGENERATORIMPL_H_ */
