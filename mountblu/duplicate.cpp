#include <bits/stdc++.h>
using namespace std;


int duplicate(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}




int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
    cin>>arr[i];
}
     int result=duplicate(arr,n);
     cout<<result<<endl;
}