/**
 * @file Miscellanea.h
 * @author Никитин Сергей ()
 * @brief Класс состояния пропуска несовпадающего слова
 * Переходы:
 *  - loopback
 *  - NewWord
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __MISCELLANEA_H__
#define __MISCELLANEA_H__

#include "IState.h"

class Miscellenea: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~Miscellenea() = default;

        void setContext(Context* context) {
            m_context = context;
        }
};

#endif // __MISCELLANEA_H__