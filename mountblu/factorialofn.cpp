#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n) {
    long long fact = 1;  // Initialize factorial as 1
    for (int i = 2; i <= n; i++) {
        fact *= i;  // Multiply each number from 2 to n
    }

    string factstr = to_string(fact);
    vector<int> result;
    
    for (char ch : factstr) {
        result.push_back(ch - '0');  // Convert each character to an integer
    }
    
    return result;  // Return the vector of digits
}

int main() {
    int n;
    cin >> n;  // Input value for which factorial is to be calculated
     
    vector<int> ans = factorial(n);
    
    for (auto it : ans) {
        cout << it << " ";  // Output each digit separated by a space
    }
    
    cout << endl;  
    return 0;
}
