#include "include/ProcessWCount.h"

ProcessWCount::ProcessWCount(const std::string& file, 
                             const std::string& word,
							 std::uintmax_t file_size):
                             m_fileName{file},
                             m_word{word},
							 m_file_size{file_size}
							 {}

ProcessWCount::~ProcessWCount() {
	if(m_file.is_open())
		m_file.close();
}

void ProcessWCount::init() {
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

void ProcessWCount::run() {
	if(is_FileEmpty(m_file_size))
		return;

	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("The file: '")
			+ m_fileName
			+"' is not open"
		);

	char ch;
	std::size_t n_words{0};
	bool wrong_word{false};
	while(m_file.read((char*)&ch, sizeof(ch))){
		switch (ch)
		{
		case '\n':
		case '\t':
		case  ' ':
			wrong_word = false;
			// std::cout << "n_words = " << n_words << std::endl;
			if(n_words == m_word.size())
				++m_count;
			// std::cout << "m_count = " << m_count << std::endl;
			n_words = 0;
			break;
		default:
			if(wrong_word){
				// std::cout << "[BAD word]: " << ch <<std::endl;
				continue;
			}
			if(n_words > m_word.size() - 1){
				// std::cout << "[OVER Char]: " << ch <<std::endl;
				wrong_word = true;
				n_words = 0;
				continue;
			}
			if(ch != m_word.at(n_words)){
				// std::cout << "[BAD Char]: " << ch << " != " << m_word.at(n_words)<<std::endl;
				wrong_word = true;
				n_words = 0;
				continue;
			}
			++n_words;
			// std::cout << "[OK Char]: " << ch <<std::endl;
			break;
		}
	}
	if(n_words == m_word.size())
		++ m_count;
}

void ProcessWCount::print(std::ostream& os) const {
	os << m_count << std::endl;
}

std::string ProcessWCount::getResult() const { 
	return std::to_string(m_count);
}
