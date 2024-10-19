#include <iostream>
#include <set>
#include <vector>
using namespace std;

double findMedianUsingSet(const vector<int>& arr1, const vector<int>& arr2) {
    set<int> mergedSet;

    // Insert all elements from both arrays into the set
    for (int num : arr1) {
        mergedSet.insert(num);
    }
    for (int num : arr2) {
        mergedSet.insert(num);
    }

    // Convert the set to a vector
    vector<int> mergedVector(mergedSet.begin(), mergedSet.end());
    int size = mergedVector.size();

    // Calculate the median
    if (size % 2 == 0) {
        return (mergedVector[size / 2 - 1] + mergedVector[size / 2]) / 2.0;
    } else {
        return mergedVector[size / 2];
    }
}

int main() {
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2, 2, 4};

    double median = findMedianUsingSet(arr1, arr2);
    cout << "The median is: " << median << endl;

    return 0;
}
