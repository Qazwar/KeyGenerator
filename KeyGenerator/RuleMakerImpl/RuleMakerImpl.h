/*
 * RuleMakerImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKERIMPL_H_
#define RULEMAKERIMPL_H_

#include <memory>

#include "../SymbolImplementation/SymbolConfigurator.h"
#include "../KeyImplementation/KeyConfigurator.h"

namespace InnerImplementation
{

    template<typename Character,
             typename TSymbolConfigurator=SymbolImplementation::SymbolConfiguratorImpl<Character>,
             typename TKeyConfigurator=KeyImplementation::KeyConfiguratorImpl<Character>>
    class RuleMakerImpl
    {
    public:
        static const TSymbolConfigurator* getSymbolRule()
        {
            if (!symbolConfig)
            {
                symbolConfig.reset(new TSymbolConfigurator());
            }

            return symbolConfig.get();
        }

        static const TKeyConfigurator* getKeyRule()
        {
            if (!keyConfig)
            {
                keyConfig.reset(new TKeyConfigurator());
            }

            return keyConfig.get();
        }

    private:
        static std::unique_ptr<TSymbolConfigurator> symbolConfig;

        static std::unique_ptr<TKeyConfigurator> keyConfig;
    };

}

#endif /* RULEMAKERIMPL_H_ */
