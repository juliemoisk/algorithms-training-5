#include <iostream>
#include <vector>
#include <algorithm>

int binsearch(const std::vector<int>& a, int val) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] >= val) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    a.push_back(1000000001);

    int k;
    std::cin >> k;
    
    std::vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        int mn, mx;
        std::cin >> mn >> mx;
        int posmn = binsearch(a, mn);
        int posmx = binsearch(a, mx + 1);
        ans[i] = posmx - posmn;
    }

    for (int i = 0; i < k; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

