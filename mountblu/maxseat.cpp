#include <bits/stdc++.h>
using namespace std;

int maxSeats(int arr[], int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {  // Current seat is empty
            // Check if we can fill this seat (it has a gap of 2 seats)
            bool canFill = true;
            
            // Check previous two seats
            if (i > 0 && arr[i - 1] == 1) canFill = false;  // Previous seat
            if (i > 1 && arr[i - 2] == 1) canFill = false;  // Seat before previous
            
            // Check next two seats
            if (i < n - 1 && arr[i + 1] == 1) canFill = false;  // Next seat
            if (i < n - 2 && arr[i + 2] == 1) canFill = false;  // Seat after next

            // If all conditions are met, we can fill this seat
            if (canFill) {
                arr[i] = 1;  // Mark this seat as filled
                count++;     // Increment the count of filled seats
            }
        }
    }
    
    return count;
}

int main() {
    // Example 1:
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int result=maxSeats(arr,n);
    cout<<result<<endl;
    return 0;
}
