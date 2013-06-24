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

    /**
     * Entity which holds symbol runs of generated key.
     * @tparam Character Type of character in key.
     * @tparam Type of class with static methods
     * for getting rules of key and symbol in key construction.
     */
    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>>
    class KeyImpl
    {
    private:
        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character, TRuleMaker> SymbolRun;

    public:
        /**
         * Constructor of KeyImpl.
         * It parses specified text and holds parsed symbols.
         * @param keyText String which contains representation of key.
         */
        KeyImpl(const std::basic_string<Character> &keyText) :
            symbolCount(0)
        {
            lastSymbol.reset(KeyParserImpl<Character, TRuleMaker>::ParseText(keyText));

            if (lastSymbol)
            {
                this->UpdateKeyText();

                assert(keyText.compare(this->text) == 0 && "parsing text of key is wrong");
            }
        }

        /**
         * Gets count of symbol runs in key.
         * @returns Count of symbols in key.
         */
        size_t getSymbolCount() const
        {
            return symbolCount;
        }

        /**
         * Gets last symbol in Key.
         * @return Pointer on last SymbolRun.
         */
        SymbolRun * getLastSymbol() const
        {
            return this->lastSymbol.get();
        }

        /**
         * Overloads operator for casting to "const Character*" type.
         * @returns String which contents key text.
         */
        operator const Character*() const
        {
            return this->text.c_str();
        }

        /**
         * Overloads increment operator for getting next key.
         */
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
