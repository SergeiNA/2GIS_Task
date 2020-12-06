#include "Miscellanea.h"
#include "Context.h"
#include "NewWord.h"
#include "utils.h"

#include <iostream>

void Miscellenea::onChar(char key) {
     #if defined(DEBUG) && defined(DEBUG_PRINT)
            std::cout << __PRETTY_FUNCTION__ << " [" << key << "] " 
              << "Find: " << m_context->m_countWords 
              <<  std::endl;
    #endif
    if(isEoW(key)){
        clear();
        m_context->changeState(std::make_unique<NewWord>());
    }
}

void Miscellenea::onEnd() {
    return;
}

void Miscellenea::clear() {
    m_context->m_countKeys = 0;
}
