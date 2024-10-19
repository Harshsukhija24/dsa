#include <iostream>
#include <string>
using namespace std;

int getSubstringCount(string s) {
    int count = 0; // To keep track of the total valid substrings
    int n = s.length(); // Length of the input string
    int zeroCount = 0; // To count consecutive 0s
    int oneCount = 0; // To count consecutive 1s

    // Loop through the string to identify groups of 0s and 1s
    for (int i = 0; i < n; i++) {
        // Count the number of consecutive 0s
        while (i < n && s[i] == '0') {
            zeroCount++;
            i++;
        }
        // Count the number of consecutive 1s
        while (i < n && s[i] == '1') {
            oneCount++;
            i++;
        }
        // The count of valid substrings formed between the last group of 0s and 1s
        count += min(zeroCount, oneCount); // Add the minimum of the two counts
        // Reset counts for the next group
        zeroCount = 0;
        oneCount = 0;
    }
    return count; // Return the total count of valid substrings
}

int main() {
    string s = "00110101011"; // Example input string
    cout << getSubstringCount(s) << endl; // Output the count of valid substrings
    return 0;
}
