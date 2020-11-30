#ifndef __APPOPTIONS_H__
#define __APPOPTIONS_H__

#include "common.h"

#include <boost/program_options.hpp>
#include <string>
#include <optional>

std::optional<Options> getProgrammOptions(int argc, const char *argv[]);

#endif // __APPOPTIONS_H__