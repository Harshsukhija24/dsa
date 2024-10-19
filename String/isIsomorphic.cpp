#include <bits/stdc++.h>
using namespace std;
 

 bool isomorphic(string s1,string s2){
      unordered_map<char,char>mpp1;
      unordered_map<char,char>mpp2;
      for(int i =0;i<s1.length();i++){
        if(mpp1[s1[i]]&& mpp1[s1[i]]!=s2[i]) return false;
        if(mpp2[s2[i]] && mpp2[s2[i]]!=s1[i]) return false;
        mpp1[s1[i]]=s2[i];
        mpp2[s2[i]=s2[i]];    
      }
      return True;
 }

int main(){
    int n ;
    cin>>n;
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    bool result=isomorphic(s1,s2);
    cout<<result<<endl;
}