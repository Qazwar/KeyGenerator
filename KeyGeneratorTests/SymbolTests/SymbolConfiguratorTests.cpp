/*
 * SymbolConfiguratorTests.cpp
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#include "SymbolConfiguratorTests.h"

#include <SymbolImplementation/SymbolConfigurator.h>

using namespace InnerImplementation::SymbolImplementation;

namespace SymbolTesting
{

    TEST_F(SymbolConfiguratorTests, create_configuration_and_check_it)
    {
        SymbolConfigurator config;

        const int symbolLength = 2;
        const SymbolRun runStart("A1");
        const SymbolRun runEnd("Z9");
        const std::string terminal("Z9");
        const std::string wrong("DFGJMQV0");

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
} /* namespace SymbolTesting */
