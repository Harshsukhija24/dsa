#include <bits/stdc++.h>
using namespace std;

int majority(int arr[], int n) {
    unordered_map<int, int> mpp;
    
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for (const auto& pair : mpp) {
        cout << pair.first << ": " << pair.second << endl;
    }

    for (auto it : mpp) {
        if (it.second > n / 2) {
            return it.first;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = majority(arr, n);
    cout << result << endl;
    return 0;
}
