#ifndef __PROCESSMANAGER_H__
#define __PROCESSMANAGER_H__

#include "IProcess.h"

#include <memory>

class ProcessManager
{
    using pIProcess  = std::unique_ptr<IProcess>;
public:
    ProcessManager(const Options& opt);
    ~ProcessManager();
    [[nodiscard]]	bool start();
    [[nodiscard]]	bool print() const;
private:
    pIProcess m_process;
    Options   m_options;
    bool      m_isRun{false};
};




#endif // __PROCESSMANAGER_H__