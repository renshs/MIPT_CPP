#include <iostream>
#include <cctype>



void reg_changer(std::string& str) {
    if (str[0] == toupper(str[0])) {
        str[0] = tolower(str[0]);
    
    } else {
        str[0] = toupper(str[0]);
    }
    
}
int main() {
    std::string a = "Mama";
    reg_changer(a);
    std::cout << a << std::endl;
    return 0;
}
