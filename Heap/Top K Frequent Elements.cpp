#include <bits/stdc++.h>
using namespace std;

// Function to find the k most frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }

    // Priority queue to store the top k frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (auto& [num, count] : countMap) {
        minHeap.push({count, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    reverse(result.begin(), result.end()); // The elements are in ascending order of frequency, so reverse to get the top k frequent elements

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
