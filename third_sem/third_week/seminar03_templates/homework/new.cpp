#include <iostream>




int main() {
    
    int n = new int(5);
    std::string s = new string("Cats and Dogs");
    std::array<int> arr  = new array{1, 2, 3, 4, 5};
    std::array<string> s_arr = new array{"Cat", "Dog"};

    delete n;
    delete arr;
    delete s_arr;

    return 0;
}
