#ifndef __UTILS_H__
#define __UTILS_H__

inline bool isEoW(char ch) {
    switch (ch)
    {
    case '\r':
    case '\n':
    case '\t':
    case ' ':
        return true;
    default:
        return false;
    }
}

inline bool isEndPunctuation(char ch) {
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

inline bool isBeginScope(char ch) {
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

inline bool isEndScope(char ch) {
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

inline bool isQuotes(char ch){
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