/**
 * @file AppOptions.h
 * @author Сергей Никитин (.)
 * @brief Функции для работы с аргументами строки
 * @version 1.0
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __APPOPTIONS_H__
#define __APPOPTIONS_H__

#include "common.h"

#include <boost/program_options.hpp>
#include <string>
#include <optional>

/**
 * @brief Получение опций программы из параметров командной строки
 * 
 * @param argc - количество параметров
 * @param argv - список параметров
 * @return std::optional<Options> возможные параметры программы
 */
std::optional<Options> getProgrammOptions(int argc, const char *argv[]);

#endif // __APPOPTIONS_H__
