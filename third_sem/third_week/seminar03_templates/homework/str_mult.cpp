#include <iostream>


std::string operator*(std::string& str, int n) {
    std::string result;
    std::string temp = str;
    for (int i = 0; i < n; i++) {
        result += temp;
    }
    return result;
}

int main() {
    std::string s = "Mama";
    std::string sh = s * 5;
    std::cout << sh << std::endl;

    return 0;
}
