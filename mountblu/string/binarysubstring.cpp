#include <iostream>
#include <string>
using namespace std;

int countBinarySubstrings(const string& s) {
    int n = s.size();
    int count = 0;
    int previousLength = 0; // Length of the previous segment of the opposite character
    int currentLength = 1;   // Length of the current segment of the same character

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            currentLength++; // Increment length of the current segment
        } else {
            // Found a different character
            count += min(previousLength, currentLength); // Count valid substrings
            previousLength = currentLength; // Update previousLength to current segment length
            currentLength = 1; // Reset currentLength for the new segment
        }
    }

    // Count valid substrings for the last segment
    count += min(previousLength, currentLength);

    return count; // Return the total count of valid substrings
}

int main() {
    string input1 = "00110011";
    cout << countBinarySubstrings(input1) << endl; // Output: 6

    string input2 = "10101";
    cout << countBinarySubstrings(input2) << endl; // Output: 4

    return 0;
}
