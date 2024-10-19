#include <bits/stdc++.h>
using namespace std;

int largestsumofsubarray(int arr[],int n){
    int sum=0;
    int maxsum=INT_MIN;
    for(int i =0;i<n;i++){
        sum+=arr[i];
        maxsum=max(maxsum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;

}


int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int result=largestsumofsubarray(arr,n);
    cout<<result;

}