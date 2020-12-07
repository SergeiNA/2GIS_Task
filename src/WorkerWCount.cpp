#include "WorkerWCount.h"

WorkerWCount::WorkerWCount(const std::string& file, 
                             const std::string& word,
							 std::uintmax_t file_size):
                             m_fileName{file},
                             m_word{word},
							 m_file_size{file_size}
							 {}

WorkerWCount::~WorkerWCount() {
	if(m_file.is_open())
		m_file.close();
}

void WorkerWCount::init() {
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

void WorkerWCount::run() {
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

void WorkerWCount::print(std::ostream& os) const {
	os << m_count << std::endl;
}

std::string WorkerWCount::getResult() const { 
	return std::to_string(m_count);
}

void WorkerWCount::processFile() 
{
	char ch;
	std::size_t n_letter{0};
	bool misc_word{false};
	while(m_file.get(ch)){
		switch (ch)
		{
		case '\r':
		case '\n':
		case '\t':
		case  ' ':
			misc_word = false;
			if(n_letter == m_word.size())
				++m_count;
			n_letter = 0;
			break;
		default:
			if(misc_word){
				continue;
			}
			if(n_letter > m_word.size() - 1){
				misc_word = true;
				n_letter = 0;
				continue;
			}
			if(ch != m_word.at(n_letter)){
				misc_word = true;
				n_letter = 0;
				continue;
			}
			++n_letter;
			break;
		}
	}
	if(n_letter == m_word.size())
		++ m_count;
}
