#include <bits/stdc++.h>
using namespace std;

int sumofhappynumber(int n){
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum+=digit*digit;
        n/=10;
    }
    return sum;
}

bool ishappy(int n){
    unordered_set<int>st;
    while(n!=1 && st.find(n)==st.end()){
        st.insert(n);
        n=sumofhappynumber(n);

    }
    return n==1;
}


int main(){
    int n ;
    cin>>n;
    bool result=ishappy(n);
    cout<<result<<endl;
}