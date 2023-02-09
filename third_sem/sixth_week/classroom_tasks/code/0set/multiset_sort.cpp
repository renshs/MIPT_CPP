#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::multiset<int> nums;
    for (auto i = 0; i < n; i++) {
        int curr_n;
        std::cin >> curr_n;
        nums.insert(curr_n);
    }
    for (auto it = nums.begin(); it != nums.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
