#include <bits/stdc++.h>
using namespace std;

int findKthLargest(int arr[], int n, int k) {
    // Sort the array in descending order
    sort(arr, arr + n, greater<int>());
    
    // Return the k-th largest element
    return arr[k - 1];
}

int main() {
    int n;
    cin >> n;  // Input the size of the array
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input array elements
    }
    
    int k;
    cin >> k;  // Input the value of k
    
    // Output the k-th largest element
    cout << findKthLargest(arr, n, k) << endl;

    return 0;
}
