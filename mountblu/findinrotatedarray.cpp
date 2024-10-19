#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (nums[mid] == target) {
            return mid;
        }

        // Determine which half is sorted
        if (nums[left] <= nums[mid]) { // Left half is sorted
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1; // Target is in the left half
            } else {
                left = mid + 1; // Target is in the right half
            }
        } else { // Right half is sorted
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1; // Target is in the right half
            } else {
                right = mid - 1; // Target is in the left half
            }
        }
    }

    // Target not found
    return -1;
}

int main() {
    int n, target;

    // Input for the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    
    // Input for the elements of the array
    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Input for the target value
    cout << "Enter the target value to search for: ";
    cin >> target;

    // Call the search function
    int result = searchInRotatedArray(nums, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
