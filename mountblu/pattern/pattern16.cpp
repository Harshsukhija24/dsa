#include <iostream>
using namespace std;

void print(int n) {
    for (int i = 1; i <= n; i++) { // Loop for each row
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        
        // Print ascending letters from A to the ith letter
        for (char j = 'A'; j < 'A' + i; j++) {
            cout << j;
        }

        // Print descending letters from the (i-1)th letter back to A
        for (char j = 'A' + i - 2; j >= 'A'; j--) {
            cout << j;
        }

        cout << endl; // Move to the next line after each row
    }
}

int main() {
    int n;
    cin >> n; // Input number of rows
    print(n); // Call the function to print the pattern
    return 0;
}
