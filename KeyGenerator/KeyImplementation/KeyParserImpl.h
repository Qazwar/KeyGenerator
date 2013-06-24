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
#include <sstream>
#include <cassert>

#include <RuleMaker.h>
#include <SymbolImplementation/SymbolRunImpl.h>

#include "KeyConfiguratorImpl.h"

namespace InnerImplementation
{
namespace KeyImplementation
{

    /**
     * Entity which is using for parsing text.
     * @tparam Character Type of character in key.
     * @tparam Type of class with static methods
     * for getting rules of key and symbol in key construction.
     */
    template<typename Character,
             typename TRuleMaker=RuleMakerImpl<Character>>
    class KeyParserImpl
    {
    private:
        typedef InnerImplementation::SymbolImplementation::SymbolRunImpl<Character, TRuleMaker> SymbolRun;

    public:
        /**
         * Parses given text to chain of symbols run in key.
         * @param text String for parsing.
         * @returns Raw pointer on last symbol in chain.
         */
        static SymbolRun* ParseText(const std::basic_string<Character> &text)
        {
            const KeyConfiguratorImpl<Character>* config = TRuleMaker::getKeyRule();
            Character separator = config->getSeparator();

            // Splits string by specified separator character.
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

            // Generates chain of symbol run. Chain begins with last symbol in key.
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
