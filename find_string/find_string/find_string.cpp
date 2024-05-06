#include <string>
#include <iostream>
#include <vector>

std::pair<int,std::string> find_first_occurrence(const std::string& str, const std::string& expected)
{
    int count = 0;
    int idx = 0;
    for (int i=0;i<str.size();i++)
    {
        if (str[i] == expected[count])
        {
            if (count == 0)
                idx = i;
            count++;
        }
        else
            count = 0;
        if (count == expected.size())
            break;
    }
    
    std::string twenty_next_char = str.substr(idx, 20); 
    std::pair<int, std::string> ans=std::make_pair(idx, twenty_next_char);
    return ans;
}

std::pair<int, std::string> find_second_occurrence(const std::string& str, const std::string& expected)
{
     std::pair<int, std::string> ans = find_first_occurrence(str, expected);
    int count = 0;
    int idx = 0;
    for (int i = ans.first+1; i < str.size(); i++)
    {
        if (str[i] == expected[count])
        {
            if (count == 0)
                idx = i;
            count++;
        }
        else
            count = 0;
        if (count == expected.size())
            break;
    }
  
    std::string twenty_next_char= str.substr(idx, 20); //= str + idx;
    
    ans=std::make_pair(idx, twenty_next_char);
    return ans;
}
int main()
{

    std::string str;
    std::getline(std::cin,str);
    std::string expected;
    std::cin >>  expected;
    std::pair<int, std::string> ans = find_first_occurrence(str, expected);
    std::cout << ans.first << " "<<ans.second;
    std::cout << std::endl;
    ans = find_second_occurrence(str, expected);
    std::cout << ans.first << "  " << ans.second;
   
}

//changes:
/*
* 1-std::pair<int , std::string>
* 2-substr:offset, length
*/
