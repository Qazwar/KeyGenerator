/*
 * SymbolValidatorImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef SYMBOLVALIDATORIMPL_H_
#define SYMBOLVALIDATORIMPL_H_

#include <memory>
#include <algorithm>

#include <RuleMaker.h>
#include "SymbolRun.h"

namespace InnerImplementation
{
namespace SymbolImplementation
{
    /**
     * Entity which validates symbol run representation.
     * @tparam Character Type of character in symbol.
     * @tparam Type of class with static methods
     * for getting rules of key and symbol in key construction.
     */
    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>>
    class SymbolValidatorImpl
    {
    public:
        /**
         * Default constructor for symbol validator.
         */
        SymbolValidatorImpl()
        {
            this->config = TRuleMaker::getSymbolRule();
        }

        /**
         * Checks whether length of symbol is correct.
         * @param symbol symbol for checking.
         * @return true if symbol is good, false otherwise.
         */
        bool IsCorrectLenght(const SymbolRunImpl<Character, TRuleMaker> &symbol) const
        {
            return symbol.getSymbolLength() == config->getSymbolLength();
        }

        /**
         * Checks whether symbol contains correct characters.
         * @param symbol Symbol for checking.
         * @return true if symbol is good, false otherwise.
         */
        bool HasWrongCharacters(const SymbolRunImpl<Character, TRuleMaker> &symbol) const
        {
            bool hasWrong = false;

            const std::basic_string<Character> wrong = config->getWrongCharacters();
            std::for_each(std::begin(wrong), std::end(wrong), [&](const Character &sign)
                {
                    typename std::basic_string<Character>::const_iterator it = std::find(symbol.getBegin(), symbol.getEnd(), sign);

                    if (it != symbol.getEnd())
                    {
                        hasWrong = true;
                    }
                });

            return hasWrong;
        }

    private:
        const SymbolConfiguratorImpl<Character>* config;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */


#endif /* SYMBOLVALIDATORIMPL_H_ */
