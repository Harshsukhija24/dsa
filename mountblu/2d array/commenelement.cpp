#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findCommonElements(const vector<vector<int>>& matrix) {
    unordered_map<int, int> elementCount; // To count occurrences of each element
    vector<int> commonElements; // To store common elements

    // Iterate through each row of the matrix
    for (const auto& row : matrix) {
        // Create a set to avoid counting duplicates within the same row
        unordered_map<int, bool> rowElements;
        for (int num : row) {
            // Mark this number as present in the current row
            if (rowElements.find(num) == rowElements.end()) {
                rowElements[num] = true;
                elementCount[num]++; // Increment the count in the hash map
            }
        }
    }

    // Collect the elements that are present in all rows
    for (const auto& pair : elementCount) {
        if (pair.second == matrix.size()) {
            commonElements.push_back(pair.first);
        }
    }

    return commonElements;
}

// Example Usage
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };

    vector<int> common = findCommonElements(matrix);

    cout << "Common elements in all rows: ";
    for (int num : common) {
        cout << num << " ";
    }
    cout << endl; // Output: Common elements in all rows: 4

    return 0;
}
