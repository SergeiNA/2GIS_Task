#include "include/ProcessCRC.h"

ProcessCRC::ProcessCRC(const std::string& file,
				             std::uintmax_t file_size)
							 : m_fileName {file},
							   m_file_size{file_size}
							  {}

ProcessCRC::~ProcessCRC() {
  if (m_file.is_open()) m_file.close();
}

void ProcessCRC::init() 
{
	if(is_FileEmpty(m_file_size))
		return;
	m_file.open(m_fileName, std::ios::in | std::ios::binary);
	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("Cannot open the file: '")
			+ m_fileName
			+"'."
		);
}

void ProcessCRC::run() {
	if(is_FileEmpty(m_file_size))
		return;
	if (!m_file.is_open())
		throw std::runtime_error(
			std::string("The file: '")
			+ m_fileName
			+"' is not open"
		);
		
	uint32_t temp{0};
	// std::cout << "[init]: " << a << "\n";
	// m_file.seekg (sizeof(uint32_t));
    while(m_file.read((char*)&temp, sizeof(temp))){
		m_CRC^=temp;
		std::cout << "[Read]: " << temp << "\n";
		temp = 0;
	}
	if(temp)
		m_CRC^=temp;
	std::cout << "[Read last]: " << temp << "\n";
}

void ProcessCRC::print(std::ostream& os) const { os << m_CRC << std::endl; }

std::string ProcessCRC::getResult() const { return std::to_string(m_CRC); }
