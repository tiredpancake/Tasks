#include "file.hpp"

//File_handler::obj_ = new File_handler();

FileHandler::FileHandler()
{
	
}
FileHandler::~FileHandler()
{
	if (file_.is_open())
		file_.close();
}

void FileHandler::change_file_address(const std::string& file_type, const std::string& path)
{
	(file_type == "input") ? input_path_ = path : output_path_ = path;
}

void FileHandler::read_from_file()
{
	int temp_size{ 0 };
	std::string str;
	std::ifstream file(input_path_);
	if (file.is_open())
	{
		while (file.good())
		{
			file >> str;
			memcpy(str_buf + temp_size, str.c_str(),sizeof(str.c_str()));
			temp_size += sizeof(str.c_str());

		}
	}
	file.close();
}

void FileHandler::write_to_file(int idx,char* str)
{
	file_.open(output_path_, std::ios::out | std::ios::app);
	file_.seekg(0, std::ios::end);
	
	file_ << std::to_string(idx);;// << str << std::endl;
	for (int i = idx; i < idx + 20; i++)
	{
		file_ << str[i];
	}
	file_ << std::endl;
}

void FileHandler::get_str_buf(char* buf)
{
	memcpy(buf,str_buf,sizeof(str_buf));
}
