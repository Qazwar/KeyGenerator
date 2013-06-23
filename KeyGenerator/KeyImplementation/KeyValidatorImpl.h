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

namespace InnerImplementation
{
namespace KeyImplementation
{
    template<typename Character>
    class KeyValidatorImpl
    {
    private:

        typedef InnerImplementation::SymbolImplementation::SymbolValidatorImpl<Character> SymbolValidator;

        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character> SymbolRun;

    public:
        KeyValidatorImpl()
        {
            this->config.reset(RuleMakerImpl<Character>::MakeKeyRule());
            this->symbolValidator.reset(new SymbolValidator());
        }

        bool IsCorrectLength(const KeyImpl<Character> &key) const
        {
            bool isCorrectKeyLen = key.getSymbolCount() >= config->getMinLength() && key.getSymbolCount() <= config->getMaxLength();
            bool isCorrectSymbolLen = this->CheckSymbols(key, [this](const SymbolRun& symbol)
                    {
                        return this->symbolValidator->IsCorrectLenght(symbol);
                    });
            return isCorrectKeyLen && isCorrectSymbolLen;
        }

        bool IsCorrectSymbols(const KeyImpl<Character> &key) const
        {
            return this->CheckSymbols(key, [this](const SymbolRun& symbol)
                    {
                        return !symbolValidator->HasWrongCharacters(symbol);
                    });
        }

    private:
        bool CheckSymbols(const KeyImpl<Character> &key, const std::function<bool(const SymbolRun&)> &functor) const
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

        std::unique_ptr<KeyConfiguratorImpl<Character>> config;

        std::unique_ptr<SymbolValidator> symbolValidator;
    };

} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/

#endif /* KEYVALIDATORIMPL_H_ */
