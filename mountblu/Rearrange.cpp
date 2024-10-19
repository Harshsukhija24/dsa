#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n) {
    vector<int> pos;
    vector<int> neg;
    int intr1 = 0, intr2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  
            if (intr1 < pos.size()) {
                arr[i] = pos[intr1];
                intr1++;
            } else if (intr2 < neg.size()) {  
                arr[i] = neg[intr2++];
            }
        } else {  
            if (intr2 < neg.size()) {
                arr[i] = neg[intr2++];
            } else if (intr1 < pos.size()) {  
                arr[i] = pos[intr1++];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Rearrange the array
    rearrange(arr, n);
    
    // Output the rearranged array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
