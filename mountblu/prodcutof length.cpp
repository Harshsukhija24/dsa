#include <iostream>
#include <vector>
#include <unordered_set>

int productOfLengths(const std::string& str1, const std::string& str2) {
    std::unordered_set<char> charsInStr1;
    int length1 = str1.length();
    int length2 = str2.length();

    // Store characters of str1 in a set
    for (char c : str1) {
        charsInStr1.insert(c);
    }

    // Check for repeating characters in str2
    bool hasRepeatingChar = false;
    for (char c : str2) {
        if (charsInStr1.find(c) != charsInStr1.end()) {
            hasRepeatingChar = true; // Found a repeating character
            break;
        }
    }

    // Return the product of lengths if there are repeating characters
    return hasRepeatingChar ? (length1 * length2) : 0;
}

int main() {
    std::vector<std::string> strings = {"hello", "world", "example", "abcde"};
    
    // Choose two strings for comparison, for example, "hello" and "world"
    std::string str1 = strings[0]; // "hello"
    std::string str2 = strings[1]; // "world"

    int result = productOfLengths(str1, str2);

    std::cout << "Product of lengths: " << result << std::endl;

    return 0;
}
