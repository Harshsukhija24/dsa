#include <bits/stdc++.h>
using namespace std;

int minimizeheight(int arr[], int n, int k) {
    if (n == 1) return 0;

    // Sort the array
    sort(arr, arr + n);

    // Initial difference
    int diff = arr[n - 1] - arr[0];

    // Initialize smallest and largest after modification
    int small = arr[0] + k;
    int large = arr[n - 1] - k;

    // Ensure small is smaller than large
    if (small > large) swap(small, large);

    // Traverse through the rest of the elements
    for (int i = 1; i < n - 1; i++) {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        // Check if the new height goes out of bounds
        if (subtract >= small || add <= large) continue;

        // Update small or large based on which adjustment makes more sense
        if (large - subtract <= add - small) 
            small = subtract;
        else 
            large = add;
    }

    // Return the minimized difference
    return min(diff, large - small);
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minimizeheight(arr, n, k);
    cout << result << " ";

    return 0;
}
