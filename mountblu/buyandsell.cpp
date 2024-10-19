#include <bits/stdc++.h>
using namespace std;

int buyandsell(int arr[],int n){
    int maxprofit=0;
    int buy =INT_MAX;
    for(int i =0;i<n;i++){
        buy=min(arr[i],buy);
        maxprofit=max(maxprofit,arr[i]-buy);
    }
    return maxprofit;
}

int main(){
  int n ;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int result=buyandsell(arr,n);
  cout<<result<<" ";
}