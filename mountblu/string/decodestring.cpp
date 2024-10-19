#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to decode the given encoded string
string decodeString(const string& s) {
    stack<int> countStack;  // Stack to hold counts of repetitions
    stack<string> stringStack;  // Stack to hold strings
    string currentString;  // Current building string
    int currentCount = 0;  // Current count for repetitions

    for (char c : s) {
        if (isdigit(c)) {
            // Build the current count (can be multiple digits)
            currentCount = currentCount * 10 + (c - '0');
        } else if (c == '[') {
            // Push the current count and string onto their respective stacks
            countStack.push(currentCount);
            stringStack.push(currentString);
            // Reset for the next segment
            currentCount = 0;
            currentString.clear();
        } else if (c == ']') {
            // Pop from the stack
            string lastString = stringStack.top();
            stringStack.pop();
            int count = countStack.top();
            countStack.pop();

            // Build the new string segment
            for (int i = 0; i < count; ++i) {
                lastString += currentString;  // Repeat the current string
            }
            currentString = lastString;  // Update the current string
        } else {
            // Add characters to the current string
            currentString += c;
        }
    }

    return currentString;  // Return the decoded string
}

int main() {
    string input1 = "3[a2[c]]";
    cout << decodeString(input1) << endl;  // Output: "accaccacc"

    string input2 = "3[a]2[bc]";
    cout << decodeString(input2) << endl;  // Output: "aaabcbc"

    return 0;
}
