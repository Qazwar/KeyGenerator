/*
 * KeyConfiguratorTests.cpp
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#include "KeyConfiguratorTests.h"

#include <RuleMaker.h>
#include <KeyImplementation/KeyConfigurator.h>

using namespace InnerImplementation::KeyImplementation;

namespace KeyTesting
{

    TEST_F(KeyConfiguratorTests, create_keyconfigurator_and_check_fields)
    {
        const size_t min = 1;
        const size_t max = 10;
        const char separator = '-';
        const wchar_t separatorWide = '-';

        KeyConfigurator configuration(min, max, separator);

        ASSERT_TRUE(configuration.getMinLength() == min);
        ASSERT_TRUE(configuration.getMaxLength() == max);
        ASSERT_TRUE(configuration.getSeparator() == separator);

        KeyConfiguratorWide configurationWide(min, max, separatorWide);

        ASSERT_TRUE(configurationWide.getMinLength() == min);
        ASSERT_TRUE(configurationWide.getMaxLength() == max);
        ASSERT_TRUE(configurationWide.getSeparator() == separatorWide);
    }

    TEST_F(KeyConfiguratorTests, create_cofigurator_for_task)
    {
        const KeyConfigurator* config = InnerImplementation::RuleMaker::getKeyRule();

        ASSERT_EQ(1, config->getMinLength());
        ASSERT_EQ(10, config->getMaxLength());
        ASSERT_EQ('-', config->getSeparator());
    }
} /* namespace KeyTesting */
