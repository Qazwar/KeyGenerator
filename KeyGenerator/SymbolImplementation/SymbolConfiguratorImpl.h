/*
 * SymbolConfiguratorImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef SYMBOLCONFIGURATORIMPL_H_
#define SYMBOLCONFIGURATORIMPL_H_

#include "SymbolRun.h"

namespace InnerImplementation
{
namespace SymbolImplementation
{

    template<typename Character>
    class SymbolConfiguratorImpl
    {
    public:
        SymbolConfiguratorImpl() :
            symbolLength(0)
        {
        }

        void setEndSymbol(const SymbolRunImpl<Character>& endSymbol)
        {
            this->endSymbol = endSymbol;
        }

        const SymbolRunImpl<Character>& getEndSymbol() const
        {
            return endSymbol;
        }

        void setStartSymbol(const SymbolRunImpl<Character>& startSymbol)
        {
            this->startSymbol = startSymbol;
        }

        const SymbolRunImpl<Character>& getStartSymbol() const
        {
            return startSymbol;
        }

        std::basic_string<Character> getFirstSymbolKey() const
        {
            return std::basic_string<Character>(startSymbol.getBegin(), startSymbol.getEnd());
        }

        void setSymbolLength(size_t symbolLength)
        {
            this->symbolLength = symbolLength;
        }

        size_t getSymbolLength() const
        {
            return symbolLength;
        }

        void setTerminalCharacters(const std::basic_string<Character>& terminalCharacters)
        {
            this->terminalCharacters = terminalCharacters;
        }

        const std::basic_string<Character>& getTerminalCharacters() const
        {
            return terminalCharacters;
        }

        void setWrongCharacters(const std::basic_string<Character>& wrongCharacters)
        {
            this->wrongCharacters = wrongCharacters;
        }

        const std::basic_string<Character>& getWrongCharacters() const
        {
            return wrongCharacters;
        }

    private:
        size_t symbolLength;

        SymbolRunImpl<Character> startSymbol;

        SymbolRunImpl<Character> endSymbol;

        std::basic_string<Character> terminalCharacters;

        std::basic_string<Character> wrongCharacters;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */

#endif /* SYMBOLCONFIGURATORIMPL_H_ */
