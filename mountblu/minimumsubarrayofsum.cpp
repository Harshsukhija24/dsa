#include <bits/stdc++.h>
using namespace std;


int minsubarray(int arr[],int n,int target){
    int left=0;
    int sum=0;
    int minlen=INT_MAX;
    for(int right=0;right<n;right++){
        sum+=arr[right];
        while(sum>=target){
            minlen=min(minlen,right-left+1);
            sum-=arr[left];
            left++;
        }
    }
    return (minlen==INT_MAX)?0:minlen;
}

int main(){
    int n ;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
   for(int i =0;i<n;i++){
    cin>>arr[i];
   }
   int result=minsubarray(arr,n,target);
   cout<<result<<" ";
}