#include <bits/stdc++.h>
using namespace std;

int countdigit(int n ){
    int originalnumber=n;
    int count=0;
    while(n>0){
        int digit=n%10;
        n/=10;
        if(digit!=0 && originalnumber % digit==0){
            count++;
        }
    }
    return count;
}

int main(){
    int n ;
    cin>>n;
  int result=  countdigit(n);
    cout<<result<<endl;
    return 0;
}