#include <bits/stdc++.h>
using namespace std;

string shuffle(string s, vector<int> indices) {
    int n = s.size();
    string suff(n, ' '); // Create a new string filled with spaces

    for (int i = 0; i < n; i++) {
        suff[indices[i]] = s[i]; // Place each character at the new index
    }
    
    return suff; // Return the shuffled string
}

int main() {
    int n;
    cout << "Enter the length of the string: ";
    cin >> n; // Read the length of the string

    // Read the input string
    string s;
    cout << "Enter the string: ";
    cin >> s; 

    // Create a vector for indices
    vector<int> indices(n);
    cout << "Enter the indices (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> indices[i]; // Read the indices
    }

    // Call the shuffle function
    string result = shuffle(s, indices);
    
    // Output the result
    cout << "Shuffled string: " << result << endl;

    return 0;
}
