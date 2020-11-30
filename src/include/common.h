#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>

enum class MODE{
    HASH,
    WORD
};

struct Options{
    std::string file;
    std::string mode;
    std::string word;
};

#endif // __COMMON_H__