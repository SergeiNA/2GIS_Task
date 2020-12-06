#include "WorkerStateWCount.h"

WorkerStateWCount::WorkerStateWCount(const std::string& file, 
                             const std::string& word,
							 std::uintmax_t file_size):
                             m_context{word},
                             m_fileName{file},
							 m_file_size{file_size}
							 {}

WorkerStateWCount::~WorkerStateWCount() {
	if(m_file.is_open())
		m_file.close();
}

void WorkerStateWCount::init() {
	if(is_FileEmpty(m_file_size))
		return;

	m_file.open(m_fileName, std::ios::in );
	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("Cannot open the file: '")
			+ m_fileName
			+"'."
		);
}

void WorkerStateWCount::run() {
	if(is_FileEmpty(m_file_size))
		return;

	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("The file: '")
			+ m_fileName
			+"' is not open"
		);
    processFile();
}

void WorkerStateWCount::print(std::ostream& os) const {
	os << m_context.getFound() << std::endl;
}

std::string WorkerStateWCount::getResult() const { 
	return std::to_string(m_context.getFound());
}

void WorkerStateWCount::processFile() 
{	
    char ch;
	while(m_file.get(ch)){
		m_context.onChar(ch);
	}
    m_context.onEnd();
}
