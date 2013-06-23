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

namespace InnerImplementation
{
namespace SymbolImplementation
{
    template<typename Character>
    class SymbolValidatorImpl
    {
    public:
        SymbolValidatorImpl()
        {
            this->config = RuleMakerImpl<Character>::getSymbolRule();
        }

        bool IsCorrectLenght(const SymbolRunImpl<Character> &symbol) const
        {
            return symbol.getSymbolLength() == config->getSymbolLength();
        }

        bool HasWrongCharacters(const SymbolRunImpl<Character> &symbol) const
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
