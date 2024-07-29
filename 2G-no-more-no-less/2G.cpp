#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int prevbreak = 0;
        int curmin = a[0];
        std::vector<int> ans;

        for (int i = 0; i < n; ++i) {
            curmin = std::min(curmin, a[i]);
            if (prevbreak + curmin <= i) {
                ans.push_back(i - prevbreak);
                prevbreak = i;
                curmin = a[i];
            }
        }

        ans.push_back(n - prevbreak);

        std::cout << ans.size() << std::endl;
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

