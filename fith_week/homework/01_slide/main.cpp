#include <vector>
#include <iostream>
#include <algorithm>

using std::cout, std::endl, std::vector, std::cin;

int main() {
    size_t n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
            cin >> v[i];

   vector<int>::iterator max = std::max_element(v.begin(), v.end());
   std::sort(v.begin(), max);
   std::sort(max, v.end()); 
   std::reverse(max, v.end());

   for (int i = 0; i < v.size(); ++i)
           cout << v[i] << (i == v.size() - 1 ? "": " ");
   cout << endl;
}
