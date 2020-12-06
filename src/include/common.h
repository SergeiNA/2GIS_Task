/**
 * @file common.h
 * @author Сергей Никитин (.)
 * @brief Общие типы данных и функции, используемые в программе
 * @version 1.0
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>

/**
 * @brief Перечисления режимов работы программы
 * 
 */
enum class MODE: uint16_t {
	HASH, ///< Подсчёт хеш суммы
	WORD  ///< Подсчёт повторений заданного слова
};

/**
 * @brief Опции программы
 * 
 */
struct Options {
	std::string file        {""};			///< Название файла
	std::uintmax_t file_size {0};			///< Размер файла
	MODE mode               {MODE::HASH};	///< Режим работы
	std::string word        {""};			///< Слово для подсчёта
};

inline bool is_FileEmpty(std::uintmax_t fsize) {
	return fsize == 0;
}



#endif // __COMMON_H__
