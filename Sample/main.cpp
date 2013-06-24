/*
 * main.cpp
 *
 *  Created on: 24.06.2013
 *      Author: grad
 */

#include "SimpleKeyGeneration.h"
#include "HardKeyGeneration.h"

std::unique_ptr<InnerImplementation::SymbolConfig> Rules::symbolConfig;

std::unique_ptr<InnerImplementation::KeyConfig> Rules::keyConfig;

int main(int argc, char** argv)
{
    SimpleKeyGeneration();

    HardKeyGeneration();

    return 0;
}

