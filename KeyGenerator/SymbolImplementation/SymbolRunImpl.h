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

#include "../RuleMakerImpl/RuleMakerImpl.h"

namespace InnerImplementation
{

namespace SymbolImplementation
{

    template<typename Character,
             typename TRuleMaker=InnerImplementation::RuleMakerImpl<Character>>
    class SymbolRunImpl
    {
    public:
        SymbolRunImpl() = default;

        SymbolRunImpl(const std::basic_string<Character> &data) :
            run(data),
            prevSymbol(nullptr)
        {
        }

        SymbolRunImpl(const SymbolRunImpl<Character, TRuleMaker> &value) = default;

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

        inline typename std::basic_string<Character>::const_iterator getBegin() const
        {
            return std::begin(this->run);
        }

        inline typename std::basic_string<Character>::const_iterator getEnd() const
        {
            return std::end(this->run);
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

        void operator ++()
        {
            const SymbolConfiguratorImpl<Character> *config = TRuleMaker::getSymbolRule();

            if (run.compare(config->getEndSymbol()) == 0)
            {
                run = config->getStartSymbol();
                if (HasPreviousSymbol())
                {
                    ++(*prevSymbol);
                }
                else
                {
                    this->setPreviousSymbol(config->getStartSymbol());
                }
            }
            else
            {
                std::basic_string<Character> terminate(config->getTerminalCharacters());
                std::basic_string<Character> wrong(config->getWrongCharacters());

                bool end = false;
                size_t rIndex = run.size()-1;
                typename std::basic_string<Character>::reverse_iterator runIter = run.rbegin();
                while (!end)
                {
                    if (std::find(std::begin(terminate), std::end(terminate), *runIter) != std::end(terminate))
                    {
                        *runIter = *(std::begin(config->getStartSymbol()) + rIndex);
                        ++runIter;
                    }
                    else
                    {
                        do
                        {
                            ++(*runIter);
                        }
                        while(std::find(std::begin(wrong), std::end(wrong), *runIter) != std::end(wrong));
                        end = true;
                    }
                }
            }
        }

    private:
        std::basic_string<Character> run;

        std::unique_ptr<SymbolRunImpl<Character>> prevSymbol;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */
#endif /* SYMBOLRUNIMPL_H_ */
