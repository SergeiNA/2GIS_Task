/**
 * @file Resembling.h
 * @author Никитин Сергей ()
 * @brief Класс состояние совпадения 
 * символов искомого слова. 
 * Переходы:
 *  - loopback
 *  - NewWord
 *  - Miscellanea
 *  - EndScope
 *  - PEndMarks
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __RESEMBLING_H__
#define __RESEMBLING_H__

#include "IState.h"

class Resembling: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~Resembling() = default;

        void setContext(Context* context){
            m_context = context;
        }
    private:
        // Вспомогательные методы для улучшения читаемости кода
        [[nodiscard]] bool isFullWord()           const;
        [[nodiscard]] bool isOverFlow()           const;
        [[nodiscard]] bool isMiscLetter(char key) const;
};

#endif // __RESEMBLING_H__