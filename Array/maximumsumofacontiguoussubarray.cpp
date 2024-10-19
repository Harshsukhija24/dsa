#include <bits/stdc++.h>
using namespace std;

int maximum(int arr[],int n){
    int maxsum=INT_MIN;
    int currentsum=0;
    for(int i =0;i<n;i++){
        currentsum+=arr[i];
        if(maxsum<currentsum){
            maxsum=currentsum;
        }
        if(currentsum<0){
            currentsum=0;
        }

    }
    return maxsum;
}

int main (){
    int n;
    cin >>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
   int result= maximum(arr,n);
    cout<<result<<endl;
        
}



