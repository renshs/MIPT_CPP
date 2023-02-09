/*
    Задача:

        На вход приходит число, ваша задача заключается в том, чтобы написать половину "ёлочки" из этого слова.

            Вход            Выход

            Hello           H
                            He
                            Hel
                            Hell
                            Hello 
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;

void spruce(std::string s)
{
    for (auto i = 0; i < s.size(); i++)
    {
        cout << s.substr(0, i + 1) << endl;
    }
}

int main()
{
    spruce("Hello");
    return 0;
}
