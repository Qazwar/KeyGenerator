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
    SymbolTests::SymbolTests()
    {
    }

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

    TEST_F(SymbolTests, validate_correct_symbol)
    {
        std::string testSymbol("B3");
        SymbolRun run(testSymbol);

        ASSERT_TRUE(validator.IsCorrectLenght(testSymbol));
        ASSERT_FALSE(validator.HasWrongCharacters(testSymbol));
    }

    TEST_F(SymbolTests, validate_symbol_with_wrong_length)
    {
        std::string testSymbol("AB3");
        SymbolRun run(testSymbol);

        ASSERT_FALSE(validator.IsCorrectLenght(testSymbol));
        ASSERT_FALSE(validator.HasWrongCharacters(testSymbol));

        std::wstring testSymbolWide(L"1");
        SymbolRunWide runWide(testSymbolWide);

        ASSERT_FALSE(validatorWide.IsCorrectLenght(testSymbolWide));
        ASSERT_FALSE(validatorWide.HasWrongCharacters(testSymbolWide));
    }

    TEST_F(SymbolTests, validate_symbol_with_wrong_character)
    {
        std::string testSymbol("D3");
        SymbolRun run(testSymbol);

        ASSERT_TRUE(validator.IsCorrectLenght(testSymbol));
        ASSERT_TRUE(validator.HasWrongCharacters(testSymbol));

        std::wstring testSymbolWide(L"C0");
        SymbolRunWide runWide(testSymbolWide);

        ASSERT_TRUE(validatorWide.IsCorrectLenght(testSymbolWide));
        ASSERT_TRUE(validatorWide.HasWrongCharacters(testSymbolWide));
    }

} /* namespace SymbolTests */
