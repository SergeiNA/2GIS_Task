#include "PEndMarks.h"
#include "Context.h"
#include "Miscellanea.h"
#include "EndScope.h"
#include "NewWord.h"
#include "utils.h"

#include <iostream>

void PEndMarks::onChar(char key) 
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
    if(isEndScope(key)){
        m_context->changeState(std::make_unique<EndScope>());
        return;
    }
    m_context->changeState(std::make_unique<Miscellenea>());
}

void PEndMarks::onEnd() 
{
    clear();
    ++m_context->m_countWords;
}

void PEndMarks::clear() 
{
    m_context->m_countKeys =0;
}
