#include <bits/stdc++.h>
using namespace std;

int maxsub(int arr[],int n){
      int maxpro=arr[0];
      int minpro=arr[0];
      int result=arr[0];
      for(int i =0;i<n;i++){
        if(arr[i]<0){
            swap(maxpro,minpro);  
        }
        maxpro=max(arr[i],maxpro*arr[i]);
        minpro=min(arr[i],minpro*arr[i]);
        result=max(result,maxpro);
      }
      return result;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
     int result=maxsub(arr,n);
     cout<<result<<" ";


}