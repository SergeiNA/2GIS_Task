/**
 * @file NewWord.h
 * @author Никитин Сергей ()
 * @brief Класс состояния разбора нового слова
 *  * Переходы:
 *  - loopback
 *  - Miscellanea
 *  - Resembling
 *  - BeginScope
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __NEWWORD_H__
#define __NEWWORD_H__

#include "IState.h"

class NewWord: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~NewWord() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __NEWWORD_H__