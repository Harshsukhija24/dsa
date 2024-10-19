#include <bits/stdc++.h>
using namespace std;

// Renamed the function to avoid using reserved keywords
void unionArrays(int arr1[], int arr2[], int n, int m) {
    vector<int> temp;

    // Traverse the first array
    for (int i = 0; i < n; i++) {
        // Check if arr1[i] is not in temp
        if (find(temp.begin(), temp.end(), arr1[i]) == temp.end()) {
            temp.push_back(arr1[i]); // Add arr1[i] to temp
        }
    }

    // Traverse the second array
    for (int j = 0; j < m; j++) {
        // Check if arr2[j] is not in temp
        if (find(temp.begin(), temp.end(), arr2[j]) == temp.end()) {
            temp.push_back(arr2[j]); // Add arr2[j] to temp
        }
    }

    // Print the union array
    sort(temp.begin(),temp.end());
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl; // Print a newline at the end
}

int main() {
    int n, m;
    cin >> n >> m; // Input size of both arrays

    int arr1[n], arr2[m]; // Declare arrays
    for (int i = 0; i < n; i++) {
        cin >> arr1[i]; // Input elements of arr1
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i]; // Input elements of arr2
    }

    unionArrays(arr1, arr2, n, m); // Call the union function

    return 0; // Indicate successful execution
}
