#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s ,string goal){
       if(s.size()!=goal.size()) return false;

       return(s+s).find(goal)!=string::npos; 
}



int main(){
int n ;
cin>>n;
string s;
cin>>s;
string goal;
cin>>goal;

bool result= rotateString(s,goal);
cout<<result<<endl;

}