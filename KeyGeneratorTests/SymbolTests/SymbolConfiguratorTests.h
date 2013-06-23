/*
 * SymbolConfiguratorTests.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef SYMBOLCONFIGURATORTESTS_H_
#define SYMBOLCONFIGURATORTESTS_H_

#include <gtest/gtest.h>

#include <RuleMaker.h>

namespace SymbolTesting
{

    class SymbolConfiguratorTests : public testing::Test
    {
    public:
        SymbolConfiguratorTests();

    public:
        const size_t symbolLength;
        const std::string runStart;
        const std::string runEnd;
        const std::string terminal;
        const std::string wrong;

        const std::wstring runStartWide;
        const std::wstring runEndWide;
        const std::wstring terminalWide;
        const std::wstring wrongWide;
    };

} /* namespace SymbolTesting */
#endif /* SYMBOLCONFIGURATORTESTS_H_ */
