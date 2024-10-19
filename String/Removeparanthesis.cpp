#include <bits/stdc++.h>
using namespace std;

string removeParantheses(string s) {
    int count = 0; // Initialize the depth counter
    string str; 

    for (char c : s) {
        if (c == '(') {
            if (count++ > 0) {
                str += "(";
            }
        } else {
            if (--count > 0) {
                str += ")";
            }
        }
    }

    return str; // Return the modified string
}

int main() {
    int n;
    cout << "Enter the number of test cases: ";
    cin >> n; // Read number of test cases

        string str;
        cout << "Enter a valid parentheses string: ";
        cin >> str; // Read the parentheses string
        string result = removeParantheses(str); // Call the function
        cout << "Result: " << result << endl; // Print the result

    return 0; // Return success
}
