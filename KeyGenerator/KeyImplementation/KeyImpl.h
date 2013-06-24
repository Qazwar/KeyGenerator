/*
 * KeyImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYIMPL_H_
#define KEYIMPL_H_

#include "KeyParserImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{

    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>>
    class KeyImpl
    {
    private:
        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character, TRuleMaker> SymbolRun;

    public:
        KeyImpl(const std::basic_string<Character> &keyText) :
            symbolCount(0)
        {
            lastSymbol.reset(KeyParserImpl<Character>::ParseText(keyText));

            if (lastSymbol)
            {
                this->UpdateKeyText();

                assert(keyText.compare(this->text) == 0 && "parsing text of key is wrong");
            }
        }

        size_t getSymbolCount() const
        {
            return symbolCount;
        }

        SymbolRun * getLastSymbol() const
        {
            return this->lastSymbol.get();
        }

        operator const Character*() const
        {
            return this->text.c_str();
        }

        void operator ++()
        {
            ++(*lastSymbol);
            this->UpdateKeyText();
        }

    private:
        void UpdateKeyText()
        {
            this->symbolCount = 1;
            this->text = *lastSymbol.get();

            const KeyConfiguratorImpl<Character>* config = TRuleMaker::getKeyRule();

            SymbolRun* symbolPtr = lastSymbol.get();
            while(symbolPtr->HasPreviousSymbol())
            {
                ++this->symbolCount;
                symbolPtr = symbolPtr->getPreviousSymbol();

                this->text.insert(std::begin(this->text), config->getSeparator());
                this->text.insert(std::begin(this->text), symbolPtr->getBegin(), symbolPtr->getEnd());
            }
        }

    private:
        std::unique_ptr<SymbolRun> lastSymbol;

        std::basic_string<Character> text;

        size_t symbolCount;
    };
}
}


#endif /* KEYIMPL_H_ */
