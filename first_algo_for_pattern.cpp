#include <iostream>
#include <string>

bool isPatternMatch(const std::string& str, const std::string& pattern) {
    if (str.length() != pattern.length()) { // Check if the lengths of the strings are equal
        return false;
    }

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != pattern[i]) { // Compare each character of the strings
            return false;
        }
    }

    return true;
}

int main() {
    std::string str = "abc";
    std::string pattern = "abcf";

    if (isPatternMatch(str, pattern)) {
        std::cout << "Pattern matched!" << std::endl;
    } else {
        std::cout << "Pattern not matched!" << std::endl;
    }

    return 0;
}