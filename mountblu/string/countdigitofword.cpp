#include <bits/stdc++.h>
using namespace std;


string rearrange(string str){
    string result;
    int count=0;
    for(char c :str){
        if(isdigit(c)){
            count=c-'0';
        }
        else{
            result.append(count,c);
            count=0;
        }
    }
    return result;
};

int main(){
    string str;
    getline(cin,str);
    string resulttt=rearrange(str);
    cout<<resulttt<<endl;
}