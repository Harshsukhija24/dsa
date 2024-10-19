#include <bits/stdc++.h>
using namespace std;



bool threesum(int arr[],int n, int x){
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
            int currentsum=arr[i]+arr[left]+arr[right];
            if(currentsum==x){
                return true;

            }
            else if (currentsum<x){
                left++;
            }
            else{
                right--;
            }

        }
    }
    return false;
}



int main(){
    int n ;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool result=threesum(arr,n,x);
    cout<<result<<" ";

    return 0;
}