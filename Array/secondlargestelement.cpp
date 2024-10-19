#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n) {
    if (n < 2) return -1;  

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];  
        }
    }

    return (second_largest == INT_MIN) ? -1 : second_largest;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = largest(arr, n);
    cout << result << endl;  
}
