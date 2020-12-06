#include "Context.h"
#include "NewWord.h"

Context::Context(const std::string& pattern) : m_pattern{pattern} {
    clear();
}

void Context::onChar(char number) {
    m_state->onChar(number);
}

void Context::onEnd() {
    m_state->onEnd();
}

void Context::clear() {
    m_state = std::make_unique<NewWord>();
    m_state->setContext(this);
}

void Context::changeState(std::unique_ptr<IState> state) {
    m_state = std::move(state);
    m_state->setContext(this);
}

uint64_t Context::getFound() const {
    return m_countWords;
}
