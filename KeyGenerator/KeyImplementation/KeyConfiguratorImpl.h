/*
 * KeyConfigurator.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef KEYCONFIGURATORIMPL_H_
#define KEYCONFIGURATORIMPL_H_

#include <cassert>

namespace InnerImplementation
{
namespace KeyImplementation
{
    /**
     * Entity that contains information about key.
     * template parameter Character is char that used for Key as string.
     */
    template<typename Character = char>
    class KeyConfiguratorImpl
    {
    public:
        /**
         * Constructor for setting up KeyConfigurator.
         * @param minLength Minimum symbols in key.
         * @param maxLength Maximim symbols in key.
         * @param separator Separate character between symbols in key.
         */
        KeyConfiguratorImpl(int minLength, int maxLength, const Character &separator) :
            minLength(minLength),
            maxLength(maxLength),
            separator(separator)
        {
            assert(this->minLength < this->maxLength && "Minimum length must be smaller than maximum length.");
        }

        /**
         * Gets minimum symbols set for key.
         */
        int getMinLength() const
        {
            return minLength;
        }

        /**
         * Gets maximum symbols set for key.
         */
        int getMaxLength() const
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
        int minLength;

        int maxLength;

        Character separator;
    };
} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/

#endif /* KEYCONFIGURATORIMPL_H_ */
