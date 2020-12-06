#include "EndScope.h"
#include "PEndMarks.h"
#include "Context.h"
#include "Miscellanea.h"
#include "NewWord.h"
#include "utils.h"

#include <iostream>

void EndScope::onChar(char key) 
{
     #if defined(DEBUG) && defined(DEBUG_PRINT)
            std::cout << __PRETTY_FUNCTION__ << " [" << key << "] " 
              << "Find: " << m_context->m_countWords 
              <<  std::endl;
    #endif
    clear();
    if(isEoW(key)){
        ++m_context->m_countWords;
         m_context->changeState(std::make_unique<NewWord>());
         return;
    }
    if(isEndPunctuation(key)){
        m_context->changeState(std::make_unique<PEndMarks>());
        return;
    }
    if(!(isEndScope(key) || isQuotes(key)))
        m_context->changeState(std::make_unique<Miscellenea>());
}

void EndScope::onEnd() 
{
    clear();
    ++m_context->m_countWords;
}

void EndScope::clear() 
{
    m_context->m_countKeys = 0;
}
