#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <cctype>

using std::cout, std::endl, std::string, std::string_view;

bool isIdentifier(string_view sv) {
    bool is = true;
    if (!(std::isalpha(sv[0]) || sv[0] == '_'))
            return false;
    if (std::all_of(sv.begin(), sv.end(), [](const char c){ return isalpha(c) || isdigit(c) || c == '_' ;}))
            return true;
    return false;
}

int main() {
    string s;
    getline(std::cin, s);
    cout << isIdentifier(s) << endl;
}
