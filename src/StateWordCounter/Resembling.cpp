#include "Resembling.h"
#include "Context.h"
#include "PEndMarks.h"
#include "EndScope.h"
#include "Miscellanea.h"
#include "NewWord.h"
#include "utils.h"

#include <iostream>

bool Resembling::isFullWord() const {
    return m_context->m_countKeys == m_context->m_pattern.size();
}

bool Resembling::isOverFlow() const {
    return m_context->m_countKeys > (m_context->m_pattern.size() - 1);
}

bool Resembling::isMiscLetter(char key) const {
    return m_context->m_pattern.at(m_context->m_countKeys) != key;
}

void Resembling::onChar(char key) {
    #if defined(DEBUG) && defined(DEBUG_PRINT)
        std::cout << __PRETTY_FUNCTION__ << " [" << key << "] " 
              << "Find: " << m_context->m_countWords 
              <<  std::endl;
    #endif

    if(isEoW(key) && isFullWord()) {
        ++m_context->m_countWords;
        clear();
        m_context->changeState(std::make_unique<NewWord>());
        return;
    }

    if(isFullWord() && isEndPunctuation(key)) {
        clear();
        m_context->changeState(std::make_unique<PEndMarks>());
        return;
    }

    if(isFullWord() && (isEndScope(key) || isQuotes(key))) {
        clear();
        m_context->changeState(std::make_unique<EndScope>());
        return;
    }

    if(isOverFlow() || isMiscLetter(key)) {
        clear();
        m_context->changeState(std::make_unique<Miscellenea>());
        return;
    }
    ++m_context->m_countKeys;
}

void Resembling::onEnd() {
    if(m_context->m_countKeys 
        == m_context->m_pattern.size()){
        ++m_context->m_countWords;
        }
}

void Resembling::clear() {
    m_context->m_countKeys =0;
}
