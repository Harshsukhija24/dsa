#include <bits/stdc++.h>
using namespace std;

bool rotation(const string& str1, const string& str2) {
    // Check if lengths are the same
    if (str1.length() != str2.length()) return false;

    // Concatenate str1 with itself
    string concatenated = str1 + str1;

    // Check if str2 is a substring of the concatenated string
    return concatenated.find(str2) != string::npos;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    // Reading strings into str1 vector
    vector<string> str1(n);
    for (int i = 0; i < n; i++) {
        cin >> str1[i];
    }

    // Corrected loop condition for str2 to use n instead of m
    vector<string> str2(m);
    for (int i = 0; i < m; i++) {
        cin >> str2[i];
    }

    // Checking rotations and printing results
    for (int i = 0; i < min(n, m); i++) { // Ensure we check only up to the smaller size
        int result = rotation(str1[i], str2[i]); // Pass individual strings
        cout << result << " "; // Output result as 0 (not rotation) or 1 (is rotation)
    }

    return 0;
}
