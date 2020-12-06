#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "IState.h"
#include <memory>
class Context{
    public:
        Context(const std::string& pattern);
        void        onChar      (char number);
        void        onEnd       ();
        void        clear       ();
        void        changeState (std::unique_ptr<IState> state);
        uint64_t    getFound    () const;
    public:
        char        m_key        {0};
        uint64_t    m_countWords {0};
        uint64_t    m_countKeys  {0};
        std::string m_pattern    {""};
    private:
        std::unique_ptr<IState> m_state = nullptr;
};

#endif // __CONTEXT_H__