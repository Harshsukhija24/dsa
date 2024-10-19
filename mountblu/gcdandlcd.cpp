#include <iostream>
#include <vector>
#include <numeric> // For std::gcd

using namespace std;

// Function to compute LCM and GCD
vector<int> lcmAndGcd(int a, int b) {
    // Compute GCD using std::gcd (C++17 and above)
    int gcd = std::gcd(a, b);
    
    // Compute LCM using the relationship between LCM and GCD
    int lcm = abs(a * b) / gcd; // Using abs to ensure LCM is non-negative
    
    return {lcm, gcd}; // Return as a vector
}

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b; // Input integers

    vector<int> result = lcmAndGcd(a, b); // Call the function

    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl; // Output the result

    return 0;
}
