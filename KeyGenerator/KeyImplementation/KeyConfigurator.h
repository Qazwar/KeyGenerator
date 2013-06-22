/*
 * KeyConfigurator.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef KEYCONFIGURATOR_H_
#define KEYCONFIGURATOR_H_

#include <cassert>

namespace InnerImplementation
{
namespace KeyImplementation
{
    template<typename Data>
    class KeyConfigurator
    {
    public:

        KeyConfigurator(int minLength, int maxLength, const Data &separate) :
            minLength(minLength),
            maxLength(maxLength),
            separator(separate)
        {
            assert(this->minLength < this->maxLength && "Minimum length must be smaller than maximum length.");
        }

        int getMinLength() const
        {
            return minLength;
        }

        int getMaxLength() const
        {
            return maxLength;
        }

        Data getSeparator() const
        {
            return separator;
        }

    private:
        int minLength;

        int maxLength;

        Data separator;
    };
} /* namespace KeyImplementation */
} /* namespace InnerImplementation*/

#endif /* KEYCONFIGURATOR_H_ */
