#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSum(int arr[], int n, int sum) {
    unordered_map<int, int> prefixSumMap;
    int currentSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == sum) {
            maxLength = i + 1;
        }

        if (prefixSumMap.find(currentSum - sum) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[currentSum - sum]);
        }

        if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
            prefixSumMap[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n; 
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    int sum;
    cin >> sum; 

    cout << longestSubarrayWithSum(arr, n, sum) << endl;

    return 0;
}
