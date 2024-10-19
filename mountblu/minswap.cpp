#include <bits/stdc++.h>
using namespace std;


int minswap(int arr[],int n ,int k){
    int count_k=0;
    for(int i =0;i<n;i++){
        if(arr[i]<=k){
            count_k++;
        }
    }
    int badelement=0;
    for(int i =0;i<count_k;i++){
        if(arr[i]>k){
            badelement++;
        }

    }
    int min_swap=badelement;
    int i=0;
    int j=count_k;
    while(j<n){
        if(arr[i]>k){
            badelement--;
        }
        if(arr[j]>k){
            badelement++;
        }
      min_swap=min(min_swap,badelement);
      i++;
      j++;
    }
  return min_swap;


}


int main(){
    int n ;
    cin>>n;
    int k ;
    cin>>k;

    int  arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int result=minswap(arr,n,k);
    cout<<result<<" ";

}