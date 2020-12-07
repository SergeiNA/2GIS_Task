/**
 * @file Context.h
 * @author Никитин Сергей ()
 * @brief Контекст для работы машины состояний 
 * для подсчёта слов в файле
 * Включает состояние и текущие 
 * данные по искомому слову
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
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
        uint64_t    m_countWords {0};   ///< Количество найденных слов
        uint64_t    m_countKeys  {0};   ///< Количество совпавших букв
        std::string m_pattern    {""};  ///< Искомое слово
    private:
        std::unique_ptr<IState> m_state = nullptr;
};

#endif // __CONTEXT_H__