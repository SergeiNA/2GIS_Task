#include "include/ProcessManager.h"
#include "include/ProcessWCount.h"
#include "include/ProcessCRC.h"

ProcessManager::ProcessManager(const Options& opt) {
	switch (opt.mode)
	{
	case MODE::WORD :
		m_process = std::make_unique<ProcessWCount>(opt.file, opt.word);
		break;
	case MODE::HASH :
		m_process = std::make_unique<ProcessCRC>(opt.file);
		break;
	default:
		throw std::invalid_argument("Unknown MODE");
		break;
	}
}

ProcessManager::~ProcessManager() {
	m_process.release();
}

void ProcessManager::start() {
	if(!m_process)
		throw std::invalid_argument ("Pointer to process is not initialized");

	m_process->init();
	m_process->run();
}

void ProcessManager::print(std::ostream& os) const {
	if(!m_process)
			throw std::invalid_argument ("Pointer to process is not initialized");
	m_process->print(os);
}
