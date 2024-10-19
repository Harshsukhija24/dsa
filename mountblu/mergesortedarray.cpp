#include <vector>
#include <iostream>

std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged; // Resultant merged array
    int i = 0, j = 0; // Pointers for arr1 and arr2

    // Traverse both arrays and compare elements
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]); // Add smaller element to merged
            i++; // Move pointer in arr1
        } else {
            merged.push_back(arr2[j]); // Add smaller element to merged
            j++; // Move pointer in arr2
        }
    }

    // Add remaining elements of arr1 (if any)
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements of arr2 (if any)
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged; // Return the merged sorted array
}

// Example usage
int main() {
    std::vector<int> arr1 = {1, 3, 5, 7};
    std::vector<int> arr2 = {2, 4, 6, 8};
    
    std::vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    // Print the merged array
    for (int num : mergedArray) {
        std::cout << num << " ";
    }

    return 0;
}
