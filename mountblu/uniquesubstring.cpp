#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<string> findCommonSubstrings(const string& str1, const string& str2) {
    unordered_set<string> substrings; // To store unique substrings
    
    // Generate all possible substrings of str1
    for (size_t i = 0; i < str1.length(); ++i) {
        for (size_t j = i + 1; j <= str1.length(); ++j) {
            string substring = str1.substr(i, j - i); // Extract substring
            // Check if substring exists in str2
            if (str2.find(substring) != string::npos) {
                substrings.insert(substring); // Insert into set if found
            }
        }
    }

    return substrings; // Return the set of common substrings
}

int main() {
    string str1 = "abc";
    string str2 = "abcbc";

    unordered_set<string> commonSubstrings = findCommonSubstrings(str1, str2);

    // Output the result
    cout << "Common substrings:" << endl;
    for (const auto& substring : commonSubstrings) {
        cout << substring << endl;
    }

    return 0;
}
