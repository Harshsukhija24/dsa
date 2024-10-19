#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findpairwithsum(int arr[], int n, int targetsum) {
    vector<pair<int, int>> result;

    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == targetsum) {
            result.push_back({arr[left], arr[right]}); // Add the pair to the result

            int leftval = arr[left];
            int rightval = arr[right];

            while (left < right && arr[left] == leftval) ++left;
            while (left < right && arr[right] == rightval) --right;
        } else if (sum < targetsum) {
            ++left; // Increase the sum by moving the left pointer
        } else {
            --right; // Decrease the sum by moving the right pointer
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int targetsum;
    cin >> targetsum;

    vector<pair<int, int>> pairs = findpairwithsum(arr, n, targetsum);

    // Output the pairs
    for (const auto& pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}
