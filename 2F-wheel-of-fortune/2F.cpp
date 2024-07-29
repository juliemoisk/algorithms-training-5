#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits> 

int main() {
    int n;
    std::cin >> n;

    std::vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vals[i];
    }

    int a, b, k;
    std::cin >> a >> b >> k;

    int minsect = (a - 1) / k;
    int maxsect = (b - 1) / k;

    int ans = INT_MIN;
    for (int j = 0; j < 2; ++j) {
        std::vector<bool> usedsect(n, false);
        for (int i = minsect; i <= maxsect; ++i) {
            ans = std::max(ans, vals[i % n]);
            if (usedsect[i % n]) {
                break;
            }
            usedsect[i % n] = true;
        }
        
        std::reverse(vals.begin() + 1, vals.end());
    }

    std::cout << ans << std::endl;
    return 0;
}

