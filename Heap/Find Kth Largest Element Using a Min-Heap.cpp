#include <bits/stdc++.h>
using namespace std;

int findElement(vector<int>& nums, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        
        if (minHeap.size() > K) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) { 
        cin >> nums[i];
    }
    int K;
    cin >> K;

    int result = findElement(nums, K);
    cout << result << endl;

    return 0;
}
