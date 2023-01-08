#include <algorithm>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <cctype>

using std::string, std::cin, std::cout, std::endl;

bool strIsUpper(const string& s) {
    return std::accumulate(s.begin(), s.end(), true, [](bool res, char c) {return res && (!isalpha(c) || isupper(c)); });
}

int main() {
    string s;
    getline(cin, s);
    cout << strIsUpper(s) << endl;
}
