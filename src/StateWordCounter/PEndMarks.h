/**
 * @file PEndMarks.h
 * @author Никитин Сергей ()
 * @brief Класс состояния знаков пунктуации после слова
 *  * Переходы:
 *  - NewWord
 *  - Miscellanea
 *  - EndScope
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __PMARKS_H__
#define __PMARKS_H__

#include "IState.h"

class PEndMarks: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~PEndMarks() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __PMARKS_H__