#include <bits/stdc++.h>
using namespace std;

// Function to find duplicate elements in the array
vector<int> duplicate(int arr[], int n) {
    unordered_map<int, int> mpp;
    vector<int> result;
    
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    
    // Find elements that appear more than once
    for (auto it : mpp) {
        if (it.second > 1) {
            result.push_back(it.first);
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = duplicate(arr, n);

    // Print the result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
