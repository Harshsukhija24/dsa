#include <bits/stdc++.h>
using namespace std;


int balance(string str){
    int count0=0;
    int count1=0;
    int balancecount=0;
    for(char ch :str){
        if(ch=='0'){
            count0++;
        }
        else if(ch=='1'){
            count1++;
        }

        if(count0==count1){
            balancecount++;
        }

    }
    if(count0!=count1){
            return -1;
        }

    return balancecount;
}

int main(){
    string str;
    cin>>str;
    int result=balance(str);
    cout<<result<<" ";
}