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