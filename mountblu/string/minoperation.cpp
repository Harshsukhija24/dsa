#include <bits/stdc++.h>
using namespace std;

int minoperation(string str1,string str2){
    int n=str1.length();
    int m =str2.length();
    if(n==0) return m;
    if(m==0) return n;
    if(str1[n-1]==str2[m-1]){
        return minoperation(str1,str2,n-1,m-1);
    }
    return 1+min({
        minoperation(str1,str1)
    })
}
int main(){
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;

    int result=minoperation(str1,str2);
    cout<<result<<endl;
}