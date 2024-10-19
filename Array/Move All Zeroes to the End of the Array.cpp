#include <bits/stdc++.h>
using namespace std;

void moveallzero(int arr[], int n) {
    int nonzeroindex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonzeroindex]);
            nonzeroindex++;
        }
    }
    return;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    moveallzero(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 

    return 0;
};