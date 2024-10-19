#include <bits/stdc++.h>
using namespace std;


bool issubset(int arr1[],int arr2[],int n ,int m){
    unordered_map<int,int>mpp;
    for(int i =0;i<n;i++){
        mpp[arr1[i]]++;
    }

    for(int i =0;i<m;i++){
        if(mpp[arr2[i]]>0){
            mpp[arr2[i]]--;
        }
        else{
            return false;
        }
    }
    return true;
}




int main(){
    int n,m ;
    cin>>n>>m;
    int arr1[n];
    for(int i =0;i<n;i++){
        cin>>arr1[i];
    }

    int arr2[m];
    for(int i =0;i<m;i++){
        cin>>arr2[i];
    }
    bool result=issubset(arr1,arr2,n,m);
    cout<<result<<" ";

}