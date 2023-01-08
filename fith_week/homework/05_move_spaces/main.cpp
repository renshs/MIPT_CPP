#include <iostream>
#include <string>
#include <algorithm>

using std::cout, std::string, std::endl;

void move_spaces(string& s) {
        std::stable_sort(s.begin(), s.end(), [](const char& a, const char& b){ return (b == ' '); });
}

int main() {
        string s;
        std::getline(std::cin, s);
        move_spaces(s);
        // So we can see spaces
        cout << s << "###" << endl;

}
