#include <bits/stdc++.h>
using namespace std;


int minreversal(string s){
    int n=s.length();
    if(n%2!=0){
        return -1;
    }
    int open =0;
    int close=0;
 for( char ch :s){
    if(ch=='{'){
        open++;
    }
    else{
        if(open>0){
            open--;
        }
        else{
            close++;
        }
    }
 } 
 return (open/2) + (close/2) +(open%2 +close%2);

}


int main(){
    string s;
    cin>>s;
    int result= minreversal(s);
    cout<<result<<" ";
}