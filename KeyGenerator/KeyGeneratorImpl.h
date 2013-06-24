/*
 * KeyGeneratorImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYGENERATORIMPL_H_
#define KEYGENERATORIMPL_H_

#include "RuleMaker.h"
#include "KeyImplementation/Key.h"
#include "KeyImplementation/KeyValidator.h"

#include "Exceptions/EmptyKeyExp.h"
#include "Exceptions/WrongKeySizeExp.h"
#include "Exceptions/WrongCharacterExp.h"

namespace InnerImplementation
{

    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>,
             typename TValidator=KeyImplementation::KeyValidatorImpl<Character>>
    class KeyGeneratorImpl
    {
    private:
        typedef KeyImplementation::KeyImpl<Character, TRuleMaker> KeyType;

    public:
        KeyGeneratorImpl()
        {
        }

        std::basic_string<Character> getFirstKey() const
        {
             const SymbolImplementation::SymbolConfiguratorImpl<Character> * rule = TRuleMaker::getSymbolRule();

             return rule->getFirstSymbolKey();
        }

        std::basic_string<Character> GenerateKey(const std::basic_string<Character> &inputKey) const
        {
            if (inputKey.empty())
            {
                throw BinaryStudio::EmptyKeyExp();
            }

            std::basic_string<Character> keyText(inputKey);
            std::transform(keyText.begin(), keyText.end(),keyText.begin(), ::toupper);

            KeyType key(keyText);

            if (!validator.IsCorrectLength(key))
            {
                throw BinaryStudio::WrongKeySizeExp();
            }
            if (!validator.IsCorrectSymbols(key))
            {
                throw BinaryStudio::WrongCharacterExp();
            }

            ++key;

            return std::basic_string<Character>(key);
        }

    private:
        TValidator validator;
    };
} /* namespace InnerImplementation */


#endif /* KEYGENERATORIMPL_H_ */
