#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::unordered_set<std::string> dictset;
    std::string line;
    
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        dictset.insert(word);
    }

    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);
    
    std::vector<std::string> ans;
    while (iss >> word) {
        bool found = false;
        for (size_t i = 1; i <= std::min(static_cast<size_t>(100), word.length()); ++i) {
            std::string part = word.substr(0, i);
            if (dictset.find(part) != dictset.end()) {
                ans.push_back(part);
                found = true;
                break;
            }
        }
        if (!found) {
            ans.push_back(word);
        }
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << ans[i];
    }
    std::cout << std::endl;

    return 0;
}

