#include<iostream>
#include<vector>
#include <string>
#include <sstream>
#include <fstream>


class FileHandler
{
public:
    FileHandler();
    ~FileHandler();
    void change_file_address(const std::string& file_type,const std::string& path );
    void read_from_file();
    void write_to_file(int idx,char* str);
    void get_str_buf(char* buf);

private:
    std::string input_path_ = "D:\Tasks\find_string\find_string\file.txt";
    std::string output_path_ = "./ans.txt";
    std::fstream file_;
    char str_buf[128]{0x00};

  
};