/*
 * KeyGeneratorTests.cpp
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#include "KeyGeneratorTests.h"

#include <KeyGenerator.h>

namespace KeyTesting
{

    TEST_F(KeyGeneratorTests, generate_first_key)
    {
        BinaryStudio::KeyGenerator generator;

        std::string key = generator.getFirstKey();

        ASSERT_STREQ(key.c_str(), "A1");
    }

    TEST_F(KeyGeneratorTests, generate_next_key_from_some_random)
    {
        std::vector<std::string> oldKeys;
        std::vector<std::string> mustBeKeys;
        oldKeys.push_back("A2-B9");
        mustBeKeys.push_back("A2-C1");
        oldKeys.push_back("B5-Z9");
        mustBeKeys.push_back("B6-A1");
        oldKeys.push_back("A3-E9");
        mustBeKeys.push_back("A3-H1");
        oldKeys.push_back("a1-a2-a3-a4-a5-a6-a7-a8-a9");
        mustBeKeys.push_back("A1-A2-A3-A4-A5-A6-A7-A8-B1");
        oldKeys.push_back("Z9-Z9-Z9");
        mustBeKeys.push_back("A1-A1-A1-A1");

        BinaryStudio::KeyGenerator generator;

        ASSERT_EQ(oldKeys.size(), mustBeKeys.size());

        for (size_t i = 0; i < oldKeys.size(); ++i)
        {
            std::string newKey = generator.GenerateKey(oldKeys[i]);

            ASSERT_STRNE(oldKeys[i].c_str(), newKey.c_str());
            ASSERT_STREQ(mustBeKeys[i].c_str(), newKey.c_str());
        }
    }

    TEST_F(KeyGeneratorTests, throw_exp_on_generating_from_wrong_key)
    {
        std::wstring keyEmpty;
        std::wstring keyTooLing(L"A1-A2-A3-A4-A5-A6-A7-A8-A9-A1-A2");
        std::wstring keyOneCharInSymbol(L"A1-1-A1");
        std::wstring keyTooLongSymbol(L"A1-A11-A1");
        std::wstring keyContainsZero(L"A0");
        std::wstring keyContainsD(L"D1");
        std::wstring keyContainsF(L"F1-A1");
        std::wstring keyContainsG(L"A1-G3");
        std::wstring keyContainsJ(L"J5-A1-B4");
        std::wstring keyContainsM(L"A1-M4-U2");
        std::wstring keyContainsQ(L"A1-Q3-A4");
        std::wstring keyContainsV(L"T6-V8");

        BinaryStudio::KeyGeneratorWide generator;

        ASSERT_THROW(generator.GenerateKey(keyEmpty), BinaryStudio::EmptyKeyExp);
        ASSERT_THROW(generator.GenerateKey(keyTooLing), BinaryStudio::WrongKeySizeExp);
        ASSERT_THROW(generator.GenerateKey(keyOneCharInSymbol), BinaryStudio::WrongKeySizeExp);
        ASSERT_THROW(generator.GenerateKey(keyTooLongSymbol), BinaryStudio::WrongKeySizeExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsZero), BinaryStudio::WrongCharacterExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsD), BinaryStudio::WrongCharacterExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsF), BinaryStudio::WrongCharacterExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsG), BinaryStudio::WrongCharacterExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsJ), BinaryStudio::WrongCharacterExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsM), BinaryStudio::WrongCharacterExp);
        ASSERT_THROW(generator.GenerateKey(keyContainsV), BinaryStudio::WrongCharacterExp);
    }

} /* namespace KeyTesting */
