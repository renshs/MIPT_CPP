#include <iostream>
#include <set>


int main() {
    int n = 0;
    std::cin >> n;
    std::set<int> nums;
    for (auto i = 0; i < n; i++) {
        int current_n;
        std::cin >> current_n;
        nums.insert(current_n);
    }
    for (auto it = nums.begin(); it != nums.end(); it++) {
        std::cout << *it << ' ';
    }
}
