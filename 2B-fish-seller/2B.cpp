#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int maxinc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i + j < n) {
                maxinc = std::max(maxinc, a[i + j] - a[i]);
            }
        }
    }

    std::cout << maxinc << std::endl;
    return 0;
}

