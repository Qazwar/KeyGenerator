/*
 * RuleMaker.h
 *
 *  Created on: 23.06.2013
 *      Author: grad
 */

#ifndef RULEMAKER_H_
#define RULEMAKER_H_

#include <RuleMakerImpl.h>

namespace InnerImplementation
{

    typedef RuleMakerImpl<char> RuleMaker;

    typedef RuleMakerImpl<wchar_t> RuleMakerWide;

}


#endif /* RULEMAKER_H_ */
