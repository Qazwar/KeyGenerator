/*
 * SimpleKeyGeneration.h
 *
 *  Created on: 24.06.2013
 *      Author: grad
 */

#ifndef SIMPLEKEYGENERATION_H_
#define SIMPLEKEYGENERATION_H_

#include <iostream>

#include <KeyGenerator.h>

void SimpleKeyGeneration()
{
    BinaryStudio::KeyGenerator generator;

    std::cout << generator.GenerateKey(std::string("A1-B6")) << std::endl;
}

#endif /* SIMPLEKEYGENERATION_H_ */
