/*
 * RuleMakerImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKERIMPL_H_
#define RULEMAKERIMPL_H_

#include <memory>

#include "SymbolImplementation/SymbolConfigurator.h"
#include "KeyImplementation/KeyConfigurator.h"

namespace InnerImplementation
{

    template<typename Character>
    class RuleMakerImpl
    {
    private:
        typedef SymbolImplementation::SymbolConfiguratorImpl<Character> SymbolConfig;

        typedef KeyImplementation::KeyConfiguratorImpl<Character> KeyConfig;

    public:
        static SymbolConfig* MakeSymbolRule()
        {
            std::unique_ptr<SymbolConfig> config;
            config.reset(new SymbolConfig());

            config->setSymbolLength(2);
            config->setStartSymbol(std::basic_string<Character>("A1"));
            config->setEndSymbol(std::basic_string<Character>("Z9"));
            config->setTerminalCharacters("Z9");
            config->setWrongCharacters("DFGJMQV0");

            return config.release();
        }

        static KeyConfig* MakeKeyRule()
        {
            std::unique_ptr<KeyConfig> config;
            config.reset(new KeyConfig(1, 10, '-'));

            return config.release();
        }
    };

    template<>
    class RuleMakerImpl <wchar_t>
    {
    private:
        typedef SymbolImplementation::SymbolConfiguratorWide SymbolConfigWide;

        typedef KeyImplementation::KeyConfiguratorImpl<wchar_t> KeyConfig;

    public:
        static SymbolConfigWide* MakeSymbolRule()
        {
            std::unique_ptr<SymbolConfigWide> config;
            config.reset(new SymbolConfigWide());

            config->setSymbolLength(2);
            config->setStartSymbol(std::wstring(L"A1"));
            config->setEndSymbol(std::wstring(L"Z9"));
            config->setTerminalCharacters(L"Z9");
            config->setWrongCharacters(L"DFGJMQV0");

            return config.release();
        }

        static KeyConfig* MakeKeyRule()
        {
            std::unique_ptr<KeyConfig> config;
            config.reset(new KeyConfig(1, 10, '-'));

            return config.release();
        }
    };

}

#endif /* RULEMAKERIMPL_H_ */
