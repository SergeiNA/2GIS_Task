/**
 * @file ProcessCRC.h
 * @author Сергей Никитин (.)
 * @brief Содержит объявление класса для подсчёта CRC
 * @version 1.0
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __PROCESSCRC_H__
#define __PROCESSCRC_H__

#include "IProcess.h"
#include <fstream>

class ProcessCRC: public IProcess {
public:
    ProcessCRC(const std::string& file);
    ~ProcessCRC();

	void init()									override;
    void run()									override;
    void print(std::ostream& os = std::cout)	const override;
    std::string getResult() 					const override;
private:
    bool		  m_isRun {false};
    std::string   m_fileName;
	std::ifstream m_file;
	uint32_t      m_CRC;
};

#endif // __PROCESSCRC_H__
