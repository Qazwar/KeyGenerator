/*
 * SymbolTests.cpp
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#include "SymbolTests.h"

#include <string>

#include <SymbolImplementation/SymbolRun.h>

using namespace InnerImplementation::SymbolImplementation;

namespace SymbolTesting
{

    TEST_F(SymbolTests, create_symbol_run)
    {
        std::string testSymbol("A1");
        std::wstring testSymbolWide(L"A1");

        SymbolRun run(testSymbol);
        SymbolRunWide runWide(testSymbolWide);

        ASSERT_STREQ(run, testSymbol.c_str());
        ASSERT_STREQ(runWide, testSymbolWide.c_str());
    }

    TEST_F(SymbolTests, create_linked_symbol_run)
    {
        std::string testSymbolFirst("A1");
        std::string testSymbolSecond("A2");

        SymbolRun run(testSymbolFirst);
        run.setPreviousSymbol(testSymbolSecond);

        ASSERT_TRUE(run.HasPreviousSymbol());

        SymbolRun* previousRun = run.getPreviousSymbol();

        ASSERT_STRNE(run, *previousRun);
    }

} /* namespace SymbolTests */
