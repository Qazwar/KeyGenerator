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

    /**
     * Entity which contains character set of key symbol.
     * By symbol run I mean characters between key separator.
     * @tparam Character Type of character in key.
     * @tparam Type of class with static methods
     * for getting rules of key and symbol in key construction.
     */
    template<typename Character,
             typename TRuleMaker=InnerImplementation::RuleMakerImpl<Character>>
    class SymbolRunImpl
    {
    public:
        SymbolRunImpl() = default;

        /**
         * Constructor which saves specified character set in SymbolRun.
         * @param data String for holding in SymbolRun.
         */
        SymbolRunImpl(const std::basic_string<Character> &data) :
            run(data),
            prevSymbol(nullptr)
        {
        }

        SymbolRunImpl(const SymbolRunImpl<Character, TRuleMaker> &value) = default;

        ~SymbolRunImpl()
        {
        }

        /**
         * Sets SymbolRun before this with specified text.
         * @param nextData String for previous SymbolRun.
         */
        void setPreviousSymbol(const std::basic_string<Character> &nextData)
        {
            this->prevSymbol.reset(new SymbolRunImpl<Character, TRuleMaker>(nextData));
        }

        /**
         * Gets SymbolRun before this.
         * @return Previous symbol.
         */
        SymbolRunImpl<Character, TRuleMaker>* getPreviousSymbol() const
        {
            return this->prevSymbol.get();
        }

        /**
         * Gets count of characters in symbol.
         * @retrun count of characters.
         */
        size_t getSymbolLength() const
        {
            return this->run.size();
        }

        /*
         * Gets whether symbol has previous symbol.
         * @return true if it has, otherwise false.
         */
        bool HasPreviousSymbol() const
        {
            return this->prevSymbol.get() != nullptr;
        }

        /**
         * Gets begin iterator of held character set.
         * @return begin iterator.
         */
        inline typename std::basic_string<Character>::const_iterator getBegin() const
        {
            return std::begin(this->run);
        }

        /**
         * Gets last iterator of held character set.
         * @return last iterator.
         */
        inline typename std::basic_string<Character>::const_iterator getEnd() const
        {
            return std::end(this->run);
        }

        /**
         * Overloads operator =.
         */
        void operator =(const SymbolRunImpl<Character, TRuleMaker> &value)
        {
            this->run = value.run;
        }

        /**
         * Overloads operator for casting to "const Character*".
         */
        operator const Character*() const
        {
            return this->run.c_str();
        }

        /**
         * Overloads equal operator.
         */
        bool operator ==(const SymbolRunImpl<Character, TRuleMaker> &value) const
        {
            return this->run == value.run;
        }

        /**
         * Overloads increment operator for generating key with other character set.
         */
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
                        --rIndex;
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

        std::unique_ptr<SymbolRunImpl<Character, TRuleMaker>> prevSymbol;
    };

} /* namespace SymbolImplementation */
} /* namespace InnerImplementation */
#endif /* SYMBOLRUNIMPL_H_ */
