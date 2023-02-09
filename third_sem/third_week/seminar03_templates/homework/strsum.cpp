#include <iostream>
#include <string>

int strSum(std::string_view s)
{
    int result = 0;
    std::string curr_num;
    for (auto it = s.begin() + 1; it != s.end(); it++)
    {

        if (isdigit(*it))
        {
            curr_num += *it;
        }
        else if (curr_num != "")
        {
            result += stoi(curr_num);
            curr_num = "";
        }
    }
    return result;
}

int main()
{
    std::string arr = "[]";
    std::cout << strSum(arr) << std::endl;

    return 0;
}
