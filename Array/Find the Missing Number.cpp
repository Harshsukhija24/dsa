#include <bits/stdc++.h>
using namespace std;

int missing(int arr[], int n) {
    int totalSum = n * (n - 1) / 2;  
    int sumArray = 0;
    for (int i = 0; i < n-1; i++) {  
        sumArray += arr[i];
    }
    return totalSum - sumArray;  
}

int main() {
    int n;
    cin >> n;  
    
    int arr[n-1];  
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];  
    }
    
    int result = missing(arr, n); 
    cout << result << endl; 
    
    return 0;
}
