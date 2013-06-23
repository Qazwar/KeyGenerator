/*
 * KeyTests.cpp
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#include "KeyTests.h"

#include <KeyImplementation/Key.h>
#include <KeyImplementation/KeyValidator.h>

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

    TEST_F(KeyTests, validate_correct_key)
    {
        std::string keyText("A1-B2-K9-H8-W7-P3");
        Key key(keyText);

        KeyValidator validator;

        ASSERT_TRUE(validator.IsCorrectLength(key));
        ASSERT_TRUE(validator.IsCorrectSymbols(key));
    }

    TEST_F(KeyTests, validate_wrong_size_key)
    {
        std::vector<KeyWide> wrongKeys;
        wrongKeys.push_back(KeyWide(L""));
        wrongKeys.push_back(KeyWide(L"A1-A2-A3-A4-A5-A6-A7-A8-A9-A1-A2"));
        wrongKeys.push_back(KeyWide(L"A1-1-A1"));
        wrongKeys.push_back(KeyWide(L"A1-A11-A1"));

        KeyValidatorWide validator;

        for (const KeyWide &key : wrongKeys)
        {
            ASSERT_FALSE(validator.IsCorrectLength(key));
        }
    }

    TEST_F(KeyTests, validate_wrong_content_key)
    {
        std::vector<Key> wrongKeys;
        wrongKeys.push_back(Key("A0"));
        wrongKeys.push_back(Key("D1"));
        wrongKeys.push_back(Key("F1-A1"));
        wrongKeys.push_back(Key("A1-G3"));
        wrongKeys.push_back(Key("J5-A1-B4"));
        wrongKeys.push_back(Key("A1-M4-U2"));
        wrongKeys.push_back(Key("A1-Q3-A4"));
        wrongKeys.push_back(Key("T6-V8"));

        KeyValidator validator;

        for (const Key &key : wrongKeys)
        {
            ASSERT_FALSE(validator.IsCorrectSymbols(key));
        }
    }

} /* namespace KeyTesting */
