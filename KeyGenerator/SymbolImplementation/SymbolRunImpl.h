/*
 * SymbolRunImpl.h
 *
 *  Created on: 22.06.2013
 *      Author: grad
 */

#ifndef SYMBOLRUNIMPL_H_
#define SYMBOLRUNIMPL_H_

#include <string>
#include <memory>

namespace InnerImplementation
{
namespace SymbolImplementation
{

    template<typename Character>
    class SymbolRunImpl
    {
    public:
        SymbolRunImpl() = default;

        SymbolRunImpl(const std::basic_string<Character> &data) :
            run(data),
            prevSymbol(nullptr)
        {
        }

        SymbolRunImpl(const SymbolRunImpl<Character> &value) = default;

        ~SymbolRunImpl()
        {
        }

        void setPreviousSymbol(const std::basic_string<Character> &nextData)
        {
            this->prevSymbol.reset(new SymbolRunImpl<Character>(nextData));
        }

        size_t getSymbolLength() const
        {
            return this->run.size();
        }

        SymbolRunImpl<Character>* getPreviousSymbol() const
        {
            return this->prevSymbol.get();
        }

        bool HasPreviousSymbol() const
        {
            return this->prevSymbol.get() != nullptr;
        }

        void operator =(const SymbolRunImpl<Character> &value)
        {
            this->run = value.run;
        }

        operator const Character*() const
        {
            return this->run.c_str();
        }

        bool operator ==(const SymbolRunImpl<Character> &value) const
        {
            return this->run == value.run;
        }

    private:
        std::basic_string<Character> run;

        std::unique_ptr<SymbolRunImpl<Character>> prevSymbol;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */
#endif /* SYMBOLRUNIMPL_H_ */
