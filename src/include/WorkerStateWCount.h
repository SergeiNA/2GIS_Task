/**
 * @file WorkerStateWCount.h
 * @author Никитин Сергей ()
 * @brief Содержит объявление класса для подсчёта 
 * повторений заданного слова в файле.
 * Реализован на паттерне "Машина состояний" .
 * В отличии от простого решения может находить слова
 * по алгоритму с более сложной логикой, что позволяет
 * учиывать знаки пунктуации, скобки и кавычки.
 * Гибкий в расширении, но медленее "простого алгоритма"
 * в виду использования виртуальных функций и опреций 
 * перемещения контекста.
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __WORKERSTATEWCOUNT_H__
#define __WORKERSTATEWCOUNT_H__

#include "IWorker.h"
#include "../StateWordCounter/Context.h"
#include <fstream>

class WorkerStateWCount:public IWorker {
public:
    WorkerStateWCount(const std::string& file, 
                  const std::string& word,
                  std::uintmax_t file_size);
    ~WorkerStateWCount();

	void init()								 override;
    void run()								 override;
    void print(std::ostream& os = std::cout) const override;
    std::string getResult() 				 const override;
private:
    void processFile();
private:
    Context         m_context;
    std::string 	m_fileName;
    std::uintmax_t  m_file_size;
    std::ifstream 	m_file;
};

#endif // __WORKERSTATEWCOUNT_H__