#include <iostream>
#include <vector>
#include <tuple> 

std::tuple<int, int, int> findmax(const std::vector<std::vector<int>>& f, int bannedrow, int bannedcol) {
    int ans = 0, r = 0, c = 0;
    for (int i = 0; i < f.size(); ++i) {
        if (i != bannedrow) {
            for (int j = 0; j < f[0].size(); ++j) {
                if (j != bannedcol && f[i][j] > ans) {
                    ans = f[i][j];
                    r = i;
                    c = j;
                }
            }
        }
    }
    return std::make_tuple(r, c, ans);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> f(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> f[i][j];
        }
    }

    int fr, fc, maxval;
    std::tie(fr, fc, maxval) = findmax(f, -1, -1);

    int banrowr, banrowc, tempval;
    std::tie(banrowr, banrowc, tempval) = findmax(f, fr, -1);

    int tempr, tempc, banrowval;
    std::tie(tempr, tempc, banrowval) = findmax(f, fr, banrowc);

    int bancolr, bancolc;
    std::tie(bancolr, bancolc, tempval) = findmax(f, -1, fc);

    int bancolval;
    std::tie(tempr, tempc, bancolval) = findmax(f, bancolr, fc);

    if (banrowval < bancolval) {
        std::cout << fr + 1 << " " << banrowc + 1 << std::endl;
    } else {
        std::cout << bancolr + 1 << " " << fc + 1 << std::endl;
    }

    return 0;
}

