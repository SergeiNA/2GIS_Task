#ifndef __PROCESSWCOUNT_H__
#define __PROCESSWCOUNT_H__
#include "IProcess.h"

class ProcessWCount:public IProcess
{
public:
    ProcessWCount(const std::string file, 
                  const std::string word);
    ~ProcessWCount();

    [[nodiscard]]	bool run()		override;
    [[nodiscard]]	bool print()	override;
    std::string getResult() const 	override;
private:
    std::string m_file;
    std::string m_word;
    uint64_t    m_count{0};
};




#endif // __PROCESSWCOUNT_H__