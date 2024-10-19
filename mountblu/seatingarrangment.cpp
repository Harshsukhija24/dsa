#include <bits/stdc++.h>
using namespace std;

int arrangment(vector<int> ans,int n){
   int count=0;
   for(int i =0;i<n;i++){
    if(ans[i]==0){
       bool canfill=true;
       if(i>0 && ans[i-1]==1){
        canfill=false;
       }
       if(i>1 && ans[i-2]==1){
        canfill=false;
       }
       if(canfill){
        ans[i]=1;
        count++;
       }
    }
   }
   return count;
}
int main(){
    int n ;
    cin>>n;
    vector<int>ans(n);
    for(int i =0;i<n;i++){
        cin>>ans[i];
    }

    int result=arrangment(ans,n);
    cout<<result<<endl;
    
}