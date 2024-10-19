#include <bits/stdc++.h>
using namespace std;

// Function to find the row with the maximum number of 1s
int rowWithMax1s(vector<vector<int>>& matrix) {
    int maxRow = -1; // To keep track of the row index with the max 1s
    int maxCount = 0; // To keep track of the max count of 1s
    int rows = matrix.size(); // Number of rows
    int cols = matrix[0].size(); // Number of columns

    for (int i = 0; i < rows; i++) {
        int left = 0; // Left pointer for binary search
        int right = cols - 1; // Right pointer for binary search

        // Perform binary search in the current row
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate mid index
            
            if (matrix[i][mid] == 1) {
                right = mid - 1; // Move left if we find a 1
            } else {
                left = mid + 1; // Move right if we find a 0
            }
        }
        
        // Count the number of 1s in the current row
        int count = cols - left; // Since `left` is the index of the first 1
        
        // Update maxCount and maxRow if we found a new maximum
        if (count > maxCount) {
            maxCount = count;
            maxRow = i; // Store the row index
        }
    }

    return maxRow; // Return the row index with the maximum number of 1s
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols; // Input for number of rows and columns

    vector<vector<int>> matrix(rows, vector<int>(cols)); // Initialize the matrix

    cout << "Enter the elements of the matrix (0s and 1s only): " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j]; // Input for each element
        }
    }

    // Find the row with the maximum number of 1s
    int resultRow = rowWithMax1s(matrix);

    if (resultRow != -1) {
        cout << "The index of the row with the maximum number of 1s is: " << resultRow << endl;
    } else {
        cout << "No row has 1s." << endl; // If no row contains 1s
    }

    return 0;
}
