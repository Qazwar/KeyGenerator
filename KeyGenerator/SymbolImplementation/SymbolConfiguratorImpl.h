/*
 * SymbolConfiguratorImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef SYMBOLCONFIGURATORIMPL_H_
#define SYMBOLCONFIGURATORIMPL_H_

#include <string>

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

        void setEndSymbol(const std::basic_string<Character>& endSymbol)
        {
            this->endSymbol = endSymbol;
        }

        const std::basic_string<Character>& getEndSymbol() const
        {
            return endSymbol;
        }

        void setStartSymbol(const std::basic_string<Character>& startSymbol)
        {
            this->startSymbol = startSymbol;
        }

        const std::basic_string<Character>& getStartSymbol() const
        {
            return startSymbol;
        }

        std::basic_string<Character> getFirstSymbolKey() const
        {
            return startSymbol;
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

        std::basic_string<Character> startSymbol;

        std::basic_string<Character> endSymbol;

        std::basic_string<Character> terminalCharacters;

        std::basic_string<Character> wrongCharacters;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */

#endif /* SYMBOLCONFIGURATORIMPL_H_ */
