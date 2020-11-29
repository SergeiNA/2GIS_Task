#ifndef __APPOPTIONS_H__
#define __APPOPTIONS_H__
#include <boost/program_options.hpp>
#include <string>
#include <optional>

enum class MODE{
    HASH,
    WORD
};

struct Options{
    std::string file;
    std::string mode;
    std::string word;
};


std::optional<Options> getProgrammOptions(int argc, const char *argv[]);

#endif // __APPOPTIONS_H__