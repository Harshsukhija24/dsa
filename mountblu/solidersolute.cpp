#include <bits/stdc++.h>
using namespace std;

int countsalute(string s){
    int left=0;
    int total=0;
    for (char ch:s){
        if(ch=='<'){
            left++;
        }
        else if(ch=='>'){
            total+=left;
        }

    }
    return total*2;
}
int main(){
    string s;
    cin>>s;
    int result =countsalute(s);
    cout<<result;

}