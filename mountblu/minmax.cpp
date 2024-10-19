#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinMax(const vector<int>& arr) {
    if (arr.empty()) {
        return {0, 0}; // Handle empty array case
    }

    // Initialize max and min to the first element
    int maxVal = arr[0];
    int minVal = arr[0];

    // Iterate through the array starting from the second element
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i]; // Update max
        } else if (arr[i] < minVal) {
            minVal = arr[i]; // Update min
        }
    }

    return {minVal, maxVal}; // Return the result as a pair
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i]; // Input elements
    }

    pair<int, int> result = findMinMax(arr); // Call the function
    cout << "Minimum Element: " << result.first << endl;
    cout << "Maximum Element: " << result.second << endl;

    return 0;
}
