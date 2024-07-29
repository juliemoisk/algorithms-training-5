#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> field(10, std::vector<int>(10, 0));

    for (int k = 0; k < n; ++k) {
        int i, j;
        std::cin >> i >> j;
        field[i][j] = 1;
    }

    int ans = 0;
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            ans += (field[i][j - 1] != field[i][j]);
            ans += (field[i - 1][j] != field[i][j]);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

