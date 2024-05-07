#include <iostream>
#include <string>

#include "file.hpp"

class String {
public:
    String();
   
    
    void get_text();
    void find();
    void change_substr(const std::string& str);
private:
    //sstream
    std::string look_for_ = "geeks";
    FileHandler* file_handler_;
    char str_buf_[256];

};