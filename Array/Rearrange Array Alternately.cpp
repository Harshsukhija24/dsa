#include <bits/stdc++.h>
using namespace std;

// Function to rearrange the array alternately
void rearrange(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    vector<int> temp(n);

    int left = 0;
    int right = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            temp[i] = arr[right];
            right--;
        } else {
            temp[i] = arr[left];
            left++;
        }
    }

    // Copy the rearranged elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rearrange(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
