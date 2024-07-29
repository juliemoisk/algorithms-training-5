#include <iostream>
#include <vector>
#include <unordered_set>

bool sol(const std::vector<int>& nums, int k) {
    std::unordered_set<int> lastk;
    for (int i = 0; i < nums.size(); ++i) {
        if (lastk.find(nums[i]) != lastk.end()) {
            return true;
        }
        lastk.insert(nums[i]);
        if (i >= k) {
            lastk.erase(nums[i - k]);
        }
    }
    return false;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    if (sol(nums, k)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

