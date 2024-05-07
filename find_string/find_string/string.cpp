#include "string.hpp"

String::String()
{
	get_text();
}

void String::get_text()
{
	file_handler_->read_from_file();
	file_handler_->get_str_buf(str_buf_);
}

void String::find()
{
    int count = 0;
    int idx = 0;
    for (int i = 0; i <sizeof(str_buf_); i++)
    {
        if (str_buf_[i] == look_for_[count])
        {
            if (count == 0)
                idx = i;
            count++;
        }
        else
            count = 0;
        if (count == look_for_.size())
        {
            file_handler_->write_to_file(idx, str_buf_);
            count=0;
        }
    }
}

void String::change_substr(const std::string& str)
{
	look_for_ = str;
}
