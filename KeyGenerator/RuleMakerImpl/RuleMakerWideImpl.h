/*
 * RuleMakerWideImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKERWIDEIMPL_H_
#define RULEMAKERWIDEIMPL_H_

#include "RuleMakerImpl.h"

namespace InnerImplementation
{
    typedef SymbolImplementation::SymbolConfiguratorWide SymbolConfigWide;

    typedef KeyImplementation::KeyConfiguratorWide KeyConfigWide;

    /**
     * Specified RuleMaker with for wchar_t strings.
     */
    template<>
    class RuleMakerImpl <wchar_t, SymbolConfigWide, KeyConfigWide>
    {
    public:
        /**
         * Gets configuration of symbols.
         */
        static const SymbolConfigWide* getSymbolRule()
        {
            if (!symbolConfig)
            {
                symbolConfig.reset(new SymbolConfigWide());

                symbolConfig->setSymbolLength(2);
                symbolConfig->setStartSymbol(std::wstring(L"A1"));
                symbolConfig->setEndSymbol(std::wstring(L"Z9"));
                symbolConfig->setTerminalCharacters(L"Z9");
                symbolConfig->setWrongCharacters(L"DFGJMQV0");
            }

            return symbolConfig.get();
        }

        /**
         * Gets configuration of keys.
         */
        static const KeyConfigWide* getKeyRule()
        {
            if (!keyConfig)
            {
                keyConfig.reset(new KeyConfigWide(1, 10, '-'));
            }

            return keyConfig.get();
        }

    private:
        static std::unique_ptr<SymbolConfigWide> symbolConfig;

        static std::unique_ptr<KeyConfigWide> keyConfig;
    };
}

#endif /* RULEMAKERWIDEIMPL_H_ */
