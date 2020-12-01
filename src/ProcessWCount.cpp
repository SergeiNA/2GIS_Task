#include "include/ProcessWCount.h"

ProcessWCount::ProcessWCount(const std::string& file, 
                             const std::string& word):
                             m_fileName{file},
                             m_word(word) {}

ProcessWCount::~ProcessWCount() {
	if(m_file.is_open())
		m_file.close();
}

void ProcessWCount::init() {
	m_file.open(m_fileName, std::ios::in );
	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("Cannot open the file: '")
			+ m_fileName
			+"'."
		);
}

void ProcessWCount::run() {
	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("The file: '")
			+ m_fileName
			+"' is not open"
		);
	std::string word;
	char ch;
	while(m_file.read((char*)&ch, sizeof(ch))){
		switch (ch)
		{
		case '\n':
		case '\t':
		case  ' ':
			m_count += (!word.empty() && word == m_word) ? 1:0;
			// std::cout << "[Word]: " <<  word << std::endl;
			word.clear();
			break;
		default:
			word.push_back(ch);
			// std::cout << "[Char]: " << ch <<std::endl;
			break;
		}
	}
	m_count += (!word.empty() && word == m_word) ? 1:0;
}

void ProcessWCount::print(std::ostream& os) const {
	os << m_count << std::endl;
}

std::string ProcessWCount::getResult() const { 
	return std::to_string(m_count);
}
