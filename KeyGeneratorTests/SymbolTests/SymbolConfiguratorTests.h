/*
 * SymbolConfiguratorTests.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef SYMBOLCONFIGURATORTESTS_H_
#define SYMBOLCONFIGURATORTESTS_H_

#include <gtest/gtest.h>

#include <SymbolImplementation/SymbolConfigurator.h>

namespace SymbolTesting
{

    class SymbolConfiguratorTests : public testing::Test
    {
    public:
        SymbolConfiguratorTests();

    public:
        const size_t symbolLength;
        const InnerImplementation::SymbolImplementation::SymbolRun runStart;
        const InnerImplementation::SymbolImplementation::SymbolRun runEnd;
        const std::string terminal;
        const std::string wrong;

        const InnerImplementation::SymbolImplementation::SymbolRunWide runStartWide;
        const InnerImplementation::SymbolImplementation::SymbolRunWide runEndWide;
        const std::wstring terminalWide;
        const std::wstring wrongWide;
    };

} /* namespace SymbolTesting */
#endif /* SYMBOLCONFIGURATORTESTS_H_ */
