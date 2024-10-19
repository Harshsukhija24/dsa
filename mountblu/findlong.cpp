#include <bits/stdc++.h>
using namespace std;

int findlong(int arr[], int n) {
    sort(arr, arr + n); 
    int count = 1; 
    int maxcount = 1; 

    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) {
        
            continue;
        }
        if (arr[i] == arr[i - 1] + 1) {
            count++; 
        } else {
            count = 1; 
        }
        maxcount = max(maxcount, count); 
    }
    return maxcount; 
}

int main() {
    int n;
    cin >> n; 
    int arr[n]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    int result = findlong(arr, n); 
    cout << result << " "; 

    return 0;
}
