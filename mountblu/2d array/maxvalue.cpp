#include <bits/stdc++.h>
using namespace std;

int maxDifference(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return 0; // Edge case for an empty matrix
    
    int maxDiff = INT_MIN; // To store the maximum difference
    int minValue = mat[0][0]; // Initialize minValue with the first element

    // Iterate through the matrix starting from the second row and column
    for (int c = 1; c < n; c++) {
        for (int d = 1; d < n; d++) {
            // Update the maxDiff using the current element
            maxDiff = max(maxDiff, mat[c][d] - minValue);
        }
        // Update the minimum value encountered so far for the next rows
        for (int b = 0; b < c; b++) {
            for (int a = 0; a < d; a++) {
                minValue = min(minValue, mat[b][a]);
            }
        }
    }

    return maxDiff; // Return the maximum difference found
}

int main() {
    // Example input matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = maxDifference(mat);
    cout << "Maximum value of mat(c, d) - mat(a, b): " << result << endl;

    return 0;
}
