#include <bits/stdc++.h>
using namespace std;


void print(int n){
  for(int i=1;i<=n;i++){
      char currentchar='A'+i-1;
          for(int j =1;j<=i;j++){
              cout<<currentchar;
          }
          cout<<endl;
      }
      
  }



int main(){
    int n ;
    cin>>n;
    print(n);
    return 0;
}