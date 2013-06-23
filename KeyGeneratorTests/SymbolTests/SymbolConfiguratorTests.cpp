/*
 * SymbolConfiguratorTests.cpp
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#include "SymbolConfiguratorTests.h"

#include <memory>

using namespace InnerImplementation;
using namespace InnerImplementation::SymbolImplementation;

namespace SymbolTesting
{
    SymbolConfiguratorTests::SymbolConfiguratorTests() :
        symbolLength(2),
        runStart("A1"),
        runEnd("Z9"),
        terminal("Z9"),
        wrong("DFGJMQV0"),
        runStartWide(L"A1"),
        runEndWide(L"Z9"),
        terminalWide(L"Z9"),
        wrongWide(L"DFGJMQV0")
    {
    }

    TEST_F(SymbolConfiguratorTests, create_configuration_and_check_it)
    {
        SymbolConfigurator config;

        config.setSymbolLength(symbolLength);
        config.setStartSymbol(runStart);
        config.setEndSymbol(runEnd);
        config.setTerminalCharacters(terminal);
        config.setWrongCharacters(wrong);

        ASSERT_EQ(config.getSymbolLength(), symbolLength);
        ASSERT_EQ(config.getStartSymbol(), runStart);
        ASSERT_EQ(config.getEndSymbol(), runEnd);
        ASSERT_STREQ(config.getTerminalCharacters().c_str(), terminal.c_str());
        ASSERT_STREQ(config.getWrongCharacters().c_str(), wrong.c_str());
    }

    TEST_F(SymbolConfiguratorTests, create_cofigurator_for_task)
    {
        const SymbolConfigurator* config = RuleMaker::getSymbolRule();

        ASSERT_EQ(config->getSymbolLength(), symbolLength);
        ASSERT_EQ(config->getStartSymbol(), runStart);
        ASSERT_EQ(config->getEndSymbol(), runEnd);
        ASSERT_STREQ(config->getTerminalCharacters().c_str(), terminal.c_str());
        ASSERT_STREQ(config->getWrongCharacters().c_str(), wrong.c_str());
    }

    TEST_F(SymbolConfiguratorTests, create_wide_cofigurator_for_task)
    {
        const SymbolConfiguratorWide* config = RuleMakerWide::getSymbolRule();

        ASSERT_EQ(config->getSymbolLength(), symbolLength);
        ASSERT_EQ(config->getStartSymbol(), runStartWide);
        ASSERT_EQ(config->getEndSymbol(), runEndWide);
        ASSERT_STREQ(config->getTerminalCharacters().c_str(), terminalWide.c_str());
        ASSERT_STREQ(config->getWrongCharacters().c_str(), wrongWide.c_str());
    }
} /* namespace SymbolTesting */
