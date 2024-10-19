#include <iostream>
#include <vector>
using namespace std;

int minCandies(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;

    vector<int> candies(n, 1); // Step 1: Initialize candies array

    // Step 2: Left to right pass
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Right to left pass
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Step 4: Calculate total candies
    int totalCandies = 0;
    for (int candy : candies) {
        totalCandies += candy;
    }

    return totalCandies; // Return total minimum candies required
}

int main() {
    vector<int> ratings1 = {1, 0, 2};
    cout << minCandies(ratings1) << endl; // Output: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << minCandies(ratings2) << endl; // Output: 4

    return 0;
}
