#include <iostream>
#include <set>

int main() {
    int len;
    int n_cuts;
    std::cin >> len >> n_cuts;
    std::set<int> cuts;
    std::multiset<int> lens;
    cuts.insert(0);
    cuts.insert(len);
    lens.insert(len);


    for (auto i = 0; i < n_cuts; i++) {
        int current_cut;
        std::cin >> current_cut;
        cuts.insert(current_cut);
        int elem = *(--cuts.find(current_cut));
        int left = *cuts.find(current_cut) - *(--cuts.find(current_cut));
        int right = *(++cuts.find(current_cut)) - *cuts.find(current_cut);
#ifdef _DEBUG
        std::cout << "left is " << left << "right is " << right << std::endl;
#endif

        lens.erase(*(++cuts.find(current_cut)) - *(--cuts.find(current_cut)));
        lens.insert(left);
        lens.insert(right);
        std::cout << *--lens.end() << ' ';
    }
    
    
}
