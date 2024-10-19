#include <iostream>
#include <limits> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reversedInt = 0; // Use long long to prevent overflow
        while (x != 0) {           // Continue until x becomes 0
            int digit = x % 10;    // Get the last digit of x
            reversedInt = reversedInt * 10 + digit; // Build the reversed integer
            x /= 10;                // Remove the last digit from x
        }

        // Check for overflow
        if (reversedInt < INT_MIN || reversedInt > INT_MAX) {
            return 0; // Return 0 if reversed integer is out of bounds
        }

        return static_cast<int>(reversedInt); // Cast and return the result
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    int n;

    cout << "Enter an integer: ";
    cin >> n; // Input number

    int result = solution.reverse(n); // Call the reverse function
    cout << "Reversed integer: " << result << endl; // Output the result

    return 0;
}
