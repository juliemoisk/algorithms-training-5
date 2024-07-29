#include <iostream>
#include <vector>
#include <set>
#include <tuple>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> points_lst(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points_lst[i].first >> points_lst[i].second;
    }

    std::set<std::pair<int, int>> points_set(points_lst.begin(), points_lst.end());

    int x0 = points_lst[0].first;
    int y0 = points_lst[0].second;

    std::vector<std::pair<int, int>> ans = {{x0 + 1, y0 + 1}, {x0 + 1, y0}, {x0, y0 + 1}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                int x1 = points_lst[i].first;
                int y1 = points_lst[i].second;
                int x2 = points_lst[j].first;
                int y2 = points_lst[j].second;
                
                int dx = x2 - x1;
                int dy = y2 - y1;
                int x3 = x1 + dy;
                int y3 = y1 - dx;
                int x4 = x3 + dx;
                int y4 = y3 + dy;

                if (points_set.find({x3, y3}) != points_set.end() && points_set.find({x4, y4}) != points_set.end()) {
                    ans.clear();
                }
                if (ans.size() > 1 && points_set.find({x3, y3}) != points_set.end()) {
                    ans = {{x4, y4}};
                }
                if (ans.size() > 1 && points_set.find({x4, y4}) != points_set.end()) {
                    ans = {{x3, y3}};
                }
                if (ans.size() > 2) {
                    ans = {{x3, y3}, {x4, y4}};
                }
            }
        }
    }

    std::cout << ans.size() << std::endl;
    for (const auto& p : ans) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}

