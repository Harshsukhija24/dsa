#include <bits/stdc++.h>
using namespace std;


bool isangram(string s1,string s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2) return true;

    return false;

}

int main(){
    int n ;
    cin>>n;
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;

    bool result=isangram(s1,s2);
    cout<<result<<endl;

}