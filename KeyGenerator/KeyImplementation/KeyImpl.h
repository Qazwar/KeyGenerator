/*
 * KeyImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYIMPL_H_
#define KEYIMPL_H_

#include <SymbolImplementation/SymbolRun.h>

#include "KeyParserImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{

    template<typename Character>
    class KeyImpl
    {
    public:
        KeyImpl(const std::basic_string<Character> &keyText) :
            symbolCount(0)
        {
            lastSymbol.reset(KeyParserImpl<Character>::ParseText(keyText));

            if (lastSymbol)
            {
                ++this->symbolCount;

                std::unique_ptr<KeyConfiguratorImpl<Character>> config;
                config.reset(RuleMakerImpl<Character>::MakeKeyRule());

                this->text = *lastSymbol.get();

                SymbolRun* symbolPtr = lastSymbol.get();
                while(symbolPtr->HasPreviousSymbol())
                {
                    ++this->symbolCount;
                    symbolPtr = symbolPtr->getPreviousSymbol();

                    this->text.insert(std::begin(this->text), config->getSeparator());
                    this->text.insert(std::begin(this->text), symbolPtr->getBegin(), symbolPtr->getEnd());
                }

                assert(keyText.compare(this->text) == 0 && "parsing text of key is wrong");
            }
        }

        size_t getSymbolCount() const
        {
            return symbolCount;
        }

        operator const Character*() const
        {
            return this->text.c_str();
        }

    private:

        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character> SymbolRun;
        std::unique_ptr<SymbolRun> lastSymbol;

        std::basic_string<Character> text;

        size_t symbolCount;
    };
}
}


#endif /* KEYIMPL_H_ */
