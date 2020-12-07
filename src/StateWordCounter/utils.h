/**
 * @file utils.h
 * @author Никитин Сергей ()
 * @brief Вспомогательные функции для перехода между состояниями
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __UTILS_H__
#define __UTILS_H__

/**
 * @brief Определяет конец слова
 * 
 * @param ch 
 * @return true 
 * @return false 
 */
[[nodiscard]] inline bool isEoW(char ch) {
    switch (ch)
    {
    case '\r': // для работы с CRLF завершением строк
    case '\n':
    case '\t':
    case ' ':
        return true;
    default:
        return false;
    }
}

/**
 * @brief Определяет пунктуацию после слова
 * 
 * @param ch 
 * @return true 
 * @return false 
 */
[[nodiscard]] inline bool isEndPunctuation(char ch) {
    switch (ch)
    {
    case ':':
    case ';':
    case '!':
    case '?':
    case ',':
    case '.':
        return true;
    default:
        return false;
    }
}

[[nodiscard]] inline bool isBeginScope(char ch) {
    switch (ch)
    {
    case '(':
    case '{':
    case '[':
    case '<':
        return true;
    default:
        return false;
    }
}

[[nodiscard]] inline bool isEndScope(char ch) {
    switch (ch)
    {
    case ')':
    case '}':
    case ']':
    case '>':
        return true;
    default:
        return false;
    }
}

[[nodiscard]] inline bool isQuotes(char ch){
    switch (ch)
    {
    case '"':
    case '\'':
    case '`':
        return true;
    default:
        return false;
    }
}

#endif // __UTILS_H__