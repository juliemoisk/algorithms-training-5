#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> bytype;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (std::tie(x1, y1) > std::tie(x2, y2)) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        int dx = x2 - x1;
        int dy = y2 - y1;
        bytype[{dx, dy}].emplace_back(x1, y1);
    }

    std::map<std::pair<int, int>, int> mxmy;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (std::tie(x1, y1) > std::tie(x2, y2)) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        int dx = x2 - x1;
        int dy = y2 - y1;

        auto it = bytype.find({dx, dy});
        if (it != bytype.end()) {
            for (const auto& [xp, yp] : it->second) {
                int mx = x1 - xp;
                int my = y1 - yp;
                mxmy[{mx, my}]++;
            }
        }
    }

    int maxinplace = 0;
    for (const auto& [coords, count] : mxmy) {
        maxinplace = std::max(maxinplace, count);
    }

    std::cout << n - maxinplace << std::endl;

    return 0;
}

