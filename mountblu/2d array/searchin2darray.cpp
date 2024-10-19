#include <bits/stdc++.h>
using namespace std;


bool searchmatrix(vector<vector<int>>& matrix ,int target){
    if(matrix.empty() || matrix[0].empty()) return false;

    int n=matrix.size();
    int m =matrix[0].size();
    int low=0;
    int high=m*n-1;


    while(low<=high){
        int mid=low+(high-low)/2;
        int row=mid/2;
        int col=mid%n;
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return false;


}


int main(){
    int rows;
    int cols;
    int target;
    cin>>rows;
    cin>>cols;


    vector<vector<int>>matrix(rows,vector<int>(cols));

    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    cin>>target;

    bool found=searchmatrix(matrix,target);
    cout<<found<<endl;
    
    return 0;
}