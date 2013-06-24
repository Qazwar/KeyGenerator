/*
 * RuleMakerCharImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKERCHARIMPL_H_
#define RULEMAKERCHARIMPL_H_

#include "RuleMakerImpl.h"

namespace InnerImplementation
{
    typedef SymbolImplementation::SymbolConfigurator SymbolConfig;

    typedef KeyImplementation::KeyConfigurator KeyConfig;

    /**
     * Specified RuleMaker with for char strings.
     */
    template<>
    class RuleMakerImpl <char, SymbolImplementation::SymbolConfigurator, KeyImplementation::KeyConfigurator>
    {
    public:
        /**
         * Gets configuration of symbols.
         */
        static const SymbolConfig* getSymbolRule()
        {
            if (!symbolConfig)
            {
                symbolConfig.reset(new SymbolConfig());

                symbolConfig->setSymbolLength(2);
                symbolConfig->setStartSymbol(std::string("A1"));
                symbolConfig->setEndSymbol(std::string("Z9"));
                symbolConfig->setTerminalCharacters("Z9");
                symbolConfig->setWrongCharacters("DFGJMQV0");
            }

            return symbolConfig.get();
        }

        /**
         * Gets configuration of keys.
         */
        static const KeyConfig* getKeyRule()
        {
            if (!keyConfig)
            {
                keyConfig.reset(new KeyConfig(1, 10, '-'));
            }

            return keyConfig.get();
        }

    private:
        static std::unique_ptr<SymbolConfig> symbolConfig;

        static std::unique_ptr<KeyConfig> keyConfig;
    };
}

#endif /* RULEMAKERCHARIMPL_H_ */
