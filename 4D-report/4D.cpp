#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 1e9;

long long getlen(const std::vector<int>& a, int size) {
    long long lines = 0;
    long long nowsize = 0;
    for (int now : a) {
        if (now > size) {
            return INF;
        }
        if (now <= nowsize) {
            nowsize -= now + 1;
        } else {
            nowsize = size - now - 1;
            ++lines;
        }
    }
    return lines;
}

bool check(const std::vector<int>& a, const std::vector<int>& b, int w, int left) {
    int right = w - left;
    return getlen(a, left) < getlen(b, right);
}

int main() {
    int w, n, m;
    std::cin >> w >> n >> m;

    std::vector<int> a(n);
    std::vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    int l = 0;
    int r = w;

    while (l < r) {
        int m = (l + r) / 2;
        if (check(a, b, w, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    long long result1 = std::max(getlen(a, l), getlen(b, w - l));
    long long result2 = std::max(getlen(a, l - 1), getlen(b, w - l + 1));

    std::cout << std::min(result1, result2) << std::endl;

    return 0;
}

