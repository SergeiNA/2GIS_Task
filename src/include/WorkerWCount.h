/**
 * @file WorkerWCount.h
 * @author Сергей Никитин (.)
 * @brief Содержит объявление класса для подсчёта 
 * повторений заданного слова в файле.
 * В данной реализации используется простой алгоритм,
 * который не поддерживает логики для определения 
 * знаков препинания, скобок и кавычек. 
 * Быстрый и простой.
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __PROCESSWCOUNT_H__
#define __PROCESSWCOUNT_H__
#include "IWorker.h"
#include <fstream>

class WorkerWCount:public IWorker {
public:
    WorkerWCount(const std::string& file, 
                  const std::string& word,
                  std::uintmax_t file_size);
    ~WorkerWCount();

	void init()								 override;
    void run()								 override;
    void print(std::ostream& os = std::cout) const override;
    std::string getResult() 				 const override;
private:
    void processFile();
private:
    std::string 	m_fileName;
    std::string 	m_word;
    std::uintmax_t  m_file_size;
    std::ifstream 	m_file;
    uint64_t 		m_count{0};
};

#endif // __PROCESSWCOUNT_H__
