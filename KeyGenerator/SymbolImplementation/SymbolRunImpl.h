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
        SymbolRunImpl(const std::basic_string<Character> &data) :
            run(data),
            prevSymbol(nullptr)
        {
        }

        ~SymbolRunImpl()
        {
        }

        void setPreviousSymbol(const std::basic_string<Character> &nextData)
        {
            this->prevSymbol.reset(new SymbolRunImpl<Character>(nextData));
        }

        SymbolRunImpl<Character>* getPreviousSymbol()
        {
            return this->prevSymbol.get();
        }

        bool HasPreviousSymbol()
        {
            return this->prevSymbol.get() != nullptr;
        }

        operator const Character*()
        {
            return this->run.c_str();
        }

    private:
        std::basic_string<Character> run;

        std::unique_ptr<SymbolRunImpl<Character>> prevSymbol;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */
#endif /* SYMBOLRUNIMPL_H_ */
