/**
 * @file EndScope.h
 * @author Никитин Сергей ()
 * @brief Класс состояния разбора закрывающихся скобок
 * или кавычек
 * Переходы:
 *  - loopback
 *  - NewWord
 *  - Miscellenea
 *  - PEndMarks
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __ENDSCOPE_H__
#define __ENDSCOPE_H__

#include "IState.h"

class EndScope: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~EndScope() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __ENDSCOPE_H__