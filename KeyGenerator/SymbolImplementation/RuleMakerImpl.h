/*
 * RuleMakerImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKERIMPL_H_
#define RULEMAKERIMPL_H_

#include <memory>

#include "SymbolConfiguratorImpl.h"

namespace InnerImplementation
{
namespace SymbolImplementation
{

    template<typename Character>
    class RuleMakerImpl
    {
        public:
            static SymbolConfiguratorImpl<Character>* MakeSymbolRule()
            {
                std::unique_ptr<SymbolConfiguratorImpl<Character>> config;
                config.reset(new SymbolConfiguratorImpl<Character>());

                config->setSymbolLength(2);
                config->setStartSymbol(std::basic_string<Character>("A1"));
                config->setEndSymbol(std::basic_string<Character>("Z9"));
                config->setTerminalCharacters("Z9");
                config->setWrongCharacters("DFGJMQV0");

                return config.release();
            }
    };

    template<>
    class RuleMakerImpl <wchar_t>
    {
        public:
            static SymbolConfiguratorImpl<wchar_t>* MakeSymbolRule()
            {
                std::unique_ptr<SymbolConfiguratorImpl<wchar_t>> config;
                config.reset(new SymbolConfiguratorImpl<wchar_t>());

                config->setSymbolLength(2);
                config->setStartSymbol(std::wstring(L"A1"));
                config->setEndSymbol(std::wstring(L"Z9"));
                config->setTerminalCharacters(L"Z9");
                config->setWrongCharacters(L"DFGJMQV0");

                return config.release();
            }
    };

}
}

#endif /* RULEMAKERIMPL_H_ */
