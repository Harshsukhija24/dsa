#include <bits/stdc++.h>
using namespace std;

bool sumequal(int arr[],int n){
    unordered_set<int>set;
    int prefixsum=0;
    for(int i =0;i<n;i++){
        prefixsum+=arr[i];

        if(prefixsum==0 || set.find(prefixsum)!=set.end()){
            return true;
        }
        set.insert(prefixsum);
    }
    return false;
}


int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    bool result =sumequal(arr,n);
    cout<<result<<endl;
}