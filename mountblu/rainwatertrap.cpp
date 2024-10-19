#include <bits/stdc++.h>
using namespace std;

int rainwater(int arr[],int n){
    if(n==0 ) return 0;
    int left=0;
    int right=n-1;
    int leftmost=0;
    int rightmost=0;
    int trappedwater=0;

    while(left<=right){
        if(arr[left]<=arr[right]){
            if()
        }
    }
}



int main(){
    int n ;
    cin>>n
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int result=rainwater(arr,n);
    cout<<result<<endl;
}