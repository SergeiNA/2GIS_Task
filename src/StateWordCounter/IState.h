/**
 * @file IState.h
 * @author Никитин Сергей ()
 * @brief Интерфейс состояний
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __ISTATE_H__
#define __ISTATE_H__

#include <string>

class Context;

class IState {
    public:
        virtual void onChar (char key) = 0;
        virtual void onEnd  ()         = 0;
        virtual void clear  ()         = 0;
        virtual ~IState()              = default;

        void setContext(Context* context) {
            m_context = context;
        }

    protected:
        Context* m_context = nullptr;
};

#endif // __ISTATE_H__