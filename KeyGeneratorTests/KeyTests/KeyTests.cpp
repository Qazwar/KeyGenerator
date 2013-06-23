/*
 * KeyTests.cpp
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#include "KeyTests.h"

#include <KeyImplementation/Key.h>

using namespace InnerImplementation::KeyImplementation;

namespace KeyTesting
{

    TEST_F(KeyTests, create_key_and_check_it)
    {
        std::string keyText("A1-B2-K9");

        Key key(keyText);

        ASSERT_EQ(3, key.getSymbolCount());
        ASSERT_STREQ(key, keyText.c_str());
    }

    TEST_F(KeyTests, create_worng_key_and_check_it)
    {
        std::wstring keyText(L"A-B2A-K0-A1");

        KeyWide key(keyText);

        ASSERT_EQ(4, key.getSymbolCount());
        ASSERT_STREQ(key, keyText.c_str());
    }

    TEST_F(KeyTests, create_empty_key_and_check_it)
    {
        std::string keyText;

        Key key(keyText);

        ASSERT_EQ(0, key.getSymbolCount());
        ASSERT_STREQ(key, keyText.c_str());
    }

} /* namespace KeyTesting */
