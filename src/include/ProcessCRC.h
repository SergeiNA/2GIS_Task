#ifndef __PROCESSCRC_H__
#define __PROCESSCRC_H__

#include "IProcess.h"

class ProcessCRC:public IProcess
{
public:

    ProcessCRC(const std::string file);
    ~ProcessCRC();

    [[nodiscard]] bool run()		override;
    [[nodiscard]] bool print()		override;
    std::string getResult() const 	override;
private:
    bool      m_isRun{false};
};



#endif // __PROCESSCRC_H__