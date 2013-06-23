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

} /* namespace KeyTesting */
