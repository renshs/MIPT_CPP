#include <iostream>



void truncateToDot(std::string& s) {
    size_t dot = s.find(".");
    if (dot != s.length()) {
        s.erase(dot, s.length());
     }       
}




int main() {
    std::string s = "ma.ma";
    truncateToDot(s);
    std::cout << s << std::endl;


    return 0;
}
