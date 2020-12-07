/**
 * @file BeginScope.h
 * @author Никитин Сергей ()
 * @brief Класс состояния разбора открывающихся скобок
 * или кавычек
 * Переходы:
 *  - Resembling
 *  - NewWord
 *  - Miscellenea
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __BEGINSCOPE_H__
#define __BEGINSCOPE_H__

#include "IState.h"

class BeginScope: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~BeginScope() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __BEGINSCOPE_H__