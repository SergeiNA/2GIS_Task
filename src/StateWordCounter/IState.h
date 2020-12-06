#ifndef __ISTATE_H__
#define __ISTATE_H__

#include <string>

class Context;

class IState {
    public:
        virtual void        onChar (char key)     = 0;
        virtual void        onEnd       ()        = 0;
        virtual void        clear       ()        = 0;
        virtual ~IState() = default;

        void setContext(Context* context) {
            m_context = context;
        }

    protected:
        Context* m_context = nullptr;
};

#endif // __ISTATE_H__