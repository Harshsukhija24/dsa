#include <bits/stdc++.h>
using namespace std;

// Function to calculate digit raised to a power using integer arithmetic
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool isArmstrong(int n) {
    int original = n;
    int digits = 0;
    int sum = 0;

    // Count the number of digits
    while (original != 0) {
        original /= 10;
        digits++;
    }

    original = n;  // Reset original to the initial value of n

    // Calculate the sum of each digit raised to the power of the number of digits
    while (original != 0) {
        int digit = original % 10;
        sum += power(digit, digits);  // Use integer-based power calculation
        original /= 10;
    }

    // Check if the calculated sum equals the original number
    return sum == n;
}

int main() {
    int n;
    cin >> n;

    if (isArmstrong(n)) {
        cout << "True" << endl;  // Output "True" if it's an Armstrong number
    } else {
        cout << "False" << endl;  // Output "False" if it's not an Armstrong number
    }

    return 0;
}
