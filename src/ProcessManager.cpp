#include "include/ProcessManager.h"

ProcessManager::ProcessManager(const Options& opt)
{
	
}

ProcessManager::~ProcessManager()
{
	
}

bool ProcessManager::start() {
	if(!m_process)
		return false;
	
	m_process->run();
	return true;
}

bool ProcessManager::print() const {
	if(!m_process)
			return false;
	m_process->print();
	return true;
}