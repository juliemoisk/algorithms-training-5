#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

bool check(int m, int n, const std::vector<int>& x, const std::vector<int>& y, 
           const std::vector<int>& prefmin, const std::vector<int>& prefmax, 
           const std::vector<int>& sufmin, const std::vector<int>& sufmax) {
    int r = 0;
    int pmx = INT_MIN;
    int pmn = INT_MAX;

    for (int i = 0; i < n; ++i) {
        while (r < n && x[r] < x[i] + m) {
            ++r;
        }
        int mx = pmx;
        int mn = pmn;
        if (r != n) {
            mx = std::max(mx, sufmax[r]);
            mn = std::min(mn, sufmin[r]);
        }
        if (mx - mn < m) {
            return true;
        }
        pmx = prefmax[i];
        pmn = prefmin[i];
    }
    return false;
}

int main() {
    int w, h, n;
    std::cin >> w >> h >> n;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::sort(a.begin(), a.end());

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        x[i] = a[i].first;
        y[i] = a[i].second;
    }

    std::vector<int> prefmin(n), prefmax(n), sufmin(n), sufmax(n);
    prefmin[0] = y[0];
    prefmax[0] = y[0];
    sufmin[n-1] = y[n-1];
    sufmax[n-1] = y[n-1];

    for (int i = 1; i < n; ++i) {
        prefmin[i] = std::min(prefmin[i-1], y[i]);
        prefmax[i] = std::max(prefmax[i-1], y[i]);
    }

    for (int i = n-2; i >= 0; --i) {
        sufmin[i] = std::min(sufmin[i+1], y[i]);
        sufmax[i] = std::max(sufmax[i+1], y[i]);
    }

    int l = 0;
    int r = std::min(w, h);
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m, n, x, y, prefmin, prefmax, sufmin, sufmax)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    std::cout << l << std::endl;

    return 0;
}

