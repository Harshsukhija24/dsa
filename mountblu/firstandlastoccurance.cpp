#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of x
int findFirstOccurrence(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int firstIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            firstIndex = mid; // Found x, but continue searching left
            right = mid - 1;  // Move to the left half
        } else if (arr[mid] < x) {
            left = mid + 1;   // Move to the right half
        } else {
            right = mid - 1;  // Move to the left half
        }
    }

    return firstIndex;
}

// Function to find the last occurrence of x
int findLastOccurrence(vector<int> arr, int x) {
    int left = 0, right = arr.size() - 1;
    int lastIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            lastIndex = mid; // Found x, but continue searching right
            left = mid + 1;  // Move to the right half
        } else if (arr[mid] < x) {
            left = mid + 1;   // Move to the right half
        } else {
            right = mid - 1;  // Move to the left half
        }
    }

    return lastIndex;
}

// Function to find both first and last occurrences of x
pair<int, int> findFirstAndLast(const vector<int>& arr, int x) {
    int first = findFirstOccurrence(arr, x);
    int last = findLastOccurrence(arr, x);

    return {first, last};
}

// Main function to take input and execute the search
int main() {
    int n;

    // Take input for the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    
    // Take input for the elements of the array
    cout << "Enter the sorted elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int x;
    // Take input for the element to be searched
    cout << "Enter the element to find: ";
    cin >> x;

    // Find first and last occurrences
    pair<int, int> result = findFirstAndLast(arr, x);
    
    // Output the results
    if (result.first == -1) {
        cout << "Element " << x << " not found in the array." << endl;
    } else {
        cout << "First occurrence of " << x << " is at index: " << result.first << endl;
        cout << "Last occurrence of " << x << " is at index: " << result.second << endl;
    }

    return 0;
}
