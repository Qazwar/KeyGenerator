/*
 * SymbolTests.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef SYMBOLTESTS_H_
#define SYMBOLTESTS_H_

#include <gtest/gtest.h>

#include <SymbolImplementation/SymbolValidator.h>

namespace SymbolTesting
{

    class SymbolTests : public testing::Test
    {
    public:
        SymbolTests();

    public:
        InnerImplementation::SymbolImplementation::SymbolValidator validator;

        InnerImplementation::SymbolImplementation::SymbolValidatorWide validatorWide;
    };

} /* namespace SymbolTesting */
#endif /* SYMBOLTESTS_H_ */
