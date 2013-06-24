/*
 * HardKeyGeneration.h
 *
 *  Created on: 24.06.2013
 *      Author: grad
 */

#ifndef HARDKEYGENERATION_H_
#define HARDKEYGENERATION_H_

#include <iostream>

#include <KeyGenerator.h>

class Rules
{
public:
    static const InnerImplementation::SymbolConfig* getSymbolRule()
    {
        if (!symbolConfig)
        {
            symbolConfig.reset(new InnerImplementation::SymbolConfig());

            symbolConfig->setStartSymbol("00000000");
            symbolConfig->setEndSymbol("11111111");
            symbolConfig->setSymbolLength(8);
            symbolConfig->setTerminalCharacters("1");
            symbolConfig->setWrongCharacters("");
        }

        return symbolConfig.get();
    }

    static const InnerImplementation::KeyConfig* getKeyRule()
    {
        if (!keyConfig)
        {
            keyConfig.reset(new InnerImplementation::KeyConfig(1,4,' '));
        }

        return keyConfig.get();
    }

private:
    static std::unique_ptr<InnerImplementation::SymbolConfig> symbolConfig;

    static std::unique_ptr<InnerImplementation::KeyConfig> keyConfig;
};

typedef InnerImplementation::KeyGeneratorImpl<char, Rules, InnerImplementation::KeyImplementation::KeyValidatorImpl<char, Rules>> MyBinaryGenerator;

void HardKeyGeneration()
{
    MyBinaryGenerator generator;

    try
    {
        std::cout << generator.GenerateKey(std::string("00001111")) << std::endl;
    }
    catch(std::exception&)
    {
        std::cout << "ups!" << std::endl;
    }
}

#endif /* HARDKEYGENERATION_H_ */
