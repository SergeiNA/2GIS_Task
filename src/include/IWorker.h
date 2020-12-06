/**
 * @file IWorker.h
 * @author Сергей Никитин (.)
 * @brief Содеожит интрефейс класса "Process" через который 
 * будет реализован основной функционал программы
 * @version 1.0
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __IPROCESS_H__
#define __IPROCESS_H__

#include "common.h"

#include <iostream>

class IWorker {
    public:
        virtual ~IWorker() 									    = default;
		virtual void init()										= 0;
        virtual void run()										= 0;
        virtual void print(std::ostream& os = std::cout) const	= 0;
        virtual std::string getResult() const					= 0;
};

#endif // __IPROCESS_H__
