#include "NewWord.h"
#include "Context.h"
#include "Resembling.h"
#include "Miscellanea.h"
#include "BeginScope.h"
#include "utils.h"

#include <iostream>

void NewWord::onChar(char key) {
     #if defined(DEBUG) && defined(DEBUG_PRINT)
            std::cout << __PRETTY_FUNCTION__ << " [" << key << "] " 
              << "Find: " << m_context->m_countWords 
              <<  std::endl;
    #endif
    clear();
    if(m_context->m_pattern.front() == key){
        ++m_context->m_countKeys;
        m_context->changeState(std::make_unique<Resembling>());
        return;
    }

    if(isBeginScope(key) || isQuotes(key)){
        m_context->changeState(std::make_unique<BeginScope>());
        return;
    }

    if(!isEoW(key)){
        clear();
        m_context->changeState(std::make_unique<Miscellenea>());
        return;
    }
}

void NewWord::onEnd() {
    return;
}

void NewWord::clear() {
    m_context->m_countKeys =0;
}
