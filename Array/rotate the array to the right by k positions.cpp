#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);  
        start++;
        end--;
    }
}

void rotate(int arr[], int n, int k) {
    k = k % n; 
    if (k == 0) return;  
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    rotate(arr, n, k);  
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
