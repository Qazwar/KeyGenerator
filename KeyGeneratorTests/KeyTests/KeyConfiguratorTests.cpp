/*
 * KeyConfiguratorTests.cpp
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#include "KeyConfiguratorTests.h"

#include <KeyImplementation/KeyConfigurator.h>

using namespace InnerImplementation::KeyImplementation;

namespace KeyTesting
{

    TEST_F(KeyConfiguratorTests, create_keyconfigurator_and_check_fields)
    {
        const int min = 1;
        const int max = 10;
        const char separator = '-';
        const wchar_t separatorWide = '-';

        KeyConfigurator<char> configuration(min, max, separator);

        ASSERT_TRUE(configuration.getMinLength() == min);
        ASSERT_TRUE(configuration.getMaxLength() == max);
        ASSERT_TRUE(configuration.getSeparator() == separator);

        KeyConfigurator<wchar_t> configurationWide(min, max, separatorWide);

        ASSERT_TRUE(configurationWide.getMinLength() == min);
        ASSERT_TRUE(configurationWide.getMaxLength() == max);
        ASSERT_TRUE(configurationWide.getSeparator() == separatorWide);
    }

} /* namespace KeyTesting */
