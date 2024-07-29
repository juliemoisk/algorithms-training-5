#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm> 

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int suma = std::accumulate(a.begin(), a.end(), 0);
    int maxa = *std::max_element(a.begin(), a.end());

    if (maxa * 2 > suma) {
        std::cout << (maxa * 2 - suma) << std::endl;
    }
    else {
        std::cout << suma << std::endl;
    }

    return 0;
}

