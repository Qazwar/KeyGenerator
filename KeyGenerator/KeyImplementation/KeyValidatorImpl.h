/*
 * KeyValidatorImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYVALIDATORIMPL_H_
#define KEYVALIDATORIMPL_H_

#include <RuleMaker.h>

#include <SymbolImplementation/SymbolValidatorImpl.h>
#include <KeyImplementation/KeyImpl.h>

namespace InnerImplementation
{
namespace KeyImplementation
{

    /**
     * Entity which validates key representation.
     * @tparam Character Type of character in key.
     * @tparam Type of class with static methods
     * for getting rules of key and symbol in key construction.
     */
    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>>
    class KeyValidatorImpl
    {
    private:

        typedef InnerImplementation::SymbolImplementation::SymbolValidatorImpl<Character, TRuleMaker> SymbolValidator;

        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character, TRuleMaker> SymbolRun;

    public:
        /**
         * Default constructor for key validator.
         */
        KeyValidatorImpl()
        {
            this->config = TRuleMaker::getKeyRule();
            this->symbolValidator.reset(new SymbolValidator());
        }

        /**
         * Checks whether length of key and its symbols is correct.
         * @param key Key for checking.
         * @return true if key is good, false otherwise.
         */
        bool IsCorrectLength(const KeyImpl<Character, TRuleMaker> &key) const
        {
            bool isCorrectKeyLen = key.getSymbolCount() >= config->getMinLength() && key.getSymbolCount() <= config->getMaxLength();
            bool isCorrectSymbolLen = this->CheckSymbols(key, [this](const SymbolRun& symbol)
                    {
                        return this->symbolValidator->IsCorrectLenght(symbol);
                    });
            return isCorrectKeyLen && isCorrectSymbolLen;
        }

        /**
         * Checks whether key contains correct symbols.
         * @param key Key for checking.
         * @return true if key is good, false otherwise.
         */
        bool IsCorrectSymbols(const KeyImpl<Character, TRuleMaker> &key) const
        {
            return this->CheckSymbols(key, [this](const SymbolRun& symbol)
                    {
                        return !symbolValidator->HasWrongCharacters(symbol);
                    });
        }

    private:
        bool CheckSymbols(const KeyImpl<Character, TRuleMaker> &key, const std::function<bool(const SymbolRun&)> &functor) const
        {
            bool isCorrect = true;
            SymbolRun * symbolPtr = key.getLastSymbol();

            while (symbolPtr != nullptr)
            {
                if ( !functor(*symbolPtr) )
                {
                    isCorrect = false;
                    break;
                }

                symbolPtr = symbolPtr->getPreviousSymbol();
            }

            return isCorrect;
        }

    private:
        const KeyConfiguratorImpl<Character>* config;

        std::unique_ptr<SymbolValidator> symbolValidator;
    };

} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/

#endif /* KEYVALIDATORIMPL_H_ */
