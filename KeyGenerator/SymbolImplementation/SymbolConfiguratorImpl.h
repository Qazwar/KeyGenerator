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

    /**
     * Entity that contains information about symbols in key.
     * @tparam Character Type of character in key.
     */
    template<typename Character>
    class SymbolConfiguratorImpl
    {
    public:
        /**
         * Default constructor for entity.
         */
        SymbolConfiguratorImpl() :
            symbolLength(0)
        {
        }

        /**
         * Sets start symbol in key.
         * @param startSymbol Specified symbol.
         */
        void setStartSymbol(const std::basic_string<Character>& startSymbol)
        {
            this->startSymbol = startSymbol;
        }

        /**
         * Gets start symbol in key.
         * @return Specified symbol.
         */
        const std::basic_string<Character>& getStartSymbol() const
        {
            return startSymbol;
        }

        /**
         * Sets end symbol in key.
         * @param endSymbol Specified symbol.
         */
        void setEndSymbol(const std::basic_string<Character>& endSymbol)
        {
            this->endSymbol = endSymbol;
        }

        /**
         * Gets end symbol in key.
         * @param Specified symbol.
         */
        const std::basic_string<Character>& getEndSymbol() const
        {
            return endSymbol;
        }

        /**
         * Sets symbol length in key.
         * @param symbolLength Specified length.
         */
        void setSymbolLength(size_t symbolLength)
        {
            this->symbolLength = symbolLength;
        }

        /**
         * Gets symbol length in key.
         * @return Specified length.
         */
        size_t getSymbolLength() const
        {
            return symbolLength;
        }

        /**
         * Sets terminate characters in symbol.
         * @param terminalCharacters String as set of terminate characters.
         */
        void setTerminalCharacters(const std::basic_string<Character>& terminalCharacters)
        {
            this->terminalCharacters = terminalCharacters;
        }

        /**
         * Gets terminate characters in symbol.
         * @return String as set of terminate characters.
         */
        const std::basic_string<Character>& getTerminalCharacters() const
        {
            return terminalCharacters;
        }

        /**
         * Sets prohibited characters in symbol.
         * @param wrongCharacters String as set of prohibited characters.
         */
        void setWrongCharacters(const std::basic_string<Character>& wrongCharacters)
        {
            this->wrongCharacters = wrongCharacters;
        }

        /**
         * Gets prohibited characters in symbol.
         * @return String as set of prohibited characters.
         */
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
