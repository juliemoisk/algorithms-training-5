#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::set<std::string> ans;
    for (int i = 0; i < k; ++i) {
        std::string word;
        std::cin >> word;
        ans.insert(word);
    }

    for (int i = 1; i < n; ++i) {
        std::cin >> k;
        std::set<std::string> now;
        for (int j = 0; j < k; ++j) {
            std::string word;
            std::cin >> word;
            now.insert(word);
        }

        std::set<std::string> intersection;
        for (const auto& word : ans) {
            if (now.find(word) != now.end()) {
                intersection.insert(word);
            }
        }
        ans = intersection;
    }

    std::vector<std::string> sorted_ans(ans.begin(), ans.end());
    std::sort(sorted_ans.begin(), sorted_ans.end());

    std::cout << sorted_ans.size() << std::endl;
    for (const auto& word : sorted_ans) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}

