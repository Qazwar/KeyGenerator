/*
 * KeyConfigurator.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef KEYCONFIGURATORIMPL_H_
#define KEYCONFIGURATORIMPL_H_

#include <cstdlib>
#include <cassert>

namespace InnerImplementation
{
namespace KeyImplementation
{
    /**
     * Entity that contains information about key.
     * @tparam Character Type of character in key.
     */
    template<typename Character>
    class KeyConfiguratorImpl
    {
    public:
        /**
         * Constructor for setting up KeyConfigurator.
         * @param minLength Minimum symbols in key.
         * @param maxLength Maximim symbols in key.
         * @param separator Separate character between symbols in key.
         */
        KeyConfiguratorImpl(size_t minLength, size_t maxLength, const Character &separator) :
            minLength(minLength),
            maxLength(maxLength),
            separator(separator)
        {
            assert(this->minLength < this->maxLength && "Minimum length must be smaller than maximum length.");
        }

        /**
         * Gets minimum symbols set for key.
         */
        size_t getMinLength() const
        {
            return minLength;
        }

        /**
         * Gets maximum symbols set for key.
         */
        size_t getMaxLength() const
        {
            return maxLength;
        }

        /**
         * Gets separator between symbols in key.
         */
        Character getSeparator() const
        {
            return separator;
        }

    private:
        size_t minLength;

        size_t maxLength;

        Character separator;
    };
} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/

#endif /* KEYCONFIGURATORIMPL_H_ */
