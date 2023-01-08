#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::string, std::vector;

void string_vector_reverse(vector<string>& sv) {
    std::for_each(sv.begin(), sv.end(), [](string& s){ std::reverse(s.begin(), s.end()); });
    std::reverse(sv.begin(), sv.end());
}

int main() {

    vector<string> sv1 {"cat", "dog", "mouse", "elephant"};
    vector<string> sv2 {"a", "bc"};

    string_vector_reverse(sv1);
    string_vector_reverse(sv2);

    for (int i = 0; i < sv1.size(); ++i)
            cout << sv1[i] << (i == sv1.size() - 1 ? "" : " ");
    cout << endl;
    for (int i = 0; i < sv2.size(); ++i)
            cout << sv2[i] << (i == sv2.size() - 1 ? "" : " ");
    cout << endl;
}
