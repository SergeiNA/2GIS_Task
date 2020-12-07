/**
 * @file WorkerCRC.h
 * @author Сергей Никитин (.)
 * @brief Содержит объявление класса для подсчёта CRC по 32-битным словам
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __PROCESSCRC_H__
#define __PROCESSCRC_H__

#include "IWorker.h"
#include <fstream>

class WorkerCRC: public IWorker {
public:
    WorkerCRC(const std::string&   file,
                     std::uintmax_t file_size);
    ~WorkerCRC();

	void init()									override;
    void run()									override;
    void print(std::ostream& os = std::cout)	const override;
    std::string getResult() 					const override;
private:
    bool		   m_isRun {false};
    std::string    m_fileName;
    std::uintmax_t m_file_size;
	std::ifstream  m_file;
	uint32_t       m_CRC   {0};
};

#endif // __PROCESSCRC_H__
