#include "BeginScope.h"
#include "Context.h"
#include "Miscellanea.h"
#include "Resembling.h"
#include "NewWord.h"
#include "utils.h"

#include <iostream>

void BeginScope::onChar(char key) {
     #if defined(DEBUG) && defined(DEBUG_PRINT)
        std::cout << __PRETTY_FUNCTION__ << " [" << key << "] " 
              << "Find: " << m_context->m_countWords 
              <<  std::endl;
    #endif
    if(isBeginScope(key) || isQuotes(key)){
        return;
    }
    if(m_context->m_pattern.front() == key){
        clear();
        ++m_context->m_countKeys;
        m_context->changeState(std::make_unique<Resembling>());
        return;
    }
    if(isEoW(key)){
        m_context->changeState(std::make_unique<NewWord>());
    }
    m_context->changeState(std::make_unique<Miscellenea>());
}

void BeginScope::onEnd() {
    clear();
}

void BeginScope::clear() {
    m_context->m_countKeys = 0;
}
