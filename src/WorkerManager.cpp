#include "WorkerManager.h"
#include "WorkerWCount.h"
#include "WorkerStateWCount.h"
#include "WorkerCRC.h"

WorkerManager::WorkerManager(const Options& opt) {
	switch (opt.mode)
	{
	case MODE::WORD :
		// m_process = std::make_unique<WorkerWCount>(opt.file, opt.word, opt.file_size);
		m_process = std::make_unique<WorkerStateWCount>(opt.file, opt.word, opt.file_size);
		break;
	case MODE::HASH :
		m_process = std::make_unique<WorkerCRC>(opt.file, opt.file_size);
		break;
	default:
		throw std::invalid_argument("Unknown MODE");
		break;
	}
}

WorkerManager::~WorkerManager() {
}

void WorkerManager::start() {
	if(!m_process)
		throw std::invalid_argument ("Pointer to process is not initialized");
	m_process->init();
	m_process->run();
}

void WorkerManager::print(std::ostream& os) const {
	if(!m_process)
			throw std::invalid_argument ("Pointer to process is not initialized");
	m_process->print(os);
}
