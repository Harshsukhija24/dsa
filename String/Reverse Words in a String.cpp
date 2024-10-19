#include <bits/stdc++.h> 
using namespace std;

string reverseWords(string s) {
    istringstream is(s); 
    string word;
    vector<string> ans; 
    
    while (is >> word) {
        ans.push_back(word);
    }

    reverse(ans.begin(), ans.end());
    
    string result;
    for (int i = 0; i < ans.size(); i++) {
        result += ans[i]; 
        if (i < ans.size() - 1) {
            result += " "; 
        }
    }

    return result;
}

int main() {
    int n; 
    cout << "Enter the number of characters: "; // Prompt user for input
    cin >> n; 
    cin.ignore(); // Ignore the newline character after the integer input

    string str;
    cout << "Enter the string: "; // Prompt user for the string input
    getline(cin, str); // Use getline to allow for spaces in the string

    string result = reverseWords(str); // Call the reverse function
    cout << "Reversed words: " << result << endl; // Print the result

    return 0; 
}
