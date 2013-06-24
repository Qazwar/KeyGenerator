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

    /**
     * Entity which provides keys generating.
     * @tparam Character Type of character in key.
     * @tparam TRuleMaker Type of class with static methods
     * for getting rules of key and symbol in key construction.
     * @tparam TValidator Type of key validator.
     */
    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>,
             typename TValidator=KeyImplementation::KeyValidatorImpl<Character, TRuleMaker>>
    class KeyGeneratorImpl
    {
    private:
        typedef KeyImplementation::KeyImpl<Character, TRuleMaker> KeyType;

    public:
        KeyGeneratorImpl() = default;

        /**
         * Gets first generated key.
         * @return string that represents key.
         */
        std::basic_string<Character> getFirstKey() const
        {
             const SymbolImplementation::SymbolConfiguratorImpl<Character> * ruleSymbol = TRuleMaker::getSymbolRule();
             const KeyImplementation::KeyConfiguratorImpl<Character> * ruleKey = TRuleMaker::getKeyRule();

             std::basic_string<Character> key;

             for(size_t i = 0; i < ruleKey->getMinLength(); ++i)
             {
                 key += ruleSymbol->getStartSymbol();
                 key.push_back(ruleKey->getSeparator());
             }
             key.pop_back();

             return key;
        }

        /**
         * Generate string as next key after specified string-key.
         * @param inputKey String with old key.
         * @return New generated key.
         * @exception BinaryStudio::EmptyKeyExp when inputKey is empty.
         * @exception BinaryStudio::WrongKeySizeExp when key has incorrect length.
         * @exception BinaryStudio::WrongCharacterExp when key has prohibited characters.
         */
        std::basic_string<Character> GenerateKey(const std::basic_string<Character> &inputKey) const
        {
            if (inputKey.empty())
            {
                throw BinaryStudio::EmptyKeyExp();
            }

            // Makes inputKey in upper case.
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
