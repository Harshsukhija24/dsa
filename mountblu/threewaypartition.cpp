#include <bits/stdc++.h>
using namespace std;

int threewaypart(int arr[],int n ,int a,int b){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]<a){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]>b){
            swap(arr[mid],arr[high]);
            high--;

        }
        else{
        mid++;
        }
    }
    return 1;
}


int main(){
    int n ;
    cin>>n;
    int a;
    cin>>a;
    int b;
    cin>>b;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    threewaypart(arr,n,a,b);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}