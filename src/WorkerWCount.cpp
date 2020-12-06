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
	std::size_t n_words{0};
	bool wrong_word{false};
	while(m_file.get(ch)){
		switch (ch)
		{
		case '\n':
		case '\t':
		case  ' ':
			wrong_word = false;
			if(n_words == m_word.size())
				++m_count;
			n_words = 0;
			break;
		default:
			if(wrong_word){
				continue;
			}
			if(n_words > m_word.size() - 1){
				wrong_word = true;
				n_words = 0;
				continue;
			}
			if(ch != m_word.at(n_words)){
				wrong_word = true;
				n_words = 0;
				continue;
			}
			++n_words;
			break;
		}
	}
	if(n_words == m_word.size())
		++ m_count;
}
