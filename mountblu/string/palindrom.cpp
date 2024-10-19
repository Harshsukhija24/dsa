#include <bits/stdc++.h>
using namespace std;

int ispalindrom(string str[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1; 
}

int main() {
    int n;
    cin >> n;

    // Use vector for dynamic sizing
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i]; // Read each string into the vector
    }
    
    // Call the correct function
    int result = ispalindrom(str.data(), n); // Use data() to pass the array to the function
    cout << result << endl; 

    return 0; 
}
