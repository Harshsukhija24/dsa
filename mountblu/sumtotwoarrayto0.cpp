#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> uniquepair(int arr[], int n) {
    unordered_set<int> seen;          // To track the elements seen so far
    set<pair<int, int>> pairs;        // To store unique pairs in sorted order
    
    // Loop through the array
    for (int i = 0; i < n; i++) {
        int current = arr[i];
        if (seen.find(-current) != seen.end()) {
            // Insert a pair with ordered elements (min, max)
            pairs.insert({min(current, -current), max(current, -current)});
        }
        seen.insert(current); // Add current element to the seen set
    }

    // Convert set of pairs to a vector of vectors
    vector<vector<int>> result;
    for (auto& p : pairs) {
        result.push_back({p.first, p.second});
    }

    return result; // Return the result as a vector of pairs
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Read array input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the unique pairs that sum to zero
    vector<vector<int>> result = uniquepair(arr, n);

    // Print the result pairs
    for (auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    return 0;
}
