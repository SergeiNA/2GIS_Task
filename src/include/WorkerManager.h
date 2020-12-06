/**
 * @file WorkerManager.h
 * @author Сергей Никитин (.)
 * @brief Содержит объявление класса для работы с различными процессами
 * @version 1.0
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __PROCESSMANAGER_H__
#define __PROCESSMANAGER_H__

#include "IWorker.h"

#include <memory>

class WorkerManager {
    using pIWorker  = std::unique_ptr<IWorker>;
public:
    WorkerManager(const Options& opt);
    ~WorkerManager();
    void start();
    void print(std::ostream& os = std::cout) const;
private:
    pIWorker  m_process;
    Options   m_options;
    bool      m_isRun{false};
};

#endif // __PROCESSMANAGER_H__
