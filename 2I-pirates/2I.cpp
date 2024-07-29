#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath> 

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ships(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ships[i].first >> ships[i].second;
    }

    std::sort(ships.begin(), ships.end());

    int ans = n * n;
    for (int col = 1; col <= n; ++col) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            now += std::abs(ships[i].first - (i + 1)) + std::abs(ships[i].second - col);
        }
        ans = std::min(ans, now);
    }

    std::cout << ans << std::endl;
    return 0;
}

