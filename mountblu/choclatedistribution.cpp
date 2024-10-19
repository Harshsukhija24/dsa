#include <bits/stdc++.h>
using namespace std;

int chocolate(int arr[],int n ,int m ){
    if(m==0 ||n==0) return 0;
    sort(arr,arr+n);
    if(m>n) return -1;
    int diff=INT_MAX;
    for(int i =0;i+m-1<n;i++){
        int diffence=arr[i+m-1]-arr[i];
        diff=min(diff,diffence);

    }
    return diff;
}

int main(){
    int n ;
    cin>>n;
    int m ;
    cin>>m;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int result=chocolate(arr,n,m);
    cout<<result<<" ";
}