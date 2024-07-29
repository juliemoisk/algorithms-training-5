#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> make_counter(const std::string& s) {
    std::unordered_map<char, int> ans;
    for (char c : s) {
        ++ans[c];
    }
    return ans;
}

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;

    std::unordered_map<char, int> dct1 = make_counter(str1);
    std::unordered_map<char, int> dct2 = make_counter(str2);

    bool flag = true;
    for (const auto& pair : dct1) {
        char char1 = pair.first;
        int count1 = pair.second;
        if (dct2.find(char1) == dct2.end() || dct2[char1] != count1) {
            flag = false;
            break;
        }
    }

    if (dct1.size() == dct2.size() && flag) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

