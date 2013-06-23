/*
 * KeyParserImpl.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef KEYPARSERIMPL_H_
#define KEYPARSERIMPL_H_

#include <algorithm>
#include <ios>
#include <cassert>

#include <RuleMaker.h>
#include <SymbolImplementation/SymbolRunImpl.h>

#include "KeyConfiguratorImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{

    template<typename Character>
    class KeyParserImpl
    {
    private:
        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character> SymbolRun;

    public:
        static SymbolRun* ParseText(const std::basic_string<Character> &text)
        {
            const KeyConfiguratorImpl<Character>* config = RuleMakerImpl<Character>::getKeyRule();
            Character separator = config->getSeparator();

            std::vector<std::basic_string<Character>> symbolsText;
            try
            {
                std::basic_istringstream<Character> istream(text);
                std::basic_string<Character> destSymbol;
                while(std::getline(istream, destSymbol, separator))
                {
                    symbolsText.push_back(destSymbol);
                }
            }
            catch(const std::ios_base::failure &e)
            {
                assert(false && e.what());
            }

            std::unique_ptr<SymbolRun> run(nullptr);
            SymbolRun* runPtr = nullptr;
            std::for_each(symbolsText.rbegin(), symbolsText.rend(), [&](const std::basic_string<Character> &symbolText)
            {
                if (!run)
                {
                    run.reset(new SymbolRun(symbolText));
                    runPtr = run.get();
                }
                else
                {
                    runPtr->setPreviousSymbol(symbolText);
                    runPtr = runPtr->getPreviousSymbol();
                }
            });

            return run.release();
        }
    };
}
}


#endif /* KEYPARSERIMPL_H_ */
