#include <iostream>
#include <string_view>
#include <string.h>

std::string repeat1(std::string_view s) {
    std::string result = {s.begin(), s.end()};
    

    result += result;
    return result;
}

void repeat2(std::string& s) {
    s = s + s;
}

void repeat3(std::string* ps) {
    *ps = *ps + *ps;
}

std::string* repeat4(std::string_view s) {
    std::string* result = new std::string{s.begin(), s.end()};
    *result += *result;
    return result;
}


int main() {
    std::string s = "Cat";
    std::string ds = repeat1(s);
    repeat3(&s);
    std::string* hs = repeat4(s);
    std::cout << ds << std::endl;
    std::cout << s << std::endl;
    std::cout << *hs << std::endl;
    delete hs;
    return 0;
}
