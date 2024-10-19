#include <bits/stdc++.h>
using namespace std;

// Function to print duplicates in a given string
void printDups(const string &str) {
    unordered_map<char, int> count;
    for (char ch : str) {
        count[ch]++;
    }

    // Iterating through the unordered map to find duplicates
    for (auto it : count) {
        if (it.second > 1) // Duplicate found
            cout << it.first << ", count = " << it.second << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    vector<string> str(n);

    // Input strings
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (const string &s : str) {
        cout << "Duplicates in string \"" << s << "\":\n";
        printDups(s);
        cout << "\n"; // Print a new line for better readability
    }

    return 0;
}
