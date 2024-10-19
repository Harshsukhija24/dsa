#include <bits/stdc++.h>
using namespace std;

vector<int> interraction(int arr1[], int n1, int arr2[], int n2) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return result;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    vector<int> result = interraction(arr1, n1, arr2, n2);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
