#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to find pair of elements in array that sum up to target
vector<int> findPairWithSum(vector<int>& nums, int target) {
    unordered_set<int> numSet;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numSet.find(complement) != numSet.end()) {
            // Found the pair
            result.push_back(complement);
            result.push_back(nums[i]);
            return result;
        }
        numSet.insert(nums[i]);
    }

    // If no pair found, return an empty vector or handle appropriately
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> pair = findPairWithSum(nums, target);

    if (!pair.empty()) {
        cout << "Pair found: " << pair[0] << " and " << pair[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}
