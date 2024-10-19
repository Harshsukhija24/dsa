#include <bits/stdc++.h>
using namespace std;


pair<int,int>minmax(int arr[],int n){
     int max=INT_MIN;
     int min=INT_MAX;
     for(int i =0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            
        }
     }
     for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
     }
     pair<int,int>pp;
     pp.first=max;
     pp.second=min;
     return pp;
}


int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    pair<int,int> result=minmax(arr,n);
    cout<<result.first<<" "<<result.second<<endl;

}